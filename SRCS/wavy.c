/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:17:38 by asamir-k          #+#    #+#             */
/*   Updated: 2018/11/15 11:25:41 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

void	wavy(t_env *env)
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		i;
	double		tmp;
	double		zoom_x;
	double		zoom_y;
	zoom_x = 800 / (XMAXBROT - XMINBROT);
	zoom_y = 800 / (YMAXBROT - YMINBROT);
	env->y = 0;
		while (env->y < YDIM)
		{
			env->x = 0;
			while (env->x < XDIM)
			{
			c_r = env->x / zoom_x + XMINBROT;
			c_i = env->y / zoom_y + YMINBROT;
			z_i = 0;
			z_r = 0;
			i = 0;
				while (z_r * z_r + z_i * z_i < 1 && i < env->maxiter)
				{
					tmp = z_r;
					z_r = z_r * z_r - z_i * z_i + c_r - 0.3;
					z_i = 2.89 * z_i * tmp + c_i - 0.75;
					i++;
				}
				if (env->ilikeit == 1)
				{
					env->img_str[XDIM * env->y + env->x] = i * 9999999999 / env->maxiter;
				}
				else
					env->img_str[XDIM * env->y + env->x] = i * 211 / env->maxiter;
			env->x++;
			}
		env->y++;
	}
}