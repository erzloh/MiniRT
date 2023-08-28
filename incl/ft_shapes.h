/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shapes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:36:33 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/26 17:01:45 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHAPES_H
# define FT_SHAPES_Hßßß

# include "ft_mlx.h"
# include "ft_vector.h"

typedef struct s_sphere
{
	t_vec	origin;
	int		radius;
	int		color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec	origin;
	t_vec	dir;
	int			radius;
	int			height;
	int			color;
}	t_cylinder;

typedef struct s_plan
{
	t_vec	origin;
	t_vec	dir;
	int			color;
}	t_plan;

typedef enum e_shape_type
{
	SHPERE,
	CYLINDER,
	PLAN
}	t_shape_type;

typedef union s_shape
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plan		plan;
}	t_shape;

typedef struct s_shapes
{
	int				id;
	t_shape_type	shape_type;
	t_shape			shape;
	struct s_shapes	*next;
}	t_shapes;

t_sphere	create_sphere(t_vec origin, int radius, int color); // changer le premier parametre en un s_point (coordonnées) ?
t_cylinder	create_cylinder(t_vec origin, t_vec dir, int radius,
						int height, int color);
t_plan		create_plan(t_vec origin, t_vec dir, int color);

void		draw_filled_sphere(t_data *data, t_sphere sphere);

#endif