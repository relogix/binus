#include <stdio.h>

int main() {
    int angka, i;
    printf("Masukkan Angka: ");
    scanf("%d", &angka);
    
    //Menggunakan For-Loop
     printf("For-Loop: ");
    for (i = 1; i <= angka; i++){
        printf("%d ", i*i);
    } 
    
    printf("\nDo-While: ");
    //Menggunakan Do-While
    i = 1;
    do {
        printf("%d ", i*i);
        i++;
    } while (i <= angka);
    
    return 0;
}