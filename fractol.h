#ifndef FRACTOL_H
# define FRACTOL_H

#include "/usr/include/minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


# define KEY_ESC 65307
# define KEY_LEFT  65361
# define KEY_UP    65362
# define KEY_RIGHT 65363
# define KEY_DOWN  65364
# define KEY_PLUS  65451
# define KEY_MINUS  65453


# define BLACK		0x000000
# define BLUE		0x0000FF
# define WHITE		0xFFFFFF


#define WIDTH 600
#define HEIGHT 600

typedef struct s_complex
{
    double reel;
    double imaginary;
}   t_complex;


typedef struct s_img
{
    void    *img;
    char    *pixel_addr;
    int     bits_pp;
    int     line_length;
    int     endian;
}   t_img;

typedef struct s_fractol
{
    void *mlx;
    void *win;
    char *title;
    double escape_value;
    int iteration_num;
    double shift_reel;
    double shift_imaginary;
    double zoom;
    double julia_reel;
    double julia_imaginary;
    t_img img;
}   t_fractol;

/* math functions */
double ft_scale(double num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_comlpex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);
double ft_atod(char *str);

/* erreur functions */
void ft_error(t_fractol *fractal);
void    ft_print_error();

/* C utils*/
void ft_adjust_name(char *str);
int	ft_strcmp(char *s1, char *s2);

/* fractol utils*/
void    ft_data_init(t_fractol *fractal);
void    init_window(t_fractol *fractal);
int     ft_check_input(int ac, char **av , t_fractol *fractal);
void    ft_check_pixel(int x, int y,t_fractol *fractal);
void    ft_pixel_put(int x, int y,t_img *img, int color);
void    render_fractal(t_fractol *fractal);
void    ft_events(t_fractol *fractal);

#endif