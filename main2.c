#include <stdio.h>

typedef struct s_complex
{
    double real;
    double imaginary;
}   t_complex;

int main()
{
    t_complex z;
    t_complex c;
    z.real = 0;
    z.imaginary = 0;
    c.real = -1;
    c.imaginary = 0;
double tmp_real;
int index = 0;
    while(index < 15)
    {
        // z = z^2 + c
        // first calculate Z^2; (Z has real component and imaginary component); --> Z.real and Z.imaginary 
        
        tmp_real = (z.real * z.real) - (z.imaginary * z.imaginary);
        z.imaginary = (2 * z.real * z.imaginary);
        z.real = tmp_real;
        //add C ----> f(Z) = Z^2 + C
        z.real += c.real ;
        z.imaginary += c.imaginary ;
        printf("iteration n -> %d    real %f imaginary %f\n",index,z.real,z.imaginary);
        index++;
    }
}