/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:06:42 by apierret          #+#    #+#             */
/*   Updated: 2025/12/15 15:01:45 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#include "libft.h"
#include "map.h"
#include "utils.h"

t_error	parse_map(t_map **map, const char *path)
{
	t_error	error;
	int		fd;
	t_map	*cub;

	if (map == NULL || path == NULL)
		return (ERR_IMPLEMENTATION);
	if (!strend(path, ".cub"))
		return (ERR_MAP_EXTENSION);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ERR_MAP_OPEN);
	cub = ft_calloc(1, sizeof(t_map));
	if (cub == NULL)
		return (close(fd), free_map(cub), ERR_ALLOCATION);
	error = parse_map_data(cub, fd);
	if (error != ERR_NONE)
		return (close(fd), free_map(cub), error);
	error = parse_map_content(cub, fd);
	if (error != ERR_NONE)
		return (close(fd), free_map(cub), error);
	error = parse_map_check(cub);
	if (error != ERR_NONE)
		return (close(fd), free_map(cub), error);
	return (close(fd), *map = cub, ERR_NONE);
}
