/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:05:38 by rradin-m          #+#    #+#             */
/*   Updated: 2025/01/18 13:07:40 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	get_x0(t_data *img, int w)
{
	double	result;

	result = (w - img->width / 2) / (0.25 * img->zoom * img->width)
		+ img->x_move;
	return (result);
}

double	get_y0(t_data *img, int h)
{
	double	result;

	result = (h - img->height / 2) / (0.25 * img->zoom * img->height)
		+ img->y_move;
	return (result);
}

void	ft_error(void)
{
	write(1, "Invalid arguments\n", 19);
	write(1, "-----------------\n", 19);
	write(1, "For Mandelbrot set: Run -> ./fractol 1\n", 40);
	write(1, "For Julia set: Run -> ./fractol 0 or ./fractol -0.6 0.125 \n",
		60);
	write(1, "For Extra Fractol/ Tricorn set: Run -> ./fractol 2\n", 52);
	exit(1);
}

int	ft_close(void)
{
	exit(1);
	return (0);
}
