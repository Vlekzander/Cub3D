/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarlier <emarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:00:50 by emarlier          #+#    #+#             */
/*   Updated: 2025/12/07 16:07:49 by emarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

typedef struct s_vec2f
{
	float	x;
	float	y;
}	t_vec2f;

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

t_vec2f	vec2f_add(t_vec2f a, t_vec2f b);
t_vec2f	vec2f_div(t_vec2f a, float b);
t_vec2f	vec2f_rot(t_vec2f a, float b);

#endif
