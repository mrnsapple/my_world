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

void	print_trees(sfVector2i *value, sfVector2f **map2d, sfVector2f **water, luis *a)
{
	int	i;
	printf("yeahahahahaha\n\n\n");
	for (i = 0; value[i].x != -84 && value[i].y != -84; i++) {
		put_tree_in_place(map2d, water, value[i].y, value[i].x);
		draw_2d_map(a->window, map2d, water, a->color);
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

int	restart_map(luis *a)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace)) {
		free(a->one);
		free(a->two);
		free(a->tree);
		a->stat[0] = 0;
		a->stat[1] = 0;
		a->stat[2] = 0;
		a->one = space_for_building();
		a->two = space_for_building();
		a->tree = space_for_building();
	}
	return (0);
}
//need to put to send the color each time call draw_2d_map
sfVector2i	*put_tree_all_square(sfVector2f **map2d, sfVector2f **water, luis *a, sfVector2i *value, int num)
{
	int		x;
	int		y;
	//sfVector2i	*value = shape;
	sfVector2i		click;
	printf("hehe\n");
	click = sfMouse_getPosition(a->screen);
	printf("hoho\n");
	for (y = 0; y != MAP_Y; y++) {
                for (x = 0; x != MAP_X; x++) {
			if (click.x > water[y][x].x &&
			    click.x < water[y][x + 1].x &&
			    click.y > water[y][x].y &&
			    click.y < water[y + 1][x].y) {
				printf("hehe1, num%d\n", num);
				a->stat[num] = mouse_tree_press(a->stat[num], value, x, y);
				printf("hehe2\n");
				put_tree_in_place(map2d, water, y, x);
				printf("hehe3\n");
				draw_2d_map(a->window, map2d, water, a->color);
			}
		}
	}
	//if (restart_map(value, &num) != 0) {
	//print_trees(value, map2d, water, a);
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
	int			i;
	sfVector2i		click;
	
 	click = sfMouse_getPosition(a->screen);
	num = square_positions();
	for (i = 0; num[i].x != -84 && num[i].y != -84; i++) {
		if (i < 3)
			rectangle = draw_rect(num[i], i);
		else
			rectangle = draw_rect(num[i], 3);
		print_rect(a, rectangle);
		free(rectangle);
	}
	for (i = 0; num[i].x != -84 && num[i].y != -84; i++) {
		rectangle = draw_rect(num[i], i);
		if (mouse_touch_rect(rectangle, click) == 1) {
			if (i < 3) {
				color = wanted_color(i);
				return (color);
			}
			else
				a->i = i;
		}
		free(rectangle);
	}
	free(num);
	return (color);
}

sfColor	map_creation(int **water_map, int **map, luis *a)
{
	//sfVector2f		**map2d;
	//sfVector2f		**water;

	water_map = feed_water_map(water_map);
	a->water = create_2d_water_map(water_map);
	a->color = rectangle_stuff(a, a->color);
	change_building(map, a);
	//a->water = create_2d_water_map(a->water_map);
	//map2d = create_2d_map(map);
	//put_tree_all_square(map2d, a->water, a);
	draw_2d_water_map(a->window, a->water, a);
	//free_map2d(map2d);
	free_map2d(a->water);
	return (a->color);
}
