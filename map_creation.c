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

void	put_tree_all_square(sfVector2f **map2d, sfVector2f **water, luis *a, sfVector2i click)
{
	int	x;
	int	y;

	for (y = 0; y != MAP_Y; y++) {
                for (x = 0; x != MAP_X; x++) {
			if (click.x >= water[y][x].x &&
			    click.x <= water[y][x + 1].x &&
			    click.y >= water[y][x].y &&
			    click.y <= water[y + 1][x].y) {
				//printf("x:%d,y;%d, water[x]:%f,water[y]:%f\n", x, y, water[y][x].x, water[y][x].y);
				//printf("clickx:%d,y:%d\n",click.x, click.y);
				put_tree_in_place(map2d, water, y, x);
				draw_2d_map(a->window, map2d, water);
			}
		}
	}
}

int	map_creation(int **water_map, int **map, luis *a)
{
	sfVector2f      **map2d;
	sfVector2f      **water;
	sfVector2i      click;

	click = sfMouse_getPosition(a->screen);
	//printf("mouse - %d %d\n", click.x, click.y);
	water = create_2d_water_map(water_map);
	map2d = create_2d_map(map);
	put_tree_all_square(map2d, water, a, click);
	//draw_2d_map(a->window, map2d, water);
	draw_2d_water_map(a->window, water);
	//upgrade_the_position(click, map2d);                   
	free_map2d(map2d);
	free_map2d(water);
	return (0);
}
