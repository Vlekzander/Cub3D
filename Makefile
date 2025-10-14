CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)/include -I$(MLX_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR= lib/libft
LIBFT_LIB= $(LIBFT_DIR)/libft.a
MLX_DIR= lib/mlx
MLX_LIB= $(MLX_DIR)/libmlx.a
SOURCES = src/main.c	\
		  src/color/get_color_channel.c src/color/rgb.c src/color/rgba.c	\
		  src/error/print_error.c	\
		  src/image/create_image.c src/image/fill_image.c src/image/free_image.c src/image/put_pixel.c	\
		  src/mlx_core/flush_screen.c src/mlx_core/free_core.c src/mlx_core/init_core.c src/mlx_core/key_handler.c src/mlx_core/update.c
OBJECTS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
NAME = cub3D


all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR) --no-print-directory
	make -C $(MLX_DIR) --no-print-directory
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

norm:
	norminette src include $(LIBFT_DIR) | grep Error || echo "No norms errors."

clean:
	make -C $(LIBFT_DIR) clean --no-print-directory
	make -C $(MLX_DIR) clean --no-print-directory
	rm -f $(OBJECTS) $(DEPS)

fclean: clean
	make -C $(LIBFT_DIR) fclean --no-print-directory
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all norm clean fclean re
