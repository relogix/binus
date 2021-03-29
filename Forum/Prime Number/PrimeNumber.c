#include <stdio.h>

int main() {
    int angka;
    
    printf("Prime Number\n");
    printf("============\n\n");
    
    printf("Jumlah angka prima: ");
    scanf("%d", &angka);
    
    printf("\n%d bilangan prima:\n", angka);
    
    int primes = 0;
    int i = 2;
    while(primes < angka) {
        if (CheckPrime(i) == 1) {
            printf("%d ", i);
            primes++;
        };
        i++;
    }
    
    return 0;
}

int CheckPrime (angka){
    int i;
    for (i = 2; i < angka - 1; i++){
        if (angka%i == 0) return 0;
    }
    return 1;
}