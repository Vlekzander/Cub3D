/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:00:18 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 15:35:31 by apierret         ###   ########.fr       */
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
	ERR_FILE_FORMAT
}	t_error;

void	print_error(t_error err);

#endif
