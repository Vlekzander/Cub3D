/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:55:22 by apierret          #+#    #+#             */
/*   Updated: 2025/10/13 16:07:43 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mlx.h"
#include "mlx_core.h"

int	main(void)
{
	t_error		error;
	t_mlx_core	*core;

	error = init_core(&core, "Cub3D");
	if (error != ERR_NONE)
		return (print_error(error), 1);
	mlx_loop(core->mlx);
	free_core(core);
	return (0);
}
