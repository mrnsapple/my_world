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
	for (i = 0; value[i].x != -84 && value[i].y != -84; i++) {
		put_tree_in_place(map2d, water, value[i].y, value[i].x);
		draw_2d_map(a->window, map2d, water);
	}		
}

sfVector2i	*put_tree_all_square(sfVector2f **map2d, sfVector2f **water, luis *a, sfVector2i click)
{
	int		x;
	int		y;
	static sfVector2i	*value = NULL;
	static int	num = 0;

	if (num == 0) {
		value = malloc(sizeof(struct coordin_t)* MAP_X * MAP_Y);
		value[0].x = -84;
		value[0].y = -84;
	}
	for (y = 0; y != MAP_Y; y++) {
                for (x = 0; x != MAP_X; x++) {
			if (click.x >= water[y][x].x &&
			    click.x <= water[y][x + 1].x &&
			    click.y >= water[y][x].y &&
			    click.y <= water[y + 1][x].y) {
				//printf("x:%d,y;%d, water[x]:%f,water[y]:%f\n", x, y, water[y][x].x, water[y][x].y);
				//printf("clickx:%d,y:%d\n",click.x, click.y);
				if (sfMouse_isButtonPressed(sfMouseLeft)) {
					value[num].x = x;
					value[num].y = y;
					num++;
					value[num].x = -84;
					value[num].y = -84;
				}
				put_tree_in_place(map2d, water, y, x);
				draw_2d_map(a->window, map2d, water);
			}
		}
	}
	print_trees(value, map2d, water, a);
	return (value);
}


int	map_creation(int **water_map, int **map, luis *a)
{
	sfVector2f      **map2d;
	sfVector2f      **water;
	sfVector2i      click;
	//sfVector2i	*value;
	
	click = sfMouse_getPosition(a->screen);
	//printf("mouse - %d %d\n", click.x, click.y);
	water = create_2d_water_map(water_map);
	map2d = create_2d_map(map);
	put_tree_all_square(map2d, water, a, click);
	//print_trees(value, map2d, water, a);
	//draw_2d_map(a->window, map2d, water);
	draw_2d_water_map(a->window, water);
	//upgrade_the_position(click, map2d);                   
	free_map2d(map2d);
	free_map2d(water);
	return (0);
}
