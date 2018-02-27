/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** by Pierrienco and Oriol
*/

#include "list.h"

void	change_building(int **map, luis *a)
{
	if (a->i == 3)
		map = feed_map(map);
	if (a->i == 4)
		map = big_building_map(map);
	if (a->i == 5)
		map = small_building_map(map);
}

int     **big_building_map(int  **map)
{
	int     y;
        int     x;

        for (y = 0; y != MAP_Y; y++) {
		for (x = 0; x != MAP_X; x++) {
			//map[y][x] = 400;
			//if (y % 2 == 0)
			map[y][x] = 250;
			if (y == 0 || y == MAP_Y - 1 || x == 0 || x == MAP_X -1)
				map[y][x] = 0;
		}
	}
        return (map);
}

int     **small_building_map(int  **map)
{
	int     y;
        int     x;
	
        for (y = 0; y != MAP_Y; y++) {
		for (x = 0; x != MAP_X; x++) {
			map[y][x] = 50;
			if (y > MAP_Y / 10  && y < (MAP_Y / 10) * 3
			    && x > MAP_X/ 10 && x < (MAP_X / 10) * 3)
				map[y][x] = 400;
		}
	}
	return (map);
}
