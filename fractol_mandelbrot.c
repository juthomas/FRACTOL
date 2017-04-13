/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:35:07 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 21:50:01 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	appli_fonc_mandel(t_var *var)
{
	float		cpy_sr;

	cpy_sr = var->sr;
	var->sr = var->sr * var->sr - (var->si * var->si) + var->cr;
	var->si = 2 * (var->si * cpy_sr) + var->ci;
}

static char	mandel_is_alive_again(int ite, t_var *var, unsigned int color)
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
		appli_fonc_mandel(var);
		mandel_is_alive_again(ite - 1, var, color + 0xF);
	}
	return (1);
}

void		mandel_main(t_var *var)
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
			var->cr = (((float)x * 6) / 1000 - 3) / var->zoom + var->modif_x;
			var->ci = (((float)y * 6) / 1000 - 3) / var->zoom + var->modif_y;
			var->tmp_x = x;
			var->tmp_y = y;
			var->sr = var->cr;
			var->si = var->ci;
			if (!is_on_the_circle(var->cr, var->ci))
				image_add_px((unsigned int*)var->addr, var->front, var);
			mandel_is_alive_again(var->ite_mov, var, 0x000000FF);
			x++;
		}
		x = 0;
		y++;
	}
	ft_scope(var);
}
