/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "list.h"


void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	
	int	i = 0;

	while(str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}

int	is_num(char *str)
{
	int	i;
	int	g = 1;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != '-' && str[i] != '+' &&
		    (str[i] < '0' || str[i] > '9'))
			g = 0;
	}
	if (g == 1)
		return (1);
	my_putstr_error("Error: invalid input (positive number expected)\n");
	return (0);
}


int	my_get_nbr(char *str)
{
        double  x = 0;
        int     y = 0;
        int     z = 1;
	
	if (is_num(str) == 0)
		return(-84);
        while (str[y] == '-' || str[y] == '+' ||
	       str[y] < '0' || str[y] > '9') {
                if (str[y] == '-')
                        z *= -1;
                y++;
        }
        while (str[y] != '\0' && str[y] >= '0' && str[y] <= '9') {
                x = (x * 10);
                x = (str[y] - 48) + x;
                y++;
        }
        if (z == -1)
                x *= -1;
        if (x < -2147483648 || x > 2147483647)
                return (0);
        x = (int)x;
        return (x);
}
