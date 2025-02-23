#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



/* ---------- Colors ---------- */
# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define DARK_BLUE	0x00008B
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define GRAY		0x808080
# define LIGHT_GRAY	0xD3D3D3
# define DARK_GRAY	0x404040
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define BROWN		0xA52A2A


#define WIDTH 800
#define HEIGHT 800
#define KEY_ESC 65307

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
    t_img img;
}   t_fractol;

/* math functions */
double ft_scale(double num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_comlpex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

/* erreur functions */
void ft_error(t_fractol *fractal);
void    ft_print_error();

/* C utils*/
void ft_adjust_name(char *str);
int	ft_strcmp(char *s1, char *s2);

/* fractol utils*/
void ft_data_init(t_fractol *fractal);
void init_window(t_fractol *fractal);
int ft_check_input(int ac, char **av , t_fractol *fractal);
void ft_check_pixel(int x, int y,t_fractol *fractal);
void	my_pixel_put(int x, int y,t_img *img, int color);
void render_fractal(t_fractol *fractal);
void ft_events(t_fractol *fractal);










#endif
