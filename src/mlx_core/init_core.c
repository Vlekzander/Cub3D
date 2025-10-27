/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:12:38 by apierret          #+#    #+#             */
/*   Updated: 2025/10/13 18:53:20 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "image.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_core.h"

t_error	init_core(t_mlx_core **core, char *title)
{
	t_mlx_core	*mlx_core;

	if (title == NULL)
		return (ERR_IMPLEMENTATION);
	mlx_core = ft_calloc(1, sizeof(t_mlx_core));
	if (mlx_core == NULL)
		return (ERR_ALLOCATION);
	mlx_core->width = WIDTH;
	mlx_core->height = HEIGHT;
	mlx_core->mlx = mlx_init();
	if (mlx_core->mlx == NULL)
		return (free_core(mlx_core), ERR_ALLOCATION);
	mlx_core->window = mlx_new_window(mlx_core->mlx, WIDTH, HEIGHT, title);
	if (mlx_core->window == NULL)
		return (free_core(mlx_core), ERR_ALLOCATION);
	mlx_core->img = mlx_new_image(mlx_core->mlx, WIDTH, HEIGHT);
	if (mlx_core->img == NULL)
		return (free_core(mlx_core), ERR_ALLOCATION);
	mlx_core->screen = create_image(WIDTH, HEIGHT);
	if (mlx_core->screen == NULL)
		return (free_core(mlx_core), ERR_ALLOCATION);
	mlx_hook(mlx_core->window, 17, 0L, mlx_loop_end, mlx_core->mlx);
	mlx_key_hook(mlx_core->window, key_handler, mlx_core);
	mlx_loop_hook(mlx_core->mlx, update, mlx_core);
	return (*core = mlx_core, ERR_NONE);
}
