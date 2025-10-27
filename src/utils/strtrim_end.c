/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:34:37 by apierret          #+#    #+#             */
/*   Updated: 2025/10/20 14:38:51 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	*strtrim_end(char *str, const char *set)
{
	int	i;
	int	end;

	if (str == NULL || set == NULL)
		return (NULL);
	end = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (end == -1 && ft_strchr(set, str[i]) != NULL)
			end = i;
		else if (ft_strchr(set, str[i]) == NULL)
			end = -1;
		i++;
	}
	if (end != -1)
		str[end] = '\0';
	return (str);
}
