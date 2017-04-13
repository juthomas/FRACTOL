/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:20:14 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 15:21:03 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		tell_me_which_3(t_var *var)
{
	if (var->color_mod == 7)
	{
		var->color1 = 0x006600;
		var->color2 = 0x009900;
		var->color3 = 0x00CC00;
	}
	else if (var->color_mod == 8)
	{
		var->color1 = 0x000066;
		var->color2 = 0x000099;
		var->color3 = 0x0000CC;
	}
}

static void		tell_me_which_2(t_var *var)
{
	if (var->color_mod == 4)
	{
		var->color1 = 0xFFFF00;
		var->color2 = 0x00FF00;
		var->color3 = 0xFF0000;
	}
	else if (var->color_mod == 5)
	{
		var->color1 = 0xFF00FF;
		var->color2 = 0xFF0000;
		var->color3 = 0x0000FF;
	}
	else if (var->color_mod == 6)
	{
		var->color1 = 0x660000;
		var->color2 = 0x990000;
		var->color3 = 0xCC0000;
	}
	else
		tell_me_which_3(var);
}

void			tell_me_which_1(t_var *var)
{
	var->color_mod++;
	if (var->color_mod == 1)
	{
		var->color1 = 0xFF0000;
		var->color2 = 0x00FF00;
		var->color3 = 0x0000FF;
	}
	else if (var->color_mod == 2)
	{
		var->color1 = 0x333333;
		var->color2 = 0x666666;
		var->color3 = 0x999999;
	}
	else if (var->color_mod == 3)
	{
		var->color1 = 0x00FFFF;
		var->color2 = 0x00FF00;
		var->color3 = 0x0000FF;
	}
	else
		tell_me_which_2(var);
	if (var->color_mod >= 8)
		var->color_mod = 0;
}

static void		tell_font_front_2(t_var *var)
{
	if (var->front_font == 4)
	{
		var->font = 0x002200;
		var->front = 0x00FF00;
	}
	else if (var->front_font == 5)
	{
		var->font = 0x220000;
		var->front = 0xFF0000;
	}
}

void			tell_font_front_1(t_var *var)
{
	var->front_font++;
	if (var->front_font == 2)
	{
		var->font = 0x000000;
		var->front = 0xFFFFFF;
	}
	else if (var->front_font == 1)
	{
		var->font = 0xFFFFFF;
		var->front = 0x000000;
	}
	else if (var->front_font == 3)
	{
		var->font = 0x000022;
		var->front = 0x0000FF;
	}
	else
		tell_font_front_2(var);
	if (var->front_font >= 5)
		var->front_font = 0;
}
