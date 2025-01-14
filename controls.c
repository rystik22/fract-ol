/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:05:20 by rradin-m          #+#    #+#             */
/*   Updated: 2025/01/10 18:18:30 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"

int	mouse(int mouse_key_code, int x, int y, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (mouse_key_code == 5)
	{
		img->zoom *= 1.1;
		img->y_move += (y - img->height / 2) * 0.0005 / img->zoom;
		img->x_move += (x - img->width / 2) * 0.0005 / img->zoom;
	}
	if (mouse_key_code == 4)
	{
		img->y_move += (y - img->height / 2) * 0.0005 / img->zoom;
		img->x_move += (x - img->width / 2) * 0.0005 / img->zoom;
		img->zoom /= 1.1;
	}
	if (img->flag == 0)
		show_julia(img);
	else if (img->flag == 1)
		show_mandelbrot(img);
	else if (img->flag == 2)
		show_tricorn(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	mouse_julia(int x, int y, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (img->stop == 0)
		img->cy = (x - img->width / 2)
			/ (0.25 * img->zoom * img->width) + img->x_move;
	if (img->stop == 0)
		img->cx = (y - img->height / 2)
			/ (0.25 * img->zoom * img->height) + img->y_move;
	if (img->flag == 0)
		show_julia(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

void	arrow_move(t_data *img, int keycode)
{
	if (keycode == 2 || keycode == 124)
		img->x_move += -0.1 / img->zoom;
	if (keycode == 0 || keycode == 123)
		img->x_move += 0.1 / img->zoom;
	if (keycode == 13 || keycode == 126)
		img->y_move += 0.1 / img->zoom;
	if (keycode == 1 || keycode == 125)
		img->y_move += -0.1 / img->zoom;
}

void	color_change(t_data *img, int color)
{
	img->base_color = color;
}

int	keypad(int keycode, t_data *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit (0);
	}
	else if (keycode == 18)
		color_change(img, 0x4169E1FF);
	else if (keycode == 19)
		color_change(img, 0x32CD32FF);
	else if (keycode == 20)
		color_change(img, 0xDC143CFF);
	else if (keycode == 49)
		img->stop = 1;
	else if (keycode == 36)
		img->stop = 0;
	arrow_move(img, keycode);
	if (img->flag == 0)
		show_julia(img);
	else if (img->flag == 1)
		show_mandelbrot(img);
	else if (img->flag == 2)
		show_tricorn(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}
