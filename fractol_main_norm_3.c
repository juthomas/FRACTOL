/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main_norm_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:50:02 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 21:53:12 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_location(int x, int y, t_var *var)
{
	if (var->fractol_type == 2)
	{
		var->cr = (((float)x * 6) / 1000 - 3) / var->zoom + var->modif_x;
		var->ci = (((float)y * 6) / 1000 - 3) / var->zoom + var->modif_y;
		julia_main(var);
		mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		print_params(var);
	}
	return (0);
}

void		mouse_hook_norm(int x, int y, t_var *var)
{
	if (x < 500 && y < 500)
	{
		var->modif_x -= ((500 - (float)x) / 166) / var->zoom;
		var->modif_y -= ((500 - (float)y) / 166) / var->zoom;
	}
	else if (x >= 500 && y < 500)
	{
		var->modif_x += (((float)x - 500) / 166) / var->zoom;
		var->modif_y -= ((500 - (float)y) / 166) / var->zoom;
	}
	else if (x >= 500 && y >= 500)
	{
		var->modif_x += (((float)x - 500) / 166) / var->zoom;
		var->modif_y += (((float)y - 500) / 166) / var->zoom;
	}
	else
	{
		var->modif_x -= ((500 - (float)x) / 166) / var->zoom;
		var->modif_y += (((float)y - 500) / 166) / var->zoom;
	}
}

int			mouse_hook(int keycode, int x, int y, t_var *var)
{
	if (keycode == 1 || keycode == 4 || keycode == 5)
		mouse_hook_norm(x, y, var);
	if (keycode == 4)
		var->zoom += var->zoom_intens;
	else if (keycode == 5 && var->zoom - var->zoom_intens > 1)
		var->zoom -= var->zoom_intens;
	better_call_fractol(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	print_params(var);
	var->modif_ite = var->ite_cst * (((float)var->zoom / 10) + 1);
	return (0);
}

char		fractol_parser_2(char *argv_1)
{
	char	ret;

	ret = 0;
	if (ft_strcmp(argv_1, "fractale_5") == 0
			|| ft_strcmp(argv_1, "Fractale_5") == 0)
		ret = 5;
	else if (ft_strcmp(argv_1, "fractale_6") == 0
			|| ft_strcmp(argv_1, "Fractale_6") == 0)
		ret = 6;
	else if (ft_strcmp(argv_1, "fractale_7") == 0
			|| ft_strcmp(argv_1, "Fractale_7") == 0)
		ret = 7;
	else if (ft_strcmp(argv_1, "fractale_8") == 0
			|| ft_strcmp(argv_1, "Fractale_8") == 0)
		ret = 8;
	else if (ft_strcmp(argv_1, "fractale_9") == 0
			|| ft_strcmp(argv_1, "Fractale_9") == 0)
		ret = 9;
	else if (ft_strcmp(argv_1, "fractale_10") == 0
			|| ft_strcmp(argv_1, "Fractale_10") == 0)
		ret = 10;
	return (ret);
}

char		fractol_parser_1(char *argv_1)
{
	char	ret;

	ret = 0;
	if (ft_strcmp(argv_1, "mandelbrot") == 0
			|| ft_strcmp(argv_1, "Mandelbrot") == 0
			|| ft_strcmp(argv_1, "fractale_1") == 0
			|| ft_strcmp(argv_1, "Fractale_1") == 0)
		ret = 1;
	else if (ft_strcmp(argv_1, "julia") == 0
			|| ft_strcmp(argv_1, "Julia") == 0
			|| ft_strcmp(argv_1, "fractale_2") == 0
			|| ft_strcmp(argv_1, "Fractale_2") == 0)
		ret = 2;
	else if (ft_strcmp(argv_1, "burning_ship") == 0
			|| ft_strcmp(argv_1, "Burning_ship") == 0
			|| ft_strcmp(argv_1, "fractale_3") == 0
			|| ft_strcmp(argv_1, "Fractale_3") == 0)
		ret = 3;
	else if (ft_strcmp(argv_1, "fractale_4") == 0
			|| ft_strcmp(argv_1, "Fractale_4") == 0)
		ret = 4;
	else
		ret = fractol_parser_2(argv_1);
	return (ret);
}
