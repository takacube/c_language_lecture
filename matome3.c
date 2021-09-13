#include <stdio.h>
#include <math.h>

double targeted_formula(double x)
{
    double y;
    y = log(x + sqrt(x*x+1));
    return y;
}

int main()
{
    double h = 0.01, x=3.0;
    double tyusin; 
    tyusin = (targeted_formula(x+h)-targeted_formula(x-h))/2.0/h;
    printf("Tyusin log(x+√(x^2+1)) = %lf\n", tyusin);
}