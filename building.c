/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** by Pierrienco and Oriol
*/

#include "list.h"

void	change_building(int **map, luis *a)
{
	sfVector2f	**map2d;

	map2d = sfVector_malloca(MAP_Y, MAP_X);

	if (a->i == 3) {
		map = feed_map(map);
		map2d = create_2d_map(map, map2d);
		put_tree_all_square(map2d, a->water, a, a->one, 0);
	}
	else if (a->i == 4) {
		map = big_building_map(map);
		map2d = create_2d_map(map, map2d);
		put_tree_all_square(map2d, a->water, a, a->two, 1);
	}
	else if (a->i == 5) {
		map = small_building_map(map);
		map2d = create_2d_map(map, map2d);
		put_tree_all_square(map2d, a->water, a, a->tree, 2);
	}
	map = feed_map(map);
	map2d = create_2d_map(map, map2d);
	print_trees(a->one, map2d, a->water, a);
	map = big_building_map(map);
	map2d = create_2d_map(map, map2d);
	print_trees(a->two, map2d, a->water, a);
	map = small_building_map(map);
	map2d = create_2d_map(map, map2d);
	print_trees(a->tree, map2d, a->water, a);
	free_map2d(map2d);
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
