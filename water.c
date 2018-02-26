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
	return (map);
}

sfVector2f	**create_2d_water_map(int **water_map)
{
        sfVector2f      **map2d;
        int             x = 0;
        int             y = 0;
	static int	z_map = 0;
	
        map2d = sfVector_malloca(MAP_Y, MAP_X);
        for (y = 0; y != MAP_Y; y++) {
                for (x = 0; x != MAP_X; x++) {
                        map2d[y][x] =
                                project_iso_point(x *SCALE_X, y
						  * SCALE_Y,
						  water_map[y][x] * SCALE_Z + z_map);
			// printf("mapx:%f", map2d[y][x].x);
	                //printf("mapy:%f\n", map2d[y][x].y);
	        }
	}
	//z_map--;
	return (map2d);
}

sfVertexArray   *create_water_face(sfRenderWindow *window, struct coordin_t   a, sfVector2f **map_2d)
{
        //map_2d[a.x][a.y].x = map_2d[a.x][a.y].x + 30;                        
        sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex      vertex1 = {.position = map_2d[a.x][a.y], .color
                                 = sfColor_fromRGBA(0, 0 , 255 , 50)};
        sfVertex      vertex2 = {.position = map_2d[a.x][a.y + 1],
                                 .color = sfColor_fromRGBA(0, 0 , 255, 50)};
        sfVertex      vertex3 = {.position = map_2d[a.x + 1][a.y],
				 .color = sfColor_fromRGBA(0, 0 , 255, 50)};
        sfVertex      vertex4 = {.position = map_2d[a.x + 1][a.y + 1],
				 .color = sfColor_fromRGBA(0, 0 , 255, 50)};

        sfVertexArray_append(vertex_array, vertex1);
        sfVertexArray_append(vertex_array, vertex2);
        sfVertexArray_append(vertex_array, vertex4);
        sfVertexArray_append(vertex_array, vertex3);
        sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
        sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
        sfVertexArray_destroy(vertex_array);
        return (vertex_array);
}


int	draw_2d_water_map(sfRenderWindow *window, sfVector2f **map_2d)
{
	struct coordin_t        a = {.x = 0, .y = 0};

        for (a.y = 0; a.y + 1 != MAP_Y; a.y++) {
                for (a.x = 0; a.x + 1 != MAP_X; a.x++) {
			create_water_face(window, a, map_2d);
                }
        }
	return (0);

	
}
