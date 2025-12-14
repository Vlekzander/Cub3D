/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:03:05 by apierret          #+#    #+#             */
/*   Updated: 2025/12/08 12:05:44 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	str_isdigit(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
