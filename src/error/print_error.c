/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:05:19 by apierret          #+#    #+#             */
/*   Updated: 2025/10/13 15:09:29 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "libft.h"

static char	*get_error_message(t_error err)
{
	if (err == ERR_NONE)
		return ("");
	if (err == ERR_IMPLEMENTATION)
		return ("Implementation error");
	if (err == ERR_ALLOCATION)
		return ("Allocation error");
	return ("Unknown error");
}

void	print_error(t_error err)
{
	if (err == ERR_NONE)
		return ;
	ft_putstr_fd("[ERROR] ", STDERR_FILENO);
	ft_putendl_fd(get_error_message(err), STDERR_FILENO);
}
