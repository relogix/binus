// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

struct structMahasiswa {
        char nama[30];
        int tanggalLahir;
        int bulanLahir;
        int tahunLahir;
        long biayaSemester;
    };

int main() {
    //Variabel Mahasiswa
    struct structMahasiswa mahasiswa[5];
    int indexMahasiswa = 0;
    
    // Fungsi Lihat Mahasiswa
    void lihatMahasiswa(){
        printf("\nData Mahasiswa (Jml: %d)\n", (indexMahasiswa));
        printf("Nama Lengkap | Tanggal Lahir | Biaya Semester\n");
        printf("=====================================\n");
        
        int i;
        for (i = 0; i < indexMahasiswa; i++){
            printf("%d. %s | %d/%d/%d | Rp. %d\n", i+1, mahasiswa[i].nama, mahasiswa[i].tanggalLahir, mahasiswa[i].bulanLahir, mahasiswa[i].tahunLahir, mahasiswa[i].biayaSemester);
        }
        printf("\n\n");
    }
    
    // Fungsi Input
    void inputMahasiswa(){
        struct structMahasiswa mahasiswaBaru;

        printf("Input Mahasiswa\n");
        printf("==========================\n");
        printf("Masukkan Informasi Mahasiswa\n");
        

        printf("Nama Lengkap: ");
        scanf(" %[^\n]s", &mahasiswaBaru.nama);
        
        printf("Tanggal Lahir (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &mahasiswaBaru.tanggalLahir, &mahasiswaBaru.bulanLahir, &mahasiswaBaru.tahunLahir);
        
        printf("Biaya Per Semester: Rp. ");
        scanf("%d", &mahasiswaBaru.biayaSemester);

        mahasiswa[indexMahasiswa] = mahasiswaBaru;
        indexMahasiswa++;
        
        printf("-\n");
        lihatMahasiswa();
    }
    
    int ulangProgram = 1;
    while(ulangProgram){
        inputMahasiswa();
        
        char inputUlangProgram[1];
        printf("\nTambah Mahasiswa Baru (y)? ");
        scanf(" %[^\n]s", &inputUlangProgram);
        
        if (strcmp((inputUlangProgram), "y") != 0 && strcmp((inputUlangProgram), "Y") != 0){
            printf("\nProgram Dihentikan.");
            exit(0);
        } else {
            printf("\n\n");
        }
    }
    
}