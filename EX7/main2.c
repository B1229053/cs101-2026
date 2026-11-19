#include <stdio.h>
#include <string.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

void total_price(book_t books[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i].price;
    }
    printf("Total Price: %d\n", sum);
}

void list_books(book_t books[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s (Price: %d)\n", books[i].id, books[i].title, books[i].price);
    }
}

int main() {
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300,  "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550,  "Killers of the Flower Moon"},
        {5, 870,  "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟 Book.bin\n");
        return 1;
    }
    fwrite(books, sizeof(book_t), 6, fp);
    fclose(fp);

    book_t read_books[6];
    fp = fopen("Book.bin", "rb");
    if (fp != NULL) {
        fread(read_books, sizeof(book_t), 6, fp);
        fclose(fp);
    }

    total_price(read_books, 6);
    printf("\n");
    list_books(read_books, 6);

    return 0;
}
