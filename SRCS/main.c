/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:32:41 by asamir-k          #+#    #+#             */
/*   Updated: 2018/11/22 19:04:18 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

int		main(int ac, char **av)
{
	t_env env;

	if (ac != 2)
	{
		ft_putstr("Bad arg you should try: dragon|disone|julia|mandelbrot|\n");
		ft_putstr("|chickenbrot|flower|ramhead|mandeland|batmandel|\n");
		exit(0);
	}
	env.wing = 0;
	env.display = 1;
	env.name = av[1];
	badarg(&av[1]);
	env.ci = 0.01;
	env.cr = 0.285;
	setup(&env);
	pixelwalk(&env);
	fractalbucket(&env);
	commandcenter(&env);
	mlx_destroy_image(env.mlx, env.img_str);
}
