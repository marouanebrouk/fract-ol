#include "fractol.h"


int ft_check_input(int ac, char **av , t_fractol *fractal)
{
    ft_adjust_name(av[1]);
    if ((ac == 2 && ft_strcmp("mandelbrot",av[1]) == 0))
        fractal->title = av[1];
    else if ((ac == 4 && ft_strcmp("julia",av[1]) == 0))
    {
        fractal->julia_reel = ft_atod(av[2]);
        fractal->julia_imaginary = ft_atod(av[3]);
        fractal->title = av[1];
    }
    else
        ft_print_error();
    return (0);
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
