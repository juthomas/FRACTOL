/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:45:53 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 21:50:12 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	appli_fonc_julia(t_var *var)
{
	float		cpy_sr;

	cpy_sr = var->sr;
	var->sr = var->sr * var->sr - (var->si * var->si) + var->cr;
	var->si = 2 * (var->si * cpy_sr) + var->ci;
}

static char	julia_is_alive_again(int ite, t_var *var, unsigned int color)
{
	if (is_on_the_circle(var->sr, var->si))
	{
		if (ite == 0)
			image_add_px((unsigned int*)var->addr, var->font, var);
		else
			image_add_px((unsigned int*)var->addr, itera_color(ite, var), var);
	}
	else
		return (0);
	if (ite > 0)
	{
		appli_fonc_julia(var);
		julia_is_alive_again(ite - 1, var, color + 0xF);
	}
	return (1);
}

void		julia_main(t_var *var)
{
	int		x;
	int		y;

	var->ite_mov = var->modif_ite;
	x = 0;
	y = 0;
	while (y < Y_IMG)
	{
		while (x < X_IMG)
		{
			var->sr = (((float)x * 6) / 1000 - 3) / var->zoom + var->modif_x;
			var->si = (((float)y * 6) / 1000 - 3) / var->zoom + var->modif_y;
			var->tmp_x = x;
			var->tmp_y = y;
			if (!is_on_the_circle(var->sr, var->si))
				image_add_px((unsigned int*)var->addr, var->front, var);
			julia_is_alive_again(var->ite_mov, var, 0x000000FF);
			x++;
		}
		x = 0;
		y++;
	}
	ft_scope(var);
}
