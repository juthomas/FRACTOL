/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractale_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:28:15 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 21:50:33 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	appli_fonc_f4_10(t_var *var)
{
	float		cpy_sr;

	cpy_sr = var->sr;
	var->sr = var->sr * var->sr - (var->si * var->si) + var->cr;
	var->si = 2 * (var->si * cpy_sr) + var->ci;
}

static char	f4_10_is_alive_again(int ite, t_var *var, unsigned int color)
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
		appli_fonc_f4_10(var);
		f4_10_is_alive_again(ite - 1, var, color + 0xF);
	}
	return (1);
}

void		f4_10_main(t_var *var, float cr, float ci)
{
	int		x;
	int		y;

	var->cr = cr;
	var->ci = ci;
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
			f4_10_is_alive_again(var->ite_mov, var, 0x000000FF);
			x++;
		}
		x = 0;
		y++;
	}
	ft_scope(var);
}
