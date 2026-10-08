#include <stdio.h>

int calculate_parking_fee(int minutes)
{
    if (minutes <= 30) {
        return 0;
    }

    if (minutes >= 240) {
        return 240;
    }

    return ((minutes + 29) / 30) * 30;
}

int main(void)
{
    int i = 20;
    int fee = calculate_parking_fee(i);

    if (fee == 0) {
        printf("免費\n");
    } else {
        printf("%d元\n", fee);
    }

    return 0;
}
