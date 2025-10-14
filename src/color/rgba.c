/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:52:14 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 12:52:37 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int	rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
