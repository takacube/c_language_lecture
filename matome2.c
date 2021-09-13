#include <stdio.h>
int main()
{
    double trapezoid_rule_func(), trap_answer;
    trap_answer = trapezoid_rule_func();
    printf("The integral = %15.7e\n", trap_answer);

    double simpsons_rule_func(), simp_answer;
    simp_answer = simpsons_rule_func();
    printf("The integral = %15.7e\n", simp_answer);
}

double trapezoid_rule_func()
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
    return sum;
}

double simpsons_rule_func()
{
    int i, intarval_num=1000;
    double x, y, dx, sum=0.0, to=1.0, start_from=0.0;
    double culc_func(double);
    dx = (to - start_from) / intarval_num;

    for(i=1; i<=intarval_num-1; i+=2)
    {
        x = start_from + i*dx;
        y = (culc_func(x))*4.0/3.0;
        sum += y*dx;
    } 

    for(i=2; i<=intarval_num-2; i+=2)
    {
        x = start_from + i*dx;
        y = (culc_func(x))*2.0/3.0;
        sum += y*dx;
    }
    y = (culc_func(start_from) + culc_func(to)) * 1.0/3.0;
    sum += y*dx;
    return sum;
}

double culc_func(double x)
{
    double y;
    y = (4*x)/(2*x*x+5*x+2);
    return y;
}