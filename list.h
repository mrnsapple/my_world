/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
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

#ifndef LIST_H_
#define LIST_H_

#define SCALING_X	20
#define SCALING_Y	20
#define SCALING_Z	2
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
}luis;

typedef struct coordin_t
{
        int     x;
        int     y;
}coordinates;

sfVector2f **sfVector_malloca(int num_ar, int cha);
sfVector2f      **create_2d_water_map(int **water_map);
sfVertexArray   *create_face(sfRenderWindow *window, struct coordin_t   a, sfVector2f **map_2d);

sfVertexArray   *create_water_face(sfRenderWindow *window, struct coordin_t   a, sfVector2f **map_2d);

int     draw_2d_water_map(sfRenderWindow *window, sfVector2f **map_2d);
int     **feed_water_map();
void    are_nb(char *str);
void    are_positive(int lines, int nb_match);
char	**get_the_match(int num, int *line, int lines, char **map);
int     before_the_match(int num);
void    free_map2d(sfVector2f **map_2d);
sfVector2f      project_iso_point(int x, int z, int y);

int	sticks(char *av, int i);
int     get_the_line(int count, int *line, int lines, char **map);
char    **game(int lines);
void    print_game(char **game);
char    **print_updated_board_game(int lines, int line, int nb_matches, char **game);
int	my_put_nbr(int nb);
int	out_of_range(int line, int lines, char **map);
void my_putchar_error(char c);
char    **ai(char **map, int lines, int num_match);
void    print_player_remove(int nb, int line);
int     **get_place(int lines, int **game, int **place, int i);
int     *more_than_1(int *first, int *second);
char *get_next_line(int fd);
char **getpath(char **env);
char **get_path_array(char *str, char leter);
coordinates *feed_p(void);
void    player_win(char **map);
void    ai_win(char **map);
int     matches_out_of_range(int num, char *map, int num_match);
int my_get_nbr(char *str);
void ls(char **str, char **env, int g);
int ls_loop(char **str, char **env, int g);
char **unsetenva(char **env, char **str, int g);
char *copy(char *pwd);
int my_putstr_error(char *str);
int num_arg(char *str, char let);
char *root(char *result);
void previous_dir(char *pwd);
int     get_rows(int lines, int rows, int i);
int     **big_2(int lines_with, int **game, int num_match, int lines);

char **malloca(int num_ar, int cha);
int **int_malloca(int num_ar, int cha);
char *delete_n(char *str);
char *add_n(char *str);

int size_array(char **env);
char **set_env(char **env, char **str, int g);
char **add_variable(char **env, char **str, int g);
char *add_n(char *str);
char *delete_n(char *str);
int my_strcmpe(char *pwd, char *line);
int funct(int *i);
void printprompt(int i);
char **no_space_array(char **ptr, coordinates *p, int *g, char *str);
char *get_pwd(char **env);
char *get_home(char **env);
int my_strcmp(char *str, char *line);
int geta_pwd(char **list, int g);
char *my_strstr(char *pwd,char *line);
char **get_array(char *str);
char *two_points(char *line);
char *get_home(char **env);
char *get_pwd(char **env);
char *get_cd(char **env, char **line, char *pwd, char *pwdmem);
int my_strlen(char *pwd);
void error(int ac);
char *feed_buffer(int fd, char *buffer);
char *save_after_n(char *buffer);
char *main_loop(int fd, int i, int count,char *str,char *buffer);
char *put_in_str(char *ptr, char *buffer, int i);
int is_line(char *str, int n);
int opening(char *av);

void my_putchar(char c);
int my_putstr(char *str);

#endif
