/*
** EPITECH PROJECT, 2018
** .h file
** File description:
** By ORIOL
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <curses.h>

#define SCALING_X	4
#define SCALING_Y	4
#define SCALING_Z	0.4
#define SCALE_Z		SCALING_Z * 2
#define SCALE_X		SCALING_X * 20
#define SCALE_Y		SCALING_Y * 20
#define PI		3.14159265358979323846
#define MAP_X		20
#define MAP_Y		20
#define BUFF		12

typedef struct framebuffer
{
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
}framebuffer_t;

typedef struct coordin_t
{
	int	 x;
	int	 y;
}coordinates;

typedef struct luis_t
{
 	sfVideoMode video_mode;
	sfRenderWindow *window;
	sfTexture*	texture;
	sfSprite*	sprite;
	sfEvent		event;
	int		alpha;
	int		alpha2;
	int		count;
	sfVector2i	center;
	sfWindow	*screen;
	sfColor		color;
	sfColor		rgb_water;
	int		i;
	sfVector2f		**water;
	sfVector2i	a;
	sfVector2i	*one;
	sfVector2i	*two;
	sfVector2i	*tree;
	sfColor		*color_one;
	sfColor		*color_two;
	sfColor		*color_tree;
	int		stat[3];
	int		num;
}luis;

sfVector2i	  *put_tree_all_square(sfVector2f **map2d,
					 sfVector2f **water, luis *a, sfVector2i *value, int num);
sfVector2i	*space_for_building(void);
void		print_trees(sfVector2i *value, sfVector2f **map2d, sfVector2f **water, luis *a);
sfRectangleShape		*draw_rect(sfVector2f b, int i);
void	print_rect(luis *a, sfRectangleShape *rectangle);
int	 mouse_touch_rect(sfRectangleShape *rectangle,
			 sfVector2i click);
sfVector2f	  *square_positions();
int	 restart_map(luis *a);
int	 **big_building_map(int  **map);
int	 **small_building_map(int  **map);
void	change_building(int **map, luis *a);
int	 **feed_map(int  **map);
void	feeds_water_map(int	**map);
sfVector2f	  **create_2d_map(int **map_3d, sfVector2f **map2d);
int draw_2d_map(sfRenderWindow *window, sfVector2f **map_2d, sfVector2f **water, sfColor color);
sfVector2f **sfVector_malloca(int num_ar, int cha);
sfVector2f	  **create_2d_water_map(int **water_map);
sfVertexArray   *create_face(sfRenderWindow *window, struct coordin_t   a,
				 sfVector2f **map_2d, sfVector2f **water, sfColor color);
sfColor	 map_creation(int **water_map, int **map, luis *a);
void	int_malloca_free(int **pwd);
sfVertexArray   *create_water_face(sfRenderWindow *window,
				   luis *a, sfVector2f **map_2d);
int	 draw_2d_water_map(sfRenderWindow *window, sfVector2f **map_2d, luis *b);
int	 **feed_map_tree(int	 **map);
void	feed_water_map(int **map);
void	feed_water_map_second(int **map);
void	feed_water_map_tree(int **map);
void	are_nb(char *str);
void	are_positive(int lines, int nb_match);
char	**get_the_match(int num, int *line, int lines, char **map);
int	 before_the_match(int num);
void	free_map2d(sfVector2f **map_2d);
sfVector2f	   project_iso_point(int x, int z, int y);
void	my_putchar_error(char c);
int	my_putstr_error(char *str);
char	**malloca(int num_ar, int cha);
int	**int_malloca(int num_ar, int cha);
void	my_putchar(char c);
int	my_putstr(char *str);
