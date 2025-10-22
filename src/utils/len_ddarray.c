/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_ddarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:00:00 by apierret          #+#    #+#             */
/*   Updated: 2025/10/17 22:00:34 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "utils.h"

int	len_ddarray(void **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
