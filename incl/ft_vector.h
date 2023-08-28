/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:02 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/28 12:39:23 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef struct s_vec
{
	float x;
	float y;
	float z;
}	t_vec;

t_vec	ft_create_vec(float x, float y, float z);
t_vec	ft_normalize(t_vec v);
float	ft_dot(t_vec v1, t_vec v2);

#endif