/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main_norm_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:49:30 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 18:51:12 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_scope(t_var *var)
{
	int x;
	int y;

	y = 500;
	x = 480;
	while (x < 520)
	{
		var->tmp_x = x;
		var->tmp_y = y;
		image_add_px((unsigned int*)var->addr, 0x00FFFFFF, var);
		var->tmp_x = y;
		var->tmp_y = x;
		image_add_px((unsigned int*)var->addr, 0x00FFFFFF, var);
		x++;
	}
}

void		reset_params(t_var *var)
{
	var->zoom = 1;
	var->modif_x = 0;
	var->modif_y = 0;
	var->ite_cst = 20;
	var->modif_ite = var->ite_cst;
	var->zoom_intens = 0.2;
}

void		print_params(t_var *var)
{
	mlx_string_put(var->mlx, var->win, 10, 10, 0x888888, "zoom : x");
	mlx_string_put(var->mlx, var->win, 90, 10, 0x888888, ft_itoa(var->zoom));
	mlx_string_put(var->mlx, var->win, 120, 10, 0x888888, ",");
	mlx_string_put(var->mlx, var->win, 130, 10, 0x888888,
			ft_itoa((int)(var->zoom * 10) % 10));
	mlx_string_put(var->mlx, var->win, 10, 25, 0x888888,
			"generated iterations : ");
	mlx_string_put(var->mlx, var->win, 235, 25, 0x888888,
			ft_itoa(var->modif_ite));
	mlx_string_put(var->mlx, var->win, 10, 40, 0x888888, "zoom power : ");
	mlx_string_put(var->mlx, var->win, 135, 40, 0x888888,
			ft_itoa(var->zoom_intens));
	mlx_string_put(var->mlx, var->win, 145, 40, 0x888888, ",");
	mlx_string_put(var->mlx, var->win, 155, 40, 0x888888,
			ft_itoa((int)(var->zoom_intens * 10) % 10));
}

void		which_key_norm(int keycode, t_var *var)
{
	if (keycode == 3)
		tell_font_front_1(var);
	else if (keycode == 15)
		reset_params(var);
	else if (keycode == 53)
	{
		destroy_t_var(var);
		exit(-1);
	}
	else if (keycode == 126)
		var->modif_y -= 0.4 / var->zoom;
	else if (keycode == 125)
		var->modif_y += 0.4 / var->zoom;
	else if (keycode == 124)
		var->modif_x += 0.4 / var->zoom;
	else if (keycode == 123)
		var->modif_x -= 0.4 / var->zoom;
}

int			which_key(int keycode, t_var *var)
{
	if (keycode == 116)
		var->ite_cst += 1;
	else if (keycode == 121 && var->ite_cst > 0)
		var->ite_cst -= 1;
	else if (keycode == 69)
		var->zoom_intens += 0.1;
	else if (keycode == 78 && var->zoom_intens > 0.2)
		var->zoom_intens -= 0.1;
	else if (keycode == 8)
		tell_me_which_1(var);
	else
		which_key_norm(keycode, var);
	var->modif_ite = var->ite_cst * (((float)var->zoom / 10) + 1);
	better_call_fractol(var);
	print_params(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	print_params(var);
	return (0);
}
