/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tga.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:20:40 by apierret          #+#    #+#             */
/*   Updated: 2025/10/21 10:15:32 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "color.h"
#include "error.h"
#include "image.h"
#include "libft.h"
#include "utils.h"

static t_error	read_header(t_tga_header *header, int fd)
{
	unsigned char	buffer[18];

	if (header == NULL || fd == -1)
		return (ERR_IMPLEMENTATION);
	if (read(fd, buffer, 18) != 18)
		return (ERR_FILE_READ);
	header->id_length = buffer[0];
	header->color_map_type = buffer[1];
	header->image_type = buffer[2];
	header->color_map_origin = buffer[3] | (buffer[4] << 8);
	header->color_map_length = buffer[5] | (buffer[6] << 8);
	header->color_map_depth = buffer[7];
	header->x_origin = buffer[8] | (buffer[9] << 8);
	header->y_origin = buffer[10] | (buffer[11] << 8);
	header->width = buffer[12] | (buffer[13] << 8);
	header->height = buffer[14] | (buffer[15] << 8);
	header->pixel_depth = buffer[16];
	header->image_descriptor = buffer[17];
	return (ERR_NONE);
}

static void	reverse_image(t_image *image, t_tga_header *header)
{
	int	i;
	int	j;
	int	one;
	int	two;
	int	color;

	if (image == NULL || (header->image_descriptor & 0x20) >> 5)
		return ;
	i = 0;
	while (i < image->height / 2)
	{
		j = 0;
		while (j < image->width)
		{
			one = i * image->width + j;
			two = (image->height - 1 - i) * image->width + j;
			color = image->pixels[one];
			image->pixels[one] = image->pixels[two];
			image->pixels[two] = color;
			j++;
		}
		i++;
	}
}

static t_error	parse_image(t_image *image, t_tga_header *header, int fd)
{
	int				bpp;
	char			*buf;
	int				len;
	int				i;
	unsigned char	alpha;

	if (image == NULL || header == NULL || fd == -1)
		return (ERR_IMPLEMENTATION);
	bpp = header->pixel_depth / 8;
	len = header->width * header->height * bpp;
	buf = ft_calloc(len, sizeof(char));
	if (buf == NULL)
		return (ERR_ALLOCATION);
	if (read(fd, buf, len) != len)
		return (free(buf), ERR_FILE_READ);
	i = 0;
	while (i < len)
	{
		alpha = 0xFF;
		if (bpp == 4)
			alpha = buf[i + 3];
		image->pixels[i / bpp] = rgba(buf[i + 2], buf[i + 1], buf[i], alpha);
		i += bpp;
	}
	return (free(buf), reverse_image(image, header), ERR_NONE);
}

t_error	parse_tga(t_image **image, const char *path)
{
	t_error			error;
	int				fd;
	t_tga_header	header;
	t_image			*img;

	if (image == NULL || path == NULL)
		return (ERR_IMPLEMENTATION);
	if (!strend(path, ".tga"))
		return (ERR_FILE_FORMAT);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ERR_FILE_OPEN);
	error = read_header(&header, fd);
	if (error != ERR_NONE)
		return (close(fd), error);
	if (header.image_type != 2)
		return (close(fd), ERR_FILE_FORMAT);
	img = create_image(header.width, header.height);
	if (img == NULL)
		return (close(fd), ERR_ALLOCATION);
	error = parse_image(img, &header, fd);
	if (error != ERR_NONE)
		return (close(fd), error);
	return (close(fd), *image = img, ERR_NONE);
}
