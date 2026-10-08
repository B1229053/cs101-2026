#include <stdio.h>

void print_circumference(int diameter)
{
    const double pi = 3.141592653589793;
    double circumference = diameter * pi;

    long long scaled = (long long)(circumference * 100000.0);

    printf("%.5f\n", scaled / 100000.0);
}

int main(void)
{
    int i = 1;

    print_circumference(i);

    return 0;
}
