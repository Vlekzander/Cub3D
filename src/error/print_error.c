/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:05:19 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 15:35:22 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "libft.h"

static char	*get_error_message_two(t_error err)
{
	if (err == ERR_MAP_DATA_FORMAT)
		return ("Invalid map data format");
	if (err == ERR_MAP_DATA_UNKNOWN)
		return ("Unknown map data");
	if (err == ERR_MAP_DATA_COLOR)
		return ("Color component out of range [0-255]");
	if (err == ERR_MAP_SPACE)
		return ("The map must be in a single block");
	if (err == ERR_MAP_INVALID_CHAR)
		return ("The map contains an invalid character");
	if (err == ERR_MAP_SPAWN)
		return ("The map must contain only one spawn point");
	if (err == ERR_MAP_NOT_CLOSED)
		return ("The map must be surrounded by walls");
	return ("Unknown error");
}

static char	*get_error_message(t_error err)
{
	if (err == ERR_NONE)
		return ("");
	if (err == ERR_IMPLEMENTATION)
		return ("Implementation error");
	if (err == ERR_ALLOCATION)
		return ("Allocation error");
	if (err == ERR_FILE_READ)
		return ("Failed to read file");
	if (err == ERR_FILE_FORMAT)
		return ("Invalid file format");
	if (err == ERR_TGA_OPEN)
		return ("Failed to open image");
	if (err == ERR_TGA_EXTENSION)
		return ("The image extension is not '.tga'");
	if (err == ERR_TGA_HEADER)
		return ("Failed to read image header");
	if (err == ERR_TGA_FORMAT)
		return ("TGA Format not supported");
	if (err == ERR_TGA_CONTENT)
		return ("Failed to read image content");
	if (err == ERR_MAP_EXTENSION)
		return ("The map extension is not '.cub'");
	if (err == ERR_MAP_OPEN)
		return ("Failed to open map");
	return (get_error_message_two(err));
}

void	print_error(t_error err)
{
	if (err == ERR_NONE)
		return ;
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putendl_fd(get_error_message(err), STDERR_FILENO);
}
