#include "libft.h"
#include "ft_mlx.h"
#include "ft_vector.h"
#include "ft_shapes.h"
#include "ft_raytracing.h"
#include "ft_color.h"
#include <stdio.h>
#include "file_scene_parsing.h"
#include "display.h"

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_data	data;

	if (argc != 2)
		ft_fatal_error("Input Error, try: ./miniRT example_scene.rt", -1);
	init_scene(&scene);
	if (file_parsing(argv[1], &scene))
	{
		printf("Error when parsing the file\n");
		return (EXIT_FAILURE);
	}
	if (init_data(&data))
		ft_fatal_error("Error when initialising data", -1);
	init_camera(&scene.camera, data.win->aspect_ratio);
	// display_scene(scene);
	draw_scene(&data, scene);
	mlx_put_image_to_window(data.win->mlx_ptr, data.win->mlx_win,
		data.img.mlx_img, 0, 0);
	mlx_hook(data.win->mlx_win, 17, 0, &exit_program, &data);
	mlx_key_hook(data.win->mlx_win, &ft_key_event, &data);
	mlx_loop(data.win->mlx_ptr);
	return (EXIT_SUCCESS);
}
