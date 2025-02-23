#include "fractol.h"


void init_window(t_fractol *fractal)
{
    fractal->mlx = mlx_init();
    if (fractal->mlx == NULL)
        ft_error(fractal);
    fractal->win = mlx_new_window(fractal->mlx ,WIDTH ,HEIGHT ,fractal->title);
    if (fractal->win == NULL)
    {
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        ft_error(fractal);
    }
    fractal->img.img = mlx_new_image(fractal->mlx ,WIDTH ,HEIGHT);
    if (fractal->img.img == NULL)
    {
        mlx_destroy_image(fractal->mlx,fractal->img.img);
        mlx_destroy_window(fractal->mlx, fractal->win);
        mlx_destroy_display(fractal->mlx);
        ft_error(fractal);
    }
    fractal->img.pixel_addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bits_pp, &fractal->img.line_length, &fractal->img.endian);
    ft_data_init(fractal);
    ft_events(fractal);
}

int ft_check_input(int ac, char **av , t_fractol *fractal)
{
    ft_adjust_name(av[1]);
    if ((ac == 2 && ft_strcmp("mandelbrot",av[1]) == 0))
        fractal->title = av[1];
    else if ((ac == 4 && ft_strcmp("julia",av[1]) == 0))
        fractal->title = av[1];
    else
        ft_print_error();
    return (0);
}




void ft_check_pixel(int x, int y,t_fractol *fractal)
{
    t_complex z;
    t_complex c;
    int     i;
    int     color;

    i = 0;
    z.reel = 0;
    z.imaginary = 0;
    c.reel = ft_scale(x, -2, 2, 0, WIDTH);
    c.imaginary = ft_scale(y, 2, -2, 0, HEIGHT);
    while (i < fractal->iteration_num)
    {
        z = sum_comlpex(square_complex(z), c);
        if (( z.reel * z.reel + z.imaginary * z.imaginary ) > fractal->escape_value)
        {
            color  = ft_scale(i ,BLACK,GREEN, 0, fractal->iteration_num);
            my_pixel_put(x, y, &fractal->img, color);
            return ;
        }
        i++;
    }
    my_pixel_put(x, y, &fractal->img,WHITE);
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

int main(int ac, char **av)
{
    t_fractol fractal;

    if (ac == 1)
        ft_print_error();
    ft_check_input(ac, av, &fractal);

    init_window(&fractal);
    
    render_fractal(&fractal);
    
    mlx_loop(fractal.mlx);
}
