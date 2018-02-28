/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** By Oriol
*/

#include "list.h"
//#include <curses.h>

int	**feed_water_map()
{
        int     y;
        int     x;
        int     **map;

        map = int_malloca(MAP_Y + 1, MAP_X + 1);
	for (y = 0; y != MAP_Y; y++) {
                for (x = 0; x != MAP_X; x++) {
			if (x % 2 == 0)
				map[y][x] = 50;
			else if (y % 2 == 0)
                                map[y][x] = 100;
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

sfVertexArray   *create_water_face(sfRenderWindow *window, luis *a, sfVector2f **map_2d)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex      vertex1 = {.position = map_2d[a->a.x][a->a.y], .color
                                 = a->rgb_water};
        sfVertex      vertex2 = {.position = map_2d[a->a.x][a->a.y + 1],
                                 .color = a->rgb_water};
        sfVertex      vertex3 = {.position = map_2d[a->a.x + 1][a->a.y],
				 .color = a->rgb_water};
        sfVertex      vertex4 = {.position = map_2d[a->a.x + 1][a->a.y + 1],
				 .color = sfWhite};

        sfVertexArray_append(vertex_array, vertex1);
        sfVertexArray_append(vertex_array, vertex2);
        sfVertexArray_append(vertex_array, vertex4);
        sfVertexArray_append(vertex_array, vertex3);
        sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
        sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
        sfVertexArray_destroy(vertex_array);
        return (vertex_array);
}


int	draw_2d_water_map(sfRenderWindow *window, sfVector2f **map_2d, luis *b)
{
	//b->i++;
	b->rgb_water = sfColor_fromRGBA(0, 0 , 0, 20);
	//b->rgb_water = sfWhite;
	for (b->a.y = 0; b->a.y + 1 != MAP_Y; b->a.y++) {
                for (b->a.x = 0; b->a.x + 1 != MAP_X; b->a.x++) {
			create_water_face(window, b, map_2d);
                }
        }
	return (0);

	
}
