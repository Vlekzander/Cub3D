/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:42:16 by apierret          #+#    #+#             */
/*   Updated: 2025/10/13 16:46:35 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	unsigned int	width;
	unsigned int	height;
	int				*pixels;
}	t_image;

t_image	*create_image(unsigned int width, unsigned int height);
void	free_image(t_image *image);

#endif
