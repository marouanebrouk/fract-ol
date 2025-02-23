#include "fractol.h"

static int ft_close_win(t_fractol *fractal)
{
    mlx_destroy_window(fractal->mlx,fractal->win);
    mlx_destroy_image(fractal->mlx,fractal->img.img);
    mlx_destroy_display(fractal->mlx);
    free(fractal->mlx);
    printf("window closed\n");
    exit(0);
}


static int ft_handle_key_events(int keycode, t_fractol *fractal)
{
    printf("the key pressed is %d\n",keycode);
    if (keycode == KEY_ESC)
        ft_close_win(fractal);
    if (keycode == 65361) //left
        fractal->shift_reel += 0.5;
    if (keycode == 65362) //up
    if (keycode == 65363) //right
        fractal->shift_reel -= 0.5;
    if (keycode == 65364) // down
    render_fractal(fractal);
    return (0);
}


// static int mouse_event(int keycode)
// {

// }

void ft_events(t_fractol *fractal)
{
    mlx_key_hook(fractal->win,ft_handle_key_events, fractal);
    mlx_hook(fractal->win, 17, 0, ft_close_win, fractal);
    // mlx_mouse_hook(fractal->win,mouse_event,fractal);
}