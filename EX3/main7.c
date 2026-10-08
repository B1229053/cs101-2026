#include <stdio.h>

int calculate_taxi_fare(int meters)
{
    if (meters <= 1500) {
        return 70;
    }

    int extra = meters - 1500;
    int units = extra / 100;

    if (extra % 100 != 0) {
        units++;
    }

    return 70 + units * 10;
}

int main(void)
{
    int i = 1000;

    printf("%d元\n", calculate_taxi_fare(i));

    return 0;
}
