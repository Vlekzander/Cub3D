/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:42:16 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 12:49:18 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	int	width;
	int	height;
	int	*pixels;
}	t_image;

t_image	*create_image(int width, int height);
void	free_image(t_image *image);
void	put_pixel(t_image *image, int x, int y, int color);
void	fill_image(t_image *image, int color);
void	draw_image(t_image *dst, t_image *src, int x, int y);

#endif
