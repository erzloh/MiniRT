#include "ft_mlx.h"
#include "ft_raytracing.h"
#include <math.h>

// Checks if there are intersections with spheres and the casted prime ray.
// Fills the intersection struct with the closest sphere in front of the camera.
// Sets intersection.shape_type to NO_SHAPE if there is no intersection.
void	fill_intersection(t_ray ray, t_shapes *shape, t_intersection *inter)
{
	inter->shape_type = NO_SHAPE;
	inter->dist = -1;
	while (shape)
	{
		if (shape->type == SPHERE)
		{
			sp_intersection(ray, shape->shape.sphere, inter);
		}

		// plane
		if (shape->type == PLANE)
		{
			pl_intersection(ray, shape->shape.plane, inter);
		}

		// cylinder

		shape = shape->next;
	}
}

// Checks if there is an intersection between a ray and a sphere.
// Fills the intersection struct with the closest intersection point 
// if there is one.
void	sp_intersection(t_ray ray, t_sphere sp, t_intersection *intersection)
{
	t_eq	eq;

	eq.co = vec_sub(ray.pos, sp.pos);
	eq.b = 2.0 * ft_dot(eq.co, ray.dir);
	eq.c = ft_dot(eq.co, eq.co) - pow(sp.radius, 2);
	eq.discriminant = pow(eq.b, 2) - (4 * eq.c);
	if (eq.discriminant < 0)
		return ;
	eq.s1 = (-eq.b - sqrt(eq.discriminant)) / 2;
	eq.s2 = (-eq.b + sqrt(eq.discriminant)) / 2;
	if (eq.s1 > 0 && (eq.s2 < 0 || eq.s1 < eq.s2)
		&& (eq.s1 < intersection->dist || intersection->dist == -1))
	{
		intersection->shape.sphere = sp;
		intersection->shape_type = SPHERE;
		intersection->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s1));
		intersection->dist = eq.s1;
	}
	else if (eq.s2 > 0 && (eq.s1 < 0 || eq.s2 < eq.s1)
		&& (eq.s2 < intersection->dist || intersection->dist == -1))
	{
		intersection->shape_type = SPHERE;
		intersection->pos = vec_add(ray.pos, vec_mult(ray.dir, eq.s2));
		intersection->dist = eq.s2;
	}
}

// Checks if there is an intersection between a ray and a plane.
// Fills the intersection struct with the closest intersection point
// if there is one.
void	pl_intersection(t_ray ray, t_plane pl, t_intersection *intersection)
{
	float	t;
	float	ray_n_dot_product;

	ray_n_dot_product = ft_dot(ray.dir, pl.normal);
	if (ray_n_dot_product == 0)
		return ;
	t = ft_dot(vec_sub(pl.pos, ray.pos), pl.normal) / ray_n_dot_product;
	if (t > 0 && (t < intersection->dist || intersection->dist == -1))
	{
		intersection->shape.plane = pl;
		intersection->shape_type = PLANE;
		intersection->pos = vec_add(ray.pos, vec_mult(ray.dir, t));
		intersection->dist = t;
	}
}

// Checks if there is an intersection between a ray and a cylinder.
// Fills the intersection struct with the closest intersection point
// if there is one.
// void	cy_intersection(t_ray ray, t_cylinder cy, t_intersection *intersection)
// {

// }