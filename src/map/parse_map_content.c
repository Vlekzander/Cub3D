/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:26:04 by apierret          #+#    #+#             */
/*   Updated: 2025/12/18 11:24:21 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error.h"
#include "libft.h"
#include "map.h"
#include "utils.h"

static int	is_map_block(char *str)
{
	int	i;
	int	end;

	if (str == NULL)
		return (0);
	end = 0;
	i = 0;
	while (str[i] != '\0' && str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (end && str[i] != '\n')
			return (0);
		if (str[i] == '\n' && str[i +1] != '\0' && str[i +1] == '\n')
			end = 1;
		i++;
	}
	return (1);
}

static t_error	prepare_grid(t_cell_type **grid, int *width, int *height,
									char **array)
{
	int	len;
	int	c_len;
	int	i;

	if (array == NULL)
		return (ERR_IMPLEMENTATION);
	len = 0;
	i = 0;
	while (array[i] != NULL)
	{
		c_len = ft_strlen(array[i]);
		if (c_len > len)
			len = c_len;
		i++;
	}
	*grid = ft_calloc(len * i, sizeof(t_cell_type));
	if (*grid == NULL)
		return (ERR_ALLOCATION);
	*width = len;
	*height = i;
	return (ERR_NONE);
}

static t_error	fill_grid_line(t_map *map, int y, char *str)
{
	int	i;

	if (map == NULL || str == NULL)
		return (ERR_FILE_FORMAT);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(" 01NSEW", str[i]) == NULL)
			return (ERR_MAP_INVALID_CHAR);
		if (ft_strchr("NSEW", str[i]) != NULL && map->facing != 0)
			return (ERR_MAP_SPAWN);
		map->grid[y * map->width + i] = OUTSIDE;
		if (str[i] == '1')
			map->grid[y * map->width + i] = WALL;
		else if (str[i] == '0' || ft_strchr("NSEW", str[i]) != NULL)
			map->grid[y * map->width + i] = SPACE;
		if (ft_strchr("NSEW", str[i]) != NULL)
		{
			map->facing = str[i];
			map->spawn_x = i;
			map->spawn_y = y;
		}
		i++;
	}
	return (ERR_NONE);
}

static t_error	fill_grid(t_map *map, char **array)
{
	t_error	error;
	int		i;
	int		empty_flag;

	if (map == NULL || array == NULL)
		return (ERR_IMPLEMENTATION);
	empty_flag = 0;
	i = 0;
	while (i < map->height)
	{
		if (is_space(array[i]))
			empty_flag = 1;
		else if (empty_flag)
			return (ERR_MAP_SPACE);
		error = fill_grid_line(map, i, array[i]);
		if (error != ERR_NONE)
			return (error);
		i++;
	}
	return (ERR_NONE);
}

t_error	parse_map_content(t_map *map, int fd)
{
	t_error			error;
	char			*buffer;
	char			**strs;
	int				i;

	if (map == NULL || fd == -1)
		return (ERR_IMPLEMENTATION);
	buffer = read_file(fd);
	if (buffer == NULL)
		return (ERR_FILE_READ);
	if (!is_map_block(buffer))
		return (free(buffer), ERR_MAP_INVALID);
	strs = ft_split(buffer, '\n');
	if (strs == NULL)
		return (free(buffer), ERR_ALLOCATION);
	i = 0;
	while (str_space(strs[i]))
		i++;
	error = prepare_grid(&map->grid, &map->width, &map->height, strs + i);
	if (error != ERR_NONE)
		return (free(buffer), free_ddarray((void **) strs), error);
	error = fill_grid(map, strs + i);
	return (free(buffer), free_ddarray((void **) strs), error);
}
