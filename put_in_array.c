/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/
#include "list.h"

void	free_map2d(sfVector2f **map_2d)
{
	int	fd;

	for (fd = 0; fd < MAP_Y + 1; fd++)
		free(map_2d[fd]);
	free(map_2d);
}

char **malloca(int num_ar, int cha)
{
	char	**pwd;
	int	fd;

	pwd = malloc(sizeof(char *) * (num_ar + 2));
	for (fd = 0; fd < num_ar + 2; fd++)
		pwd[fd] = malloc(sizeof(char) * (cha + 5));
	return (pwd);
}

sfVector2f **sfVector_malloca(int num_ar, int cha)
{
	sfVector2f	**pwd;
	int		fd;

	pwd = malloc(sizeof(sfVector2f *) * (num_ar + 2));
	for (fd = 0; fd < num_ar + 2; fd++)
		pwd[fd] = malloc(sizeof(sfVector2f) * (cha + 5));
	return (pwd);
}

int **int_malloca(int num_ar, int cha)
{
	int	**pwd;
	int	fd;

	pwd = malloc(sizeof(int *) * (num_ar + 2));
	for (fd = 0; fd < num_ar + 2; fd++)
		pwd[fd] = malloc(sizeof(int) * (cha + 1));
	return (pwd);
}
