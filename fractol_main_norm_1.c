/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main_norm_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:48:44 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 18:50:47 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float		ft_power(float a, int b)
{
	if (b > 1)
		return (ft_power(a * a, b - 1));
	else if (b == 1)
		return (a);
	else
		return (1);
}

char		is_on_the_circle(float a, float b)
{
	if (sqrt(a * a + b * b) <= 2)
		return (1);
	return (0);
}

void		image_add_px(unsigned int *addr, unsigned int img_color, t_var *var)
{
	if (var->tmp_x < X_IMG && var->tmp_y < Y_IMG
			&& var->tmp_x >= 0 && var->tmp_y >= 0)
		addr[(var->tmp_y * var->sizeline + var->tmp_x * var->bpp / 8) / 4] =
			img_color;
}

void		new_window(t_var *var, char *str)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, X_WIN, Y_WIN, str);
	var->img = mlx_new_image(var->mlx, X_IMG, Y_IMG);
	var->addr = mlx_get_data_addr(var->img, &var->bpp,
			&var->sizeline, &var->endian);
}

void		destroy_t_var(t_var *var)
{
	free(var->mlx);
	free(var->win);
	free(var->img);
	free(var->addr);
	free(var);
}
