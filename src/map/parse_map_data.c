/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:26:09 by apierret          #+#    #+#             */
/*   Updated: 2025/12/08 12:59:39 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "color.h"
#include "error.h"
#include "libft.h"
#include "map.h"
#include "utils.h"

static void	prepare_line(char *str)
{
	int		i;
	int		j;
	int		flag;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	flag = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && !flag)
		{
			str[j++] = ' ';
			flag = 1;
		}
		else if (str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

static t_error	parse_color(int *color_ptr, char *line)
{
	char	**strs;
	int		r;
	int		g;
	int		b;

	if (color_ptr == NULL || line == NULL)
		return (ERR_IMPLEMENTATION);
	if (strend(line, ","))
		return (ERR_FILE_FORMAT);
	strs = ft_split(line, ',');
	if (strs == NULL)
		return (ERR_IMPLEMENTATION);
	if (len_ddarray((void **) strs) != 3 || !str_isdigit(strs[0])
		|| !str_isdigit(strs[1]) || !str_isdigit(strs[2]))
		return (free_ddarray((void **) strs), ERR_MAP_DATA_FORMAT);
	r = ft_atoi(strs[0]);
	g = ft_atoi(strs[1]);
	b = ft_atoi(strs[2]);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		return (free_ddarray((void **) strs), ERR_MAP_DATA_COLOR);
	*color_ptr = rgb(r, g, b);
	return (free_ddarray((void **) strs), ERR_NONE);
}

static t_error	parse_data(t_map *map, char *line)
{
	t_error	error;
	char	**strs;

	if (map == NULL || line == NULL)
		return (ERR_IMPLEMENTATION);
	strs = ft_split(line, ' ');
	if (strs == NULL)
		return (ERR_IMPLEMENTATION);
	if (len_ddarray((void **) strs) != 2)
		return (free_ddarray((void **) strs), ERR_MAP_DATA_FORMAT);
	if (ft_strncmp(strs[0], "C", 2) == 0 && map->color_ceil == 0)
		error = parse_color(&map->color_ceil, strs[1]);
	else if (ft_strncmp(strs[0], "F", 2) == 0 && map->color_floor == 0)
		error = parse_color(&map->color_floor, strs[1]);
	else if (ft_strncmp(strs[0], "NO", 3) == 0 && map->north == NULL)
		error = parse_tga(&map->north, strs[1]);
	else if (ft_strncmp(strs[0], "SO", 3) == 0 && map->south == NULL)
		error = parse_tga(&map->south, strs[1]);
	else if (ft_strncmp(strs[0], "EA", 3) == 0 && map->east == NULL)
		error = parse_tga(&map->east, strs[1]);
	else if (ft_strncmp(strs[0], "WE", 3) == 0 && map->west == NULL)
		error = parse_tga(&map->west, strs[1]);
	else
		error = ERR_MAP_DATA_UNKNOWN;
	return (free_ddarray((void **) strs), error);
}

t_error	parse_map_data(t_map *map, int fd)
{
	t_error	error;
	char	*line;
	char	*nl;

	if (map == NULL || fd == -1)
		return (ERR_IMPLEMENTATION);
	line = get_next_line(fd);
	while (line != NULL
		&& (map->color_ceil == 0 || map->color_floor == 0 || map->north == NULL
			|| map->south == NULL || map->east == NULL || map->west == NULL))
	{
		nl = ft_strrchr(line, '\n');
		if (nl != NULL)
			*nl = '\0';
		if (!is_space(line))
		{
			prepare_line(line);
			error = parse_data(map, line);
			if (error != ERR_NONE)
				return (free(line), get_next_line(-1), error);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), ERR_NONE);
}
