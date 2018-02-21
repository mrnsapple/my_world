/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "list.h"
float rotation = 45;
float view_angle = 45;

int	**feed_map()
{
	int	y;
	int	x;
	int	**map;

	map = int_malloca(MAP_Y + 1, MAP_X + 1);
	for (y = 0; y != MAP_Y; y++) {
		for (x = 0; x != MAP_X; x++) {
			if (x % 2 == 0)
				map[y][x] = 0.4;
			else if (y % 2 == 0)
				map[y][x] = 1;
			else
				map[y][x] = 0;
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

	//printf("rot;%f\n\n\n\n\n\n", rotation);
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
			map2d[y][x] = project_iso_point(x *SCALING_X, y
							* SCALING_Y, map_3d[y][x] * SCALING_Z);
			//printf("mapx:%f\n", map2d[y][x].x);
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

sfVertexArray   *create_face(sfRenderWindow *window, int x, int y, sfVector2f **map_2d)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex      vertex1 = {.position = map_2d[x][y], .color
				 = sfColor_fromRGBA(0, 125 , 125 , 250)};
	sfVertex      vertex2 = {.position = map_2d[x][y + 1],
				 .color = sfColor_fromRGBA(0, 255 , 125 , 125)};
	sfVertex      vertex3 = {.position = map_2d[x + 1][y], .color = sfWhite};
	sfVertex      vertex4 = {.position = map_2d[x + 1][y + 1], .color = sfWhite};

	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex4);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
	sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
	sfVertexArray_destroy(vertex_array);
	return (vertex_array);
}
int draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d)
{
	int		x = 0;
	int		y = 0;

	for (y = 0; y + 1 != MAP_Y; y++) {
		for (x = 0; x + 1 != MAP_X; x++) {
			//printf("thex:%d,they:%d\n",x, y);
			//printf("y:%f\n,x:%f\n",map_2d[y][x].x, map_2d[y][x].y);
			//create_line(window, map_2d[y][x], map_2d[y][x + 1]);
			//create_line(window, map_2d[y][x], map_2d[y + 1][x]);
			create_face(window, x, y, map_2d);
		}
		//create_line(window, map_2d[y][x], map_2d[y + 1][x]);
	}
	for (x = 0; x + 1 != MAP_X; x++)
		create_line(window, map_2d[y][x], map_2d[y][x + 1]);
	//printf("out\n");
	return (0);
}

luis *feed2_a(luis *a, float num)
{
         //a->center.x = 800 / 2 + 800 / 2 * cos(num)*cos(num*2);
        //a->center.y = 1000;
	a->texture = sfTexture_create(800, 600);
        a->sprite = sfSprite_create();
        a->video_mode.width = 800;
        a->video_mode.height = 600;
        a->video_mode.bitsPerPixel = 8;
	a->window = sfRenderWindow_create(a->video_mode, "Window", sfResize | sfClose, NULL);
        return (a);
}

int	open_window(sfVector2f **map2d, int **map)
{
	luis	*a;
	
	a = malloc(sizeof(luis));
	a = feed2_a(a, 0);
	//map2d = create_2d_map(map);
	sfRenderWindow_setFramerateLimit(a->window, 80);
	while (sfRenderWindow_isOpen(a->window)) {
		while(sfRenderWindow_pollEvent(a->window, &a->event)){
			if(a->event.type == sfEvtClosed)
				sfRenderWindow_close(a->window);
		}
		sfRenderWindow_clear(a->window, sfBlack);
		map2d = create_2d_map(map);
		rotation++;
		draw_2d_map(a->window, map2d);
		//	sfSprite_setTexture(a->sprite, a->texture, sfTrue);
		free_map2d(map2d);
                //sfRenderWindow_drawSprite(a->window, a->sprite, NULL);
                sfRenderWindow_display(a->window);
	}
	//sfSprite_destroy(a->sprite);
        //sfTexture_destroy(a->texture);
        sfRenderWindow_destroy(a->window);
	
	return (0);
}

int	main(int ac, char **av)
{
	int		**map;
	sfVector2f	**map2d;
	
	map = feed_map();
	printf("hehe\n");
	map2d = create_2d_map(map);
	open_window(map2d, map);
	printf("hehe\n");
	return (0);
}
