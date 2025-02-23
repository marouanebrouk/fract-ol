#include "minilibx-linux/mlx.h"
#include <stdio.h>

# define WIDTH 800
# define HEIGHT 800

    // mlx_key_hook(img.win, key_hook, img.mlx); -----> to be in main.
int key_hook(int keycode, void *param)
{
    printf("Key pressed: %d\n", keycode);
    if (keycode == 65307)
        mlx_destroy_window((void *)param, (void *)param);
    return (0);
}


typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

int main()
{
    t_data img;

    int x = 100;
    int y = 100;
    img.mlx = mlx_init();
    img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "new window");
    img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
    x = 100;
    while (x < 400)
    {
        my_mlx_pixel_put(&img, y, x, 0xFF0000);
        x++;
    }
    while (x > 100)
    {
        my_mlx_pixel_put(&img,y,x , 0x0000FF);
        y++;
        x--;
    }

    while (y > 100)
    {
        my_mlx_pixel_put(&img,y,x , 0xFF0000);
        y--;
    }
    // second triangle
    x = 450;
    my_mlx_pixel_put(&img, y, x, 0xFF0000);
    while (x < 750)
    {
        my_mlx_pixel_put(&img, y, x, 0xFF0000);
        x++;
    }

    while (y < 400)
    {
        my_mlx_pixel_put(&img, y, x, 0xFF0000);
        y++;
    }

    while (x > 450)
    {
        my_mlx_pixel_put(&img, y, x, 0xFF0000);
        x--;
        y--;
    }
    my_mlx_pixel_put(&img,y,x , 0xFF0000);
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_loop(img.mlx);
    return (0);
}

