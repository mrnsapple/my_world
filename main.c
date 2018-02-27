/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <curses.h>
#include "list.h"

float	rotation = 20;
float	view_angle = 332;
float	x_map = -81;
float	y_map = -446;
float	z_map = 0;
int	size = 100;
int	color[3];

int	**feed_map(int	**map)
{
	int	y;
	int	x;

	printf("x:%f, y%f, z%f\n",x_map, y_map, z_map);
	for (y = 0; y != MAP_Y; y++) {
		for (x = 0; x != MAP_X; x++) {
			if (x % 2 == 0)
				map[y][x] = 50;
			else if (y % 2 == 0)
				map[y][x] = size;
			else
				map[y][x] = 0;
			
		}
	}
	for (y = 0; y != MAP_Y; y++) {
		if (y > MAP_Y / 4  && y < (MAP_Y / 4) * 3) {
			for (x = 0; x != MAP_X; x++) {
				if (x > MAP_X/ 4 && x < (MAP_X / 4) * 3)
					map[y][x] = 200;
			}
		}
	}
	return (map);
}

sfVector2f	project_iso_point(int x, int z, int y)
{
	sfVector2f	point_2d;
	float		point[3];
	float	rot = (rotation / 180) * PI;
	float	view = ((view_angle / 180) * PI);
	float	a = MAP_X * SCALING_X / 2;
	float	b = MAP_Y * SCALING_Z / 2;

	point[0] = a + cos(rot) * (x - a) - (sin(rot) * (z - b));
	point[2] = b + sin(rot) * (x - a) + (cos(rot) * (z - b));
	point[1] = y * cos(view) - point[2] * sin(view);
	point_2d.x = point[0] + (800 / 2) - a;
	point_2d.y = point[1] + (600 / 2);

	/*point_2d.x = cos((0 / 180) * PI) * (float)x -
		cos((0 / 180) * PI) * (float)y;
	point_2d.y = sin((0.0 / 180) * PI);
	printf("point->y:%f, y:%d\n", point_2d.y, y);
	point_2d.y = point_2d.y * (float)y;
	printf("point->y:%f\n", point_2d.y); 
	point_2d.y = point_2d.y + (sin((0 / 180) * PI) * (float)x) - (float)z;
	printf("point->y:%f\n", point_2d.y); 
	if (point_2d.y < 0)
		point_2d.y = 0;
	if (point_2d.x < 0)
	point_2d.x = 0;*/
	return (point_2d);
}

sfVector2f	**create_2d_map(int **map_3d)
{
	sfVector2f	**map2d;
	int		x = 0;
	int		y = 0;

	map2d = sfVector_malloca(MAP_Y, MAP_X);
	for (y = 0; y != MAP_Y; y++) {
		for (x = 0; x != MAP_X; x++) {
			map2d[y][x] =
				project_iso_point(x * SCALING_X + x_map, y
							* SCALING_Y + y_map,
							map_3d[y][x] * SCALING_Z + z_map);
			//printf("mapxd:%f", map2d[y][x].x);
			//printf("mapy:%f\n", map2d[y][x].y);
		}
	}
	return (map2d);
}

sfVertexArray   *create_line(sfRenderWindow *window, sfVector2f point1, sfVector2f point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex      vertex1 = {.position = point1, .color = sfWhite};
	sfVertex      vertex2 = {.position = point2, .color = sfWhite};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
	sfVertexArray_destroy(vertex_array);
	return (vertex_array);
}

sfVertexArray   *create_face(sfRenderWindow *window, struct coordin_t	a,
			     sfVector2f **map_2d, sfVector2f **water, sfColor color)
{
	//map_2d[a.x][a.y].x = map_2d[a.x][a.y].x + water[0][0].x;
	//map_2d[a.x][a.y].y = map_2d[a.x][a.y].y + water[0][0].y;
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex      vertex1 = {.position = map_2d[a.x][a.y], .color
				 = color};
	sfVertex      vertex2 = {.position = map_2d[a.x][a.y + 1],
				 .color = color};
	sfVertex      vertex3 = {.position = map_2d[a.x + 1][a.y], .color = sfWhite};
	sfVertex      vertex4 = {.position = map_2d[a.x + 1][a.y + 1], .color = sfWhite};
	
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
	sfVertexArray_destroy(vertex_array);
	return (vertex_array);
}

int	draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d,
		    sfVector2f **water, sfColor color)
{
	struct coordin_t	a = {.x = 0, .y = 0};

	for (a.y = 0; a.y + 1 != MAP_Y; a.y++) {
		for (a.x = 0; a.x + 1 != MAP_X; a.x++) {
			//printf("thex:%d,they:%d\n",x, y);
			//printf("y:%f\n,x:%f\n",map_2d[y][x].x, map_2d[y][x].y);
			//create_line(window, map_2d[y][x], map_2d[y][x + 1]);
			//create_line(window, map_2d[y][x], map_2d[y + 1][x]);
			create_face(window, a, map_2d, water, color);
		}
	}
	for (a.x = 0; a.x + 1 != MAP_X; a.x++)
		create_line(window, map_2d[a.y][a.x], map_2d[a.y][a.x + 1]);
	return (0);
}

luis *feed2_a(luis *a, float num)
{
        //a->center.x = 800 / 2 + 800 / 2 * cos(num)*cos(num*2);
        //a->center.y = 1000;
	a->texture = sfTexture_create(800, 600);
        a->sprite = sfSprite_create();
	a->video_mode = sfVideoMode_getDesktopMode();
//        a->video_mode.width = 800;
	//      a->video_mode.height = 600;
	//      a->video_mode.bitsPerPixel = 8;
	a->window = sfRenderWindow_create(a->video_mode, "Window", sfFullscreen, NULL);
        return (a);
}

int	key_press()
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft))
		rotation--;
	if (sfKeyboard_isKeyPressed(sfKeyRight))
		rotation++;
	if (sfKeyboard_isKeyPressed(sfKeyUp))
		view_angle++;
	if (sfKeyboard_isKeyPressed(sfKeyDown))
		view_angle--;
	if (sfKeyboard_isKeyPressed(sfKeyA))
		y_map++;
	if (sfKeyboard_isKeyPressed(sfKeyD))
		y_map--;
	if (sfKeyboard_isKeyPressed(sfKeyW))
		x_map++;
	if (sfKeyboard_isKeyPressed(sfKeyS))
		x_map--;
	return (0);
}

int	mouse_button_press(int **map)
{
	//if (sfMouse_isButtonPressed(sfMouseLeft)) {
	if (sfKeyboard_isKeyPressed(sfKeyZ)) {
		size = size + 10;
		//free(map);
		map = feed_map(map);
	}
	if (sfKeyboard_isKeyPressed(sfKeyX)) {
		//if (sfMouse_isButtonPressed(sfMouseRight)) {
		size = size - 10;
		//free(map);
		map = feed_map(map);
	}
	return (0);
}

void	close_win(luis *a)
{
	while(sfRenderWindow_pollEvent(a->window, &a->event)){
		if(a->event.type == sfEvtClosed)
			sfRenderWindow_close(a->window);
		}
}
int	open_window(int **map, int **water_map)
{
	luis		*a;
		
	a = malloc(sizeof(luis));
	a = feed2_a(a, 0);
	sfRenderWindow_setFramerateLimit(a->window, 16);
	while (sfRenderWindow_isOpen(a->window)) {
		close_win(a);
		sfRenderWindow_clear(a->window, sfBlack);
		key_press();
		map_creation(water_map, map, a);
		mouse_button_press(map);
		sfRenderWindow_display(a->window);
	}
	sfRenderWindow_destroy(a->window);

	return (0);
}

int	main(int ac, char **av)
{
	int		**map;
	//sfVector2i	click;
	int		**water_map;

	map = int_malloca(MAP_Y + 1, MAP_X + 1);
	//water_map = feed_water_map();
	map = feed_map(map);
	water_map = feed_map(map);
	//map2d = create_2d_map(map);
	open_window(map, water_map);
	printf("hehe\n");
	return (0);
}
