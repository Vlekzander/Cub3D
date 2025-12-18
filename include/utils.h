/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apierret <apierret@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:29:28 by apierret          #+#    #+#             */
/*   Updated: 2025/12/18 11:13:34 by apierret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void		free_ddarray(void **array);
int			len_ddarray(void **array);
int			strend(const char *str, const char *end);
int			is_space(const char *str);
char		*read_file(int fd);
char		*strtrim_end(char *str, const char *set);
int			str_isdigit(const char *str);
float		rad(float deg);
long long	get_time(void);
int			str_space(char *str);

#endif
