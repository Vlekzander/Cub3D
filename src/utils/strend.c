/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:32:19 by apierret          #+#    #+#             */
/*   Updated: 2025/12/08 12:05:21 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	strend(const char *str, const char *end)
{
	size_t		str_len;
	size_t		end_len;

	if (str == NULL || end == NULL)
		return (0);
	str_len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (end_len > str_len)
		return (0);
	return (ft_strncmp(str + str_len - end_len, end, end_len +1) == 0);
}
