#include  "../MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#define WIDTH 256
#define HEIGHT 256

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}