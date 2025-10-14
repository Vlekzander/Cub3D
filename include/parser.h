/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:08:49 by apierret          #+#    #+#             */
/*   Updated: 2025/10/14 15:21:13 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "error.h"
# include "image.h"

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

t_error	parse_tga(t_image **image, const char *path);

#endif
