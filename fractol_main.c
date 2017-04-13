/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:45:06 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 19:28:46 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void		better_call_fractol(t_var *var)
{
	if (var->fractol_type == 1)
		mandel_main(var);
	else if (var->fractol_type == 2)
		julia_main(var);
	else if (var->fractol_type == 3)
		ship_main(var);
	else if (var->fractol_type == 4)
		f4_10_main(var, 0.3, 0.5);
	else if (var->fractol_type == 5)
		f4_10_main(var, 0.285, 0.01);
	else if (var->fractol_type == 6)
		f4_10_main(var, -1.417022, 0.00995);
	else if (var->fractol_type == 7)
		f4_10_main(var, -0.038088, 0.9754633);
	else if (var->fractol_type == 8)
		f4_10_main(var, 0.285, 0.013);
	else if (var->fractol_type == 9)
		f4_10_main(var, -0.8, 0.2);
	else if (var->fractol_type == 10)
		f4_10_main(var, -1.0, 0.0);
}

int			error_msg(char type)
{
	if (type == 1)
		ft_putstr_fd("Unknow fractal\n", 2);
	ft_putstr_fd("Usage : ./fractol <name_of_fractal>\n", 2);
	ft_putstr_fd("available fractals : Julia, Mandelbrot, Burning_ship,", 2);
	ft_putstr_fd(" Fractale_4 to Fractale_10\n", 2);
	return (0);
}

void		main_init(t_var *var)
{
	var->color_mod = 0;
	var->front_font = 0;
	var->color1 = 0x00FFFF;
	var->color2 = 0x00FF00;
	var->color3 = 0x0000FF;
	var->font = 0x000000;
	var->front = 0xFFFFFF;
	var->zoom = 1;
	var->modif_x = 0;
	var->modif_y = 0;
	var->ite_cst = 20;
	var->modif_ite = var->ite_cst;
	var->zoom_intens = 0.2;
}

int			main(int argc, char **argv)
{
	t_var	*var;

	if (argc == 2)
	{
		if ((var = (t_var*)malloc(sizeof(*var))) == NULL)
			return (0);
		if ((var->fractol_type = fractol_parser_1(argv[1])) == 0)
		{
			destroy_t_var(var);
			return (error_msg(1));
		}
		main_init(var);
		new_window(var, argv[1]);
		better_call_fractol(var);
		mlx_hook(var->win, 2, 1, &which_key, var);
		mlx_hook(var->win, 6, 2, &mouse_location, var);
		mlx_mouse_hook(var->win, &mouse_hook, var);
		mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		print_params(var);
		mlx_loop(var->mlx);
		destroy_t_var(var);
	}
	else
		error_msg(2);
	return (0);
}
