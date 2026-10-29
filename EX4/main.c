#include <stdio.h>

int main(void)
{
    FILE *fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1f, 1.2f, 1.3f};

    int read_a[3];
    char read_b[4];
    float read_c[3];
    int i;

    /* 將三個陣列寫入二進位檔案 */
    fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        perror("開啟檔案失敗");
        return 1;
    }

    if (fwrite(a, sizeof(a), 1, fp) != 1 ||
        fwrite(b, sizeof(b), 1, fp) != 1 ||
        fwrite(c, sizeof(c), 1, fp) != 1) {
        fprintf(stderr, "寫入檔案失敗\n");
        fclose(fp);
        return 1;
    }

    if (fclose(fp) != 0) {
        perror("關閉檔案失敗");
        return 1;
    }

    /* 重新開啟檔案，依照寫入順序讀取 */
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        perror("開啟檔案失敗");
        return 1;
    }

    if (fread(read_a, sizeof(read_a), 1, fp) != 1 ||
        fread(read_b, sizeof(read_b), 1, fp) != 1 ||
        fread(read_c, sizeof(read_c), 1, fp) != 1) {
        fprintf(stderr, "讀取檔案失敗\n");
        fclose(fp);
        return 1;
    }

    if (fclose(fp) != 0) {
        perror("關閉檔案失敗");
        return 1;
    }

    /* 輸出讀回的三個陣列 */
    for (i = 0; i < 3; i++) {
        printf("%d%c", read_a[i], i == 2 ? '\n' : ' ');
    }

    for (i = 0; i < 3; i++) {
        printf("%c%c", read_b[i], i == 2 ? '\n' : ' ');
    }

    for (i = 0; i < 3; i++) {
        printf("%f%c", read_c[i], i == 2 ? '\n' : ' ');
    }

    return 0;
}
