
static int ft_close_win(t_fractol *fractal)
{
    mlx_destroy_window(fractal->mlx,fractal->win);
    mlx_destroy_image(fractal->mlx,fractal->img.img);
    mlx_destroy_display(fractal->mlx);
    free(fractal->mlx);
    printf("window closed\n");
    exit(0);
}


static int ft_handle_keyESC(int keycode, t_fractol *fractal)
{
    printf("the key pressed is %d\n",keycode);
    if (keycode == KEY_ESC)
        ft_close_win(fractal);
}


void ft_events(t_fractol *fractal)
{
    mlx_key_hook(fractal->win,ft_handle_keyESC, fractal);
    mlx_hook(fractal->win, 17, 0, ft_close_win, fractal);
}