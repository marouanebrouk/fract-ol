#include "fractol.h"

void ft_error(t_fractol *fractal)
{
    write(2,"mlx function failed\n",20);
    free(fractal->mlx);
    exit(1);
}


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
    fractal->img.pixel_addr = mlx_get_data_addr(&fractal->img.img, &fractal->img.bits_pp, &fractal->img.line_length, &fractal->img.endian);

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
}

void render_fractal(t_fractol *fractal)
{
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
