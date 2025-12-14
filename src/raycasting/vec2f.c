/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarlier <emarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:52:31 by emarlier          #+#    #+#             */
/*   Updated: 2025/12/14 22:47:08 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec.h"

t_vec2f	vec2f_add(t_vec2f a, t_vec2f b)
{
	return ((t_vec2f){a.x + b.x, a.y + b.y});
}

t_vec2f	vec2f_div(t_vec2f a, float b)
{
	return ((t_vec2f){a.x / b, a.y / b});
}

t_vec2f	vec2f_rot(t_vec2f a, float b)
{
	t_vec2f	out;

	out.x = a.x * cosf(b) - a.y * sinf(b);
	out.y = a.x * sinf(b) + a.y * cosf(b);
	return (out);
}
