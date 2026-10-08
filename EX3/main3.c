#include <stdio.h>

void print_result(int number)
{
    if (number % 15 == 0) {
        printf("Love IU\n");
    } else if (number % 3 == 0) {
        printf("Love\n");
    } else if (number % 5 == 0) {
        printf("IU\n");
    } else {
        printf("%d\n", number);
    }
}

int main(void)
{
    int i = 10;

    print_result(i);

    return 0;
}
