#include <stdio.h>

int is_power_of_two(int number)
{
    return number > 0 && (number & (number - 1)) == 0;
}

int main(void)
{
    int i = 10;

    if (is_power_of_two(i)) {
        printf("是\n");
    } else {
        printf("否\n");
    }

    return 0;
}
