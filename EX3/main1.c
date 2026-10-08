#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 1; i <= 6; i++) {
        /* 印出前面的空白 */
        for (j = 0; j < 6 - i; j++) {
            printf(" ");
        }

        /* 第 i 層印出 i 個數字 i */
        for (j = 1; j <= i; j++) {
            printf("%d", i);
            if (j < i) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
