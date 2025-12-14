/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:55:22 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 15:39:05 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "map.h"
#include "mlx.h"
#include "mlx_core.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_error		error;
	t_mlx_core	*core;

	if (argc != 2)
		return (ft_printf("usage: %s <map>\n", argv[0]), 1);
	error = init_core(&core, "Cub3D");
	if (error != ERR_NONE)
		return (print_error(error), 1);
	error = parse_map((t_map **) &core->game->map, argv[1]);
	if (error != ERR_NONE)
		return (print_error(error), 1);
	mlx_loop(core->mlx);
	free_core(core);
	return (0);
}
