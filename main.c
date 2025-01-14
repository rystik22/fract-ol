/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:16:45 by rradin-m          #+#    #+#             */
/*   Updated: 2025/01/10 18:14:28 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"

void	init_values(t_data *img)
{
	img->width = 800 * 2;
	img->height = 400 * 2;
	img->base_color = 0x0F0000;
	img->flag = 0;
	img->zoom = 1;
	img->x_move = 0;
	img->y_move = 0;
	img->stop = 0;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->width, img->height, "fractol");
	img->img = mlx_new_image(img->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	init_fractol(t_data *img, int argc, char **argv)
{
	init_values(img);
	if (argc == 3)
	{
		if (!error_check(argv[1]) || !error_check(argv[2]))
			ft_error();
		img->cx = contof(argv[1]);
		img->cy = contof(argv[2]);
		if (img->cx < -2.0 || img->cx > 2.0 || img->cy < -2.0 || img->cy > 2.0)
			ft_error();
		img->flag = 0;
	}
	else if (argc == 2)
	{
		if (ft_strcmp(argv[1], "1") == 0)
			img->flag = 1;
		else if (ft_strcmp(argv[1], "2") == 0)
			img->flag = 2;
		else if (ft_strcmp(argv[1], "0") == 0)
			img->flag = 0;
		else
			ft_error();
	}
	else
		ft_error();
}

void	visualize(t_data *img)
{
	if (img->flag == 0)
		show_julia(img);
	else if (img->flag == 1)
		show_mandelbrot(img);
	else if (img->flag == 2)
		show_tricorn(img);
} 

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc > 1 && argc <= 3)
	{
		init_fractol(&img, argc, argv);
		visualize(&img);
		mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
		mlx_hook(img.mlx_win, 2, 5, keypad, &img);
		mlx_mouse_hook(img.mlx_win, mouse, &img);
		mlx_hook(img.mlx_win, 6, 1L < 6, mouse_julia, &img);
		mlx_hook(img.mlx_win, 17, 1L << 17, ft_close, 0);
		mlx_loop(img.mlx);
	}
	else
		ft_error();
	return (0);
} 
