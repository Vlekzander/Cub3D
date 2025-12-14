/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_core.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:00:09 by apierret          #+#    #+#             */
/*   Updated: 2025/12/14 17:40:46 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_CORE_H
# define MLX_CORE_H
# define WIDTH 800
# define HEIGHT 600
# define KEY_ESC 65307
# define KEY_W 'w'
# define KEY_S 's'
# define KEY_A 'a'
# define KEY_D 'd'
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# include "error.h"
# include "image.h"
# include "game.h"

typedef struct s_mlx_core
{
	void	*mlx;
	void	*window;
	void	*img;
	t_image	*screen;
	t_game	*game;
}	t_mlx_core;

t_error		init_core(t_mlx_core **core, char *title);
void		free_core(t_mlx_core *core);
int			key_down_handler(int keycode, t_mlx_core *core);
int			key_up_handler(int keycode, t_mlx_core *core);
int			update(t_mlx_core *core);

#endif
