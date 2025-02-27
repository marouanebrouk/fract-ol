#include "fractol.h"


void init_window(t_fractol *fractal)
{
    fractal->mlx = mlx_init();
    if (fractal->mlx == NULL)
        ft_error(fractal);
    fractal->win = mlx_new_window(fractal->mlx ,WIDTH ,HEIGHT ,fractal->title);
    if (fractal->win == NULL)
    {
        mlx_destroy_display(fractal->mlx);
        ft_error(fractal);
    }
    fractal->img.img = mlx_new_image(fractal->mlx ,WIDTH ,HEIGHT);
    if (fractal->img.img == NULL)
    {
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        ft_error(fractal);
    }
    fractal->img.pixel_addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_pp, &fractal->img.line_length, &fractal->img.endian);
    ft_data_init(fractal);
    ft_events(fractal);
}


static void check_fractal_set(t_complex *z, t_complex *c, t_fractol *fractal)
{
    if (ft_strcmp(fractal->title,"julia") == 0)
    {
        c->reel   = fractal->julia_reel;
        c->imaginary = fractal->julia_imaginary;
    }
    else
    {
        c->reel = z->reel;
        c->imaginary = z->imaginary;
    }
}


void ft_check_pixel(int x, int y, t_fractol *fractal)
{
    t_complex z;
    t_complex c;
    int     i;
    int     color;

    i = 0;
    // z.reel = 0;
    // z.imaginary = 0;
    // why i scaled z.reel z.imaginary instead of c.real c.imaginary
    // which what it was in the first half
    z.reel = ft_scale(x, -2, 2, 0, WIDTH) * fractal->zoom + fractal->shift_reel;
    z.imaginary =ft_scale(y, 2, -2, 0, HEIGHT)  * fractal->zoom + fractal->shift_imaginary;
    check_fractal_set(&z ,&c, fractal);
    while (i < fractal->iteration_num)
    {
        z = sum_comlpex(square_complex(z), c);
        if (( z.reel * z.reel + z.imaginary * z.imaginary ) > 4)
        {
            color  = ft_scale(i, BLACK, WHITE, 0, fractal->iteration_num);
            ft_pixel_put(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    ft_pixel_put(x, y, &fractal->img,BLACK);
}


void render_fractal(t_fractol *fractal)
{
    int x = 0;
    int y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            ft_check_pixel(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img,0,0);
}
