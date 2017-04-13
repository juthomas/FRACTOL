/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomass@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:10:25 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 18:44:26 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	fade_color_2(int c1, int c2, char f)
{
	int		ret;

	ret = (c1 * (10 - f) + c2 * (10 - f)) / 2;
	return (ret);
}

unsigned		fade_color_1(unsigned int c1, unsigned int c2, char f)
{
	int ret;

	ret = 0;
	ret = fade_color_2(c1 % 256, c2 % 256, f);
	ret += fade_color_2(c1 / 256 % 256, c2 / 256 % 256, f) * 256;
	ret += fade_color_2(c1 / 256 / 256 % 256, c2 / 256 / 256 % 256, f)
		* 256 * 256;
	return (ret);
}

unsigned int	itera_color(int ite, t_var *var)
{
	int		dat_color;

	dat_color = var->modif_ite - ite;
	if (dat_color % 6 == 0)
		return (var->color1);
	else if (dat_color % 6 == 1)
		return (fade_color_1(var->color1, var->color2, 5));
	else if (dat_color % 6 == 2)
		return (var->color2);
	else if (dat_color % 6 == 3)
		return (fade_color_1(var->color2, var->color3, 5));
	else if (dat_color % 6 == 4)
		return (var->color3);
	else if (dat_color % 6 == 5)
		return (fade_color_1(var->color3, var->color1, 5));
	return (0);
}
