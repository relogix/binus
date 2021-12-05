#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct structMahasiswa {
        int nim;
        char nama[30];
        char jurusan[50];
};
    
struct Node {
    struct structMahasiswa data;
    struct Node* next;
};


int lengthCheck(char str[50], int length) {
    if (strlen(str) < length) {
        return 1;
    } else  {
        return 0; 
    }
}

void printList(struct Node* n)
{
    int index = 1;
    while (n != NULL) {
        printf("%d. %d | %s | %s\n", index, n->data.nim, n->data.nama, n->data.jurusan);
        n = n->next;
        index++;
    }
}

void swap(struct Node *a, struct Node *b)
{
    struct structMahasiswa temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(struct Node *start)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
  
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data.nim > ptr1->next->data.nim)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
 
int main()
{
    // Buat Node
    struct Node* nodes[5];
    nodes[0] = (struct Node*)malloc(sizeof(struct Node));
    nodes[1] = (struct Node*)malloc(sizeof(struct Node));
    nodes[2] = (struct Node*)malloc(sizeof(struct Node));
    nodes[3] = (struct Node*)malloc(sizeof(struct Node));
    nodes[4] = (struct Node*)malloc(sizeof(struct Node));
    
    // Menu Utama
    printf("Program Mahasiswa Menggunakan Single Linked List\n");
    printf("================================================\n\n");
    
    int jumlahMahasiswa = 0;
    int tambahMahasiswa = 1;
    // Input Mahasiswa
    do {
        struct structMahasiswa mahasiswaBaru;
        mahasiswaBaru.nim = 0;
        strcpy(mahasiswaBaru.nama, "");
        strcpy(mahasiswaBaru.jurusan, "");
        
        printf("Tambah Mahasiswa (%d slot tersedia)\n", 5 - jumlahMahasiswa);
        
        // Input NIM
        do {
            if (mahasiswaBaru.nim > pow(10,10)) {
                printf("\n\nNIM tidak boleh melebihi 10 karakter\n");
            }
            printf("NIM: ");
            scanf("%d", &mahasiswaBaru.nim);
        } while (mahasiswaBaru.nim > pow(10,10));
        
        // Input Nama
        do {
            if (strlen(mahasiswaBaru.nama) > 0) {
                printf("\n\nNama tidak boleh melebihi 30 karakter\n");
            }
            printf("Nama: ");
            scanf(" %[^\n]s", &mahasiswaBaru.nama);
        } while (!lengthCheck(mahasiswaBaru.nama, 30));
        
        // Input Jurusan
        do {
            if (strlen(mahasiswaBaru.jurusan) > 0) {
                printf("\n\nJurusan tidak boleh melebihi 50 karakter\n");
            }
            printf("Jurusan: ");
            scanf(" %[^\n]s", &mahasiswaBaru.jurusan);
        } while (!lengthCheck(mahasiswaBaru.jurusan, 50));
        
        // Tambah Mahasiswa Lagi
        char tambah[10];
        printf("\nIngin menambahkan mahasiswa lagi? (y) ");
        scanf(" %[^\n]s", &tambah);
        if (strcmp(tambah, "y") != 0 && strcmp(tambah, "Y") != 0) {
            tambahMahasiswa = 0;
        }
        
        // Input Mahasiswa Ke Dalam Node
        nodes[jumlahMahasiswa]->data = mahasiswaBaru;
        nodes[jumlahMahasiswa]->next = tambahMahasiswa && jumlahMahasiswa < 5 ? nodes[jumlahMahasiswa + 1] : NULL;
        
        jumlahMahasiswa++;
        printf("\n-\n");
    } while (tambahMahasiswa && jumlahMahasiswa < 5);
    
    // Print Linked List
    printf("\nData Mahasiswa\n");
    printf("No. | NIM | Nama | Jurusan\n");
    printf("===========================\n");
    
    bubbleSort(nodes[0]);
    printList(nodes[0]);
    
    printf("Program Selesai.");
    
    return 0;
}