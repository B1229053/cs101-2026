#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩:");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("輸入組數必須在 1 到 5 之間\n");
        return 1;
    }

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟檔案\n");
        return 1;
    }

    time_t curtime;
    time(&curtime);
    char *time_str = ctime(&curtime);
    time_str[strlen(time_str) - 1] = '\0';

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    srand((unsigned)time(NULL));

    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);
        if (i <= n) {
            int lotto[7];
            for (int j = 0; j < 7; j++) {
                int num, duplicate;
                do {
                    duplicate = 0;
                    num = rand() % 69 + 1; 
                    for (int k = 0; k < j; k++) {
                        if (lotto[k] == num) {
                            duplicate = 1;
                            break;
                        }
                    }
                } while (duplicate);
                lotto[j] = num;
                fprintf(fp, "%02d ", lotto[j]);
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "-- -- -- -- -- -- --\n");
        }
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的%d組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
