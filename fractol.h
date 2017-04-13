/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:45:35 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/13 21:52:02 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# define X_WIN 1000
# define Y_WIN 1000
# define X_IMG 1000
# define Y_IMG 1000

typedef struct		s_var
{
	char			fractol_type;
	unsigned int	color1;
	unsigned int	color2;
	unsigned int	color3;
	unsigned int	font;
	unsigned int	front;
	char			front_font;
	char			color_mod;
	int				modif_ite;
	int				ite_cst;
	int				ite_mov;
	float			zoom;
	float			modif_x;
	float			modif_y;
	float			zoom_intens;
	float			cr;
	float			ci;
	float			sr;
	float			si;
	int				bpp;
	int				sizeline;
	int				endian;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				tmp_x;
	int				tmp_y;
}					t_var;

unsigned int		fade_color_2(int c1, int c2, char f);
unsigned int		fade_color_1(unsigned int c1, unsigned int c2, char f);
unsigned int		itera_color(int ite, t_var *var);
void				tell_me_which_1(t_var *var);
void				tell_font_front_1(t_var *var);
float				ft_power(float a, int b);
char				is_on_the_circle(float a, float b);
void				image_add_px(unsigned int *addr, unsigned int img_color,
		t_var *var);
void				new_window(t_var *var, char *str);
void				destroy_t_var(t_var *var);
void				ft_scope(t_var *var);
void				reset_params(t_var *var);
void				print_params(t_var *var);
void				which_key_norm(int keycode, t_var *var);
int					which_key(int keycode, t_var *var);
int					mouse_location(int x, int y, t_var *var);
void				mouse_hook_norm(int x, int y, t_var *var);
int					mouse_hook(int keycode, int x, int y, t_var *var);
char				fractol_parser_2(char *argv_1);
char				fractol_parser_1(char *argv_1);
void				main_init(t_var *var);
void				better_call_fractol(t_var *var);
void				ship_main(t_var *var);
void				image_add_px(unsigned int *addr, unsigned int img_color,
			t_var *var);
void				new_window(t_var *var, char *str);
void				destroy_t_var(t_var *var);
void				mandel_main(t_var *var);
char				is_on_the_circle(float a, float b);
void				ft_scope(t_var *var);
void				julia_main(t_var *var);
void				f4_10_main(t_var *var, float cr, float ci);
#endif
