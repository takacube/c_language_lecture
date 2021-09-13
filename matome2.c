#include <stdio.h>
int main()
{
    int i, intarval_num=1000;
    double x, sum_y, dx, sum, trapezoid_size, to=1.0, start_from=0.0;
    double culc_func(double);
    dx = (to - start_from)/intarval_num;
    sum = 0.0;
    for(i=0; i < intarval_num; i++)
    {
        x = start_from + i*dx;
        sum_y = (culc_func(x) + culc_func(x + dx));
        trapezoid_size = sum_y*dx*0.5;
        sum += trapezoid_size;
    }
    printf("The integral = %15.7e\n", sum);
}
double culc_func(double x)
{
    double y;
    y = (4*x)/(2*x*x+5*x+2);
    return y;
}