/*
** EPITECH PROJECT, 2018
** feh
** File description:
** fdjfje
*/

#include "list.h"

void	my_putchar_error(char c)
{
	write(2, &c, 1);
}

int	my_putstr_error(char *str)
{
	int     i = 0;
	
	while(str[i] != '\0') {
		my_putchar_error(str[i]);
		i = i + 1;
	}
	return (0);
}
