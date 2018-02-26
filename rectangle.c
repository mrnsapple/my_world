/*
** EPITECH PROJECT, 2018
** jeje
** File description:
** By Pierillo
*/

#include "list.h"

sfRectangleShape	*draw_rect(sfVector2f b)
{
	sfRectangleShape	*rectangle;
	sfVector2f		a = {.x = 30,.y = 40};

	rectangle = malloc(sizeof(rectangle));
	rectangle = sfRectangleShape_create();
	sfRectangleShape_setPosition(rectangle, b);
	sfRectangleShape_setSize(rectangle,a);
	sfRectangleShape_setFillColor(rectangle, sfBlue);
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
	if (click.x < pos.x + size.x && click.x > pos.x && click.y < pos.y + size.y && click.y > pos.y)
		return (1);
	return (0);
}
