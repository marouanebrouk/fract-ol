#include "/usr/include/minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdio.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int main()
{
    t_data img;
    void *mlx_connection;
    void *mlx_window;
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 800, 800, "Test_screen");
    int y = 0;
    int x = 0;
    while (y < 800)
    {
        x = 0;
        while(x < 800)
        {
            mlx_pixel_put(mlx_connection, mlx_window, x, y, 0xFF0000);
            x++;
        }
        y++;
    }
    mlx_loop(mlx_connection);
}



