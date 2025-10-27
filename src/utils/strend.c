/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:32:19 by apierret          #+#    #+#             */
/*   Updated: 2025/10/16 10:36:42 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	strend(const char *str, const char *end)
{
	const char	*s;

	if (str == NULL || end == NULL)
		return (0);
	s = ft_strrchr(str, '.');
	if (s == NULL)
		return (0);
	return (ft_strncmp(s, end, ft_strlen(end) +1) == 0);
}
