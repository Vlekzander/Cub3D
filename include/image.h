/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:42:16 by apierret          #+#    #+#             */
/*   Updated: 2025/10/21 10:12:26 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include "error.h"

typedef struct s_image
{
	int	width;
	int	height;
	int	*pixels;
}	t_image;

typedef struct s_tga_header
{
	short unsigned int	color_map_origin;
	short unsigned int	color_map_length;
	short unsigned int	x_origin;
	short unsigned int	y_origin;
	short unsigned int	width;
	short unsigned int	height;
	unsigned char		id_length;
	unsigned char		color_map_type;	
	unsigned char		image_type;
	unsigned char		color_map_depth;
	unsigned char		pixel_depth;
	unsigned char		image_descriptor;
}	t_tga_header;

t_image	*create_image(int width, int height);
void	free_image(t_image *image);
void	put_pixel(t_image *image, int x, int y, int color);
void	fill_image(t_image *image, int color);
void	draw_image(t_image *dst, t_image *src, int x, int y);
t_error	parse_tga(t_image **image, const char *path);

#endif
