/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:37:04 by apierret          #+#    #+#             */
/*   Updated: 2025/10/20 11:44:24 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"

char	*read_file(int fd)
{
	char	*buffer;
	char	*temp;
	char	*line;

	if (fd == -1)
		return (NULL);
	buffer = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(buffer, line);
		if (temp == NULL && buffer == NULL)
			temp = ft_strjoin("", line);
		else if (temp == NULL)
			return (free(buffer), free(line), get_next_line(-1), NULL);
		free(buffer);
		buffer = temp;
		free(line);
		line = get_next_line(fd);
	}
	return (buffer);
}
