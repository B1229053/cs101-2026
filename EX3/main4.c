#include <stdio.h>

int is_odd(int number)
{
    return number % 2 != 0;
}

int main(void)
{
    int i = 10;

    if (is_odd(i)) {
        printf("奇數\n");
    } else {
        printf("偶數\n");
    }

    return 0;
}
