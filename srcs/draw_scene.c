#include "ft_mlx.h"
#include "ft_raytracing.h"

void	draw_scene(t_data *data, t_scene scene)
{
	t_point2D		pixel;
	t_ray			prime_ray;
	t_intersection	intersection;
	t_color			color;
	t_color			color_ambient_light_with_intensity;

	prime_ray.pos = scene.camera.pos;
	pixel.y = -1;
	color_ambient_light_with_intensity = change_intesity(scene.ambient_light.color, scene.ambient_light.intensity);
	while (++pixel.y < data->win->win_h)
	{
		pixel.x = -1;
		while (++pixel.x < data->win->win_w)
		{
			// Fill the prime ray with its approriate components
			fill_prime_ray(&prime_ray, *data->win, scene.camera, pixel);

			// Check if the prime ray intersects any objects
			fill_intersection(prime_ray, scene.shapes, &intersection);
			
			// Compute the color of the pixel
			if (intersection.shape_type != NO_SHAPE)
			{
				if (intersection.shape_type == SPHERE)
				{
					color = intersection.shape.sphere.color;
				}
				else if (intersection.shape_type == CYLINDER)
				{
					color = intersection.shape.cylinder.color;
				}
				else if (intersection.shape_type == PLANE)
				{
					color = intersection.shape.plane.color;
				}
				// printf("color1 = %i, g = %i, b = %i\n", color.r, color.g, color.b);
				if (check_intersection(intersection.pos, scene.spot_light.pos, scene.shapes))
				{
					color = shadow();
				}
				// else
				color = phong(scene, &intersection);
				if (check_intersection(scene.spot_light.pos, intersection.pos, scene.shapes))
				{
					color = change_intesity(color, 0.3);
				}
				// printf("color2 = %i, g = %i, b = %i\n", color.r, color.g, color.b);
				ft_img_pix_put(data, pixel.x, pixel.y, color_to_int(color));
			}
			else
			{
				// Set the pixel to the background color
				// printf("A = %i, g = %i, b = %i\n", scene.ambient_light.color.r, scene.ambient_light.color.g, scene.ambient_light.color.b);
				ft_img_pix_put(data, pixel.x, pixel.y, color_to_int(color_ambient_light_with_intensity));
			}
		}
	}
}
