/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:04:45 by rradin-m          #+#    #+#             */
/*   Updated: 2025/01/10 16:43:55 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"

static	void	algorithm(t_data *img, int w, int h)
{
	double	zx;
	double	zy; 

	zx = compute_x0(img, w);
	zy = compute_y0(img, h);
	img->xtemp = 0.0;
	img->iteration = 0;
	img->max_iteration = 300;
	while (zx * zx + zy + zy < 4 && img->iteration < img->max_iteration)
	{
		img->xtemp = zx * zx - zy * zy;
		zy = 2.0 * zx * zy + img->cy;
		zx = img->xtemp + img->cx;
		img->iteration += 1;
	}
	if (img->iteration == img->max_iteration)
		my_mlx_pixel_put(img, w, h, img->base_color);
	else
		my_mlx_pixel_put(img, w, h, img->base_color * img->iteration);
	w++;
}

void	show_julia(t_data *img)
{
	int	h;
	int	w;

	h = 0;
	while (h < img->height)
	{
		w = 0;
		while (w < img->width)
		{
			algorithm(img, w, h);
			w++;
		}
		h++;
	}
}
