/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:26:04 by apierret          #+#    #+#             */
/*   Updated: 2025/10/21 10:22:42 by apierret         ###   ########.fr       */
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

static t_error	prepare_grid(unsigned char **grid, int *width, int *height,
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
		strtrim_end(array[i], " ");
		if (ft_strlen(array[i]) == 0)
			return (ERR_FILE_FORMAT);
		c_len = ft_strlen(array[i]);
		if (c_len > len)
			len = c_len;
		i++;
	}
	*grid = ft_calloc(len * i, sizeof(unsigned char));
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
		if (ft_strchr(" 01NSEW", str[i]) == NULL
			|| (ft_strchr("NSEW", str[i]) != NULL && map->facing != 0))
			return (ERR_FILE_FORMAT);
		if (str[i] == '1')
			map->grid[y * map->width + i] = 1;
		else if (ft_strchr("NSEW", str[i]) != NULL)
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
			return (ERR_FILE_FORMAT);
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

	if (map == NULL || fd == -1)
		return (ERR_IMPLEMENTATION);
	buffer = read_file(fd);
	if (buffer == NULL)
		return (ERR_FILE_FORMAT);
	if (!is_map_block(buffer))
		return (free(buffer), ERR_FILE_FORMAT);
	strs = ft_split(buffer, '\n');
	if (strs == NULL)
		return (free(buffer), ERR_ALLOCATION);
	error = prepare_grid(&map->grid, &map->width, &map->height, strs);
	if (error != ERR_NONE)
		return (free(buffer), free_ddarray((void **) strs), error);
	error = fill_grid(map, strs);
	return (free(buffer), free_ddarray((void **) strs), error);
}
