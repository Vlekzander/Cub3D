/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:18 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 18:54:13 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
	ERR_NONE,
	ERR_IMPLEMENTATION,
	ERR_ALLOCATION,
	ERR_FILE_OPEN,
	ERR_FILE_READ,
	ERR_FILE_EXTENSION,
	ERR_FILE_FORMAT,
	ERR_TGA_FORMAT,
	ERR_TGA_HEADER,
	ERR_TGA_CONTENT,
	ERR_MAP_DATA_FORMAT,
	ERR_MAP_DATA_UNKNOWN,
	ERR_MAP_DATA_COLOR,
	ERR_MAP_SPACE,
	ERR_MAP_INVALID_CHAR,
	ERR_MAP_SPAWN,
	ERR_MAP_NOT_CLOSED
}	t_error;

void	print_error(t_error err);

#endif
