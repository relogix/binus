#include <stdio.h>

struct alamat {
        char kota[20];
        char negara[20];
    };

struct mahasiswa {
        char nama[20];
        int umur;
        struct alamat a1;
    };

int main() {
    struct mahasiswa m1 = {"Luthfi", 20, {"Bandung", "Indonesia"}};
    
    printf("Informasi Mahasiswa\n");
    printf("Nama: %s\n", m1.nama);
    printf("Umur: %d\n", m1.umur);
    printf("Kota Asal: %s\n", m1.a1.kota);
    printf("Negara Asal: %s\n", m1.a1.negara);
    
    return 0;
}