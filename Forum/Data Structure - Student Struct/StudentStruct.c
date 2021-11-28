// Online C compiler to run C program online
#include <stdio.h>

struct structMahasiswa {
        char nama[30];
        int tanggalLahir;
        int bulanLahir;
        int tahunLahir;
        long biayaSemester;
    };

int main() {
    //Variabel Mahasiswa
    struct structMahasiswa mahasiswa;
    
    // Fungsi Lihat Mahasiswa
    void lihatMahasiswa(){
        printf("Data Mahasiswa\n");
        printf("==========================\n");
        printf("Nama Lengkap: %s\n", mahasiswa.nama);
        printf("Tanggal Lahir: %d/%d/%d\n", mahasiswa.tanggalLahir, mahasiswa.bulanLahir, mahasiswa.tahunLahir);
        printf("Biaya Per Semester: Rp. %d\n", mahasiswa.biayaSemester);
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

        mahasiswa = mahasiswaBaru;
        printf("-\n");
        lihatMahasiswa();
    }
    
    inputMahasiswa();
}