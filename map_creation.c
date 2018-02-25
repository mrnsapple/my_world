/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** By Piere and Oriol
*/

#include "list.h"

int	map_creation(int **water_map, int **map, luis *a)
{
	sfVector2f      **map2d;
	sfVector2f      **water;
	water = create_2d_water_map(water_map);
	
	map2d = create_2d_map(map);
	draw_2d_map(a->window, map2d);
	draw_2d_water_map(a->window, water);
	//upgrade_the_position(click, map2d);                   
	free_map2d(map2d);
	free_map2d(water);
	return (0);
}
