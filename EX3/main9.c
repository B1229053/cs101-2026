#include <stdio.h>

int combine_digits(int hundreds, int tens, int ones)
{
    if (hundreds < 0) {
        return hundreds * 100 - tens * 10 - ones;
    }

    return hundreds * 100 + tens * 10 + ones;
}

int main(void)
{
    int x = 9;
    int y = 9;
    int z = 1;

    printf("%d\n", combine_digits(x, y, z));

    return 0;
}
