#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils_fractol.c"


#define WIDTH 800
#define HEIGHT 600
# define KEY_ESC 65307

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
    t_img img;
}   t_fractol;

#include "calculation.c"
#include "event_handl.c"
#endif