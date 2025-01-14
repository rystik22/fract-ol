/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:04:54 by rradin-m          #+#    #+#             */
/*   Updated: 2025/01/08 22:30:54 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"

static	void	algorithm(t_data *img, int w, int h)
{
	double	x;
	double	y;

	x = 0.0;
	y = 0.0;
	img->xtemp = 0.0;
	img->iteration = 0;
	img->max_iteration = 300;
	img->offset = 0.05;
	while (x * x + y * y <= 1 * 2 && img->iteration < img->max_iteration)
	{
		img->xtemp = x * x - y * y + compute_x0(img, w);
		y = 2.0 * x * y + compute_y0(img, h);
		x = img->xtemp;
		img->iteration += 1;
	}
	if (img->iteration == img->max_iteration)
		my_mlx_pixel_put(img, w, h, img->base_color);
	else
		my_mlx_pixel_put(img, w, h, img->base_color * img->iteration);
	w++;
}

void	show_mandelbrot(t_data *img)
{
	int	h;
	int	w;

	h = 5;
	while (h < img->height)
	{
		w = 5;
		compute_y0(img, h);
		while (w < img->width)
		{
			algorithm(img, w, h);
			w++;
		}
		h++;
	}
}
