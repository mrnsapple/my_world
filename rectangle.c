/*
** EPITECH PROJECT, 2018
** jeje
** File description:
** By Pierillo
*/

#include "list.h"

sfRectangleShape	*draw_rect(sfVector2f b, int i)
{
	sfRectangleShape	*rectangle;
	sfVector2f		a = {.x = 30,.y = 40};
	sfColor			one[3] = {sfBlue, sfGreen, sfRed};	
	rectangle = malloc(sizeof(rectangle));
	if (rectangle == NULL)
		exit (84);
	rectangle = sfRectangleShape_create();
	sfRectangleShape_setPosition(rectangle, b);
	sfRectangleShape_setSize(rectangle,a);
	sfRectangleShape_setFillColor(rectangle, one[i]);
	return (rectangle);
}

void	print_rect(luis *a, sfRectangleShape *rectangle)
{
	sfRenderWindow_drawRectangleShape(a->window, rectangle, NULL);
}

int	mouse_touch_rect(sfRectangleShape *rectangle,
			  sfVector2i click)
{
	sfVector2f	pos;
	sfVector2f	size;

	pos = sfRectangleShape_getPosition(rectangle);
	size = sfRectangleShape_getSize(rectangle);
	if (click.x < pos.x + size.x && click.x > pos.x
	    && click.y < pos.y + size.y && click.y > pos.y)
		return (1);
	return (0);
}

sfVector2f	*square_positions()
{
	sfVector2f	*num;

	num = malloc(sizeof(sfVector2i) * 4);
	if (num == NULL)
		exit(84);
	num[0].x = 50;
	num[0].y = 50;
	num[1].x = 300;
	num[1].y = 50;
	num[2].x = 600;
	num[2].y = 50;
	num[3].x = -84;
	num[3].y = -84;
	return (num);
}