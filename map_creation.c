/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** By Piere and Oriol
*/

#include "list.h"

void	put_tree_in_place(sfVector2f **map2d, sfVector2f **water, int x, int y)
{
	float	a = - water[x][y].x + map2d[x][y].x;
	float	b = - water[x][y].y + map2d[x][y].y;

	for (y = 0; y != MAP_Y; y++) {
                for (x = 0; x != MAP_X; x++) {
			map2d[x][y].x = map2d[x][y].x - a;
			map2d[x][y].y = map2d[x][y].y - b;
		}
	}
}

void	print_trees(sfVector2i *value, sfVector2f **map2d, sfVector2f **water, luis *a, sfColor color)
{
	int	i;
	for (i = 0; value[i].x != -84 && value[i].y != -84; i++) {
		put_tree_in_place(map2d, water, value[i].y, value[i].x);
		draw_2d_map(a->window, map2d, water, color);
	}		
}

int	mouse_tree_press(int num, sfVector2i *value, int x, int y)
{
	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		value[num].x = x;
		value[num].y = y;
		num++;
		value[num].x = -84;
		value[num].y = -84;
	}
	return (num);
}
//need to put to send the color each time call draw_2d_map
sfVector2i	*put_tree_all_square(sfVector2f **map2d, sfVector2f **water, luis *a, sfColor color)
{
	int		x;
	int		y;
	static sfVector2i	*value = NULL;
	static int	num = 0;
	sfVector2i		click;

	click = sfMouse_getPosition(a->screen);
	if (num == 0) {
		value = malloc(sizeof(struct coordin_t)* MAP_X * MAP_Y);
		value[0].x = -84;
		value[0].y = -84;
	}
	for (y = 0; y != MAP_Y; y++) {
                for (x = 0; x != MAP_X; x++) {
			if (click.x > water[y][x].x &&
			    click.x < water[y][x + 1].x &&
			    click.y > water[y][x].y &&
			    click.y < water[y + 1][x].y) {
				num = mouse_tree_press(num, value, x, y); 
				put_tree_in_place(map2d, water, y, x);
				draw_2d_map(a->window, map2d, water, color);
			}
		}
	}
	print_trees(value, map2d, water, a, color);
	return (value);
}

sfColor	wanted_color(int i)
{
	sfColor	color;

	if (i == 0)
		color = sfColor_fromRGBA(0, 0, 255, 255);
	if (i == 1)
		color = sfColor_fromRGBA(0, 255, 125, 255);
	if (i == 2)
		color = sfColor_fromRGBA(255, 0, 0, 255);
	return (color);
}

sfColor	rectangle_stuff(luis *a, sfColor color)
{
	sfRectangleShape        *rectangle;
	sfVector2f		*num;
	int	i;
	sfVector2i		click;
	
 	click = sfMouse_getPosition(a->screen);
	num = square_positions();
	for (i = 0; num[i].x != -84 && num[i].y != -84; i++) {
		rectangle = draw_rect(num[i], i);
		print_rect(a, rectangle);
		free(rectangle);
	}
	for (i = 0; num[i].x != -84 && num[i].y != -84; i++) {
		rectangle = draw_rect(num[i], i);
		if (mouse_touch_rect(rectangle, click) == 1) {
			color = wanted_color(i);
			return (color);
		}
		free(rectangle);
	}
	free(num);
	return (color);
}

sfColor	map_creation(int **water_map, int **map, luis *a)
{
	sfVector2f		**map2d;
	sfVector2f		**water;
	static sfColor			color;

	color = rectangle_stuff(a, color);
 	//click = sfMouse_getPosition(a->screen);
	//printf("mouse - %d %d\n", click.x, click.y);
	water = create_2d_water_map(water_map);
	map2d = create_2d_map(map);
	put_tree_all_square(map2d, water, a, color);
	draw_2d_water_map(a->window, water);
	free_map2d(map2d);
	free_map2d(water);
	return (color);
}