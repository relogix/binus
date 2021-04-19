// Tugas Personal 2 - Algoritma dan Pemrograman
// Program Nilai Akhir Mahasiswa
// ============================================
// MUHAMMAD LUTHFI HIZBULLOH - 2401974964

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct structPenilaian {
        int nilaiHadir;
        int nilaiTugas;
        int nilaiQuiz;
        int nilaiKeaktifanForum;
        int nilaiUAS;
        bool sudahDinilai;
    };

struct structMahasiswa {
        char nim[20];
        char nama[30];
        char mataKuliah[20];
        struct structPenilaian nilaiMahasiswa;
    };

int main(){
    //Variabel Mahasiswa
    struct structMahasiswa mahasiswa[50];
    int indexMahasiswa = 0;

    //Judul Program ----------------------------------------------------------
    void titleScreen(){
        printf("Program Nilai Akhir Mahasiswa");
        printf("\n==========================\n");
    }

    //Menu Awal --------------------------------------------------------------
    int menu = 0;
    char inputMenu[1];
    bool inputError = false;
    bool pilihMenu(bool inputError){\
        printf("Menu Utama: \n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Input Nilai Mahasiswa\n");
        printf("3. Lihat Nilai & Status Mahasiswa\n");
        printf("4. Keluar Program\n\n");

        if (inputError == 1){
            printf("Input salah. Masukkan angka (1, 2, 3, atau 4)\n");
        }
        printf("Pilih Menu (1, 2, 3, 4): ");
        scanf(" %[^\n]s", inputMenu);
        return atoi(inputMenu) < 1 || atoi(inputMenu) > 4;
    }
 
    void menuUtama(){
        while (atoi(inputMenu) < 1 || atoi(inputMenu) > 4){
            system("cls");
            titleScreen();
            inputError = pilihMenu(inputError);
        }
        menu = atoi(inputMenu);
        inputMenu[0] = '0';
    }


    //Kembali Ke Menu Utama atau Tetap di Menu Aktif
    void kembaliAtauTetap(char namaMenu[20]){
        char inputKembaliAtauTetap[1];
        printf("\nKembali ke Menu Utama (k) atau tetap di menu %s (y)? ", namaMenu);
        scanf(" %[^\n]s", &inputKembaliAtauTetap);

        if (strcmp((inputKembaliAtauTetap), "k") == 0 || strcmp((inputKembaliAtauTetap), "K") == 0){
            menu = 0;
        } 
        else if (strcmp((inputKembaliAtauTetap), "y") != 0 && strcmp((inputKembaliAtauTetap), "Y") != 0){
            kembaliAtauTetap(namaMenu);
        }
    }

    //Fungsi Utility --------------------------------------------------------------

    //Lihat Data Mahasiswa
    void lihatDataMahasiswa(){
        //Lihat Data Mahasiswa
        printf("\nData Mahasiswa (Jml. Mahasiswa: %d)\n", (indexMahasiswa));
        printf("=====================================\n");
        
        int i;
        for (i = 0; i < indexMahasiswa; i++){
            printf("%d. %s | %s | %s\n", i + 1, mahasiswa[i].nim, mahasiswa[i].nama, mahasiswa[i].mataKuliah);
        }
    }

     void lihatInformasiMahasiswaDetail(struct structMahasiswa mahasiswaAktif, bool denganNilai){
        system("cls");
        printf("\nInformasi Mahasiswa\n");
        printf("===================\n");
        printf("Nama: %s\n", mahasiswaAktif.nama);
        printf("NIM: %s\n", mahasiswaAktif.nim);
        printf("Mata Kuliah: %s\n\n", mahasiswaAktif.mataKuliah);

        if (denganNilai == 1){
            printf("Nilai Mahasiswa:\n");
            printf("================\n");
            printf("Nilai Hadir: %d\n", mahasiswaAktif.nilaiMahasiswa.nilaiHadir);
            printf("Nilai Tugas: %d\n", mahasiswaAktif.nilaiMahasiswa.nilaiTugas);
            printf("Nilai Quiz: %d\n", mahasiswaAktif.nilaiMahasiswa.nilaiQuiz);
            printf("Nilai Keaktifan Forum: %d\n", mahasiswaAktif.nilaiMahasiswa.nilaiKeaktifanForum);
            printf("Nilai UAS: %d\n", mahasiswaAktif.nilaiMahasiswa.nilaiUAS);
        }
    }

    //Menu 1 : Input Mahasiswa -----------------------------------------------
    void inputMahasiswa(){
        struct structMahasiswa mahasiswaBaru;
        bool mahasiswaTersedia = false;
        bool inputNimError = false;

        system("cls");
        printf("Input Mahasiswa\n");
        printf("==========================\n");
        printf("Masukkan Informasi Mahasiswa\n");
        
        do {
            if (mahasiswaTersedia == 1) printf("\nNIM sudah tersedia. Masukkan NIM baru\n");
            if (inputNimError == 1) printf("\nNIM harus berupa angka\n");
            printf("NIM: ");
            scanf(" %[^\n]s", &mahasiswaBaru.nim);

            //Cek NIM jika sudah tersedia
            mahasiswaTersedia = false;
            if (indexMahasiswa > 0){
            	int i;
                for (i = 0; i < indexMahasiswa; i++) {
                    if (strcmp(mahasiswa[i].nim, mahasiswaBaru.nim) == 0){
                        mahasiswaTersedia = true;
                    }
                }
            }

            //Cek NIM harus berupa angka
            if (strcmp(mahasiswaBaru.nim, "0") != 0 && atoi(mahasiswaBaru.nim) == 0)
                inputNimError = true;
            else inputNimError = false;

        } while (mahasiswaTersedia == 1 || inputNimError == 1);

        printf("Nama Lengkap: ");
        scanf(" %[^\n]s", &mahasiswaBaru.nama);
        
        printf("Mata Kuliah: ");
        scanf(" %[^\n]s", &mahasiswaBaru.mataKuliah);

        mahasiswa[indexMahasiswa] = mahasiswaBaru;
        indexMahasiswa++;

        //Lihat Data Mahasiswa
        lihatDataMahasiswa();

        //Kembali Atau Tetap di Menu
        kembaliAtauTetap("Input Data Mahasiswa");
    }

    //Menu 2 : Input Nilai Mahasiswa -----------------------------------------
    void inputNilaiMahasiswa(){
        char inputNim[20] = "";
        bool mahasiswaDitemukan = false;
        int indexMahasiswaAktif = 0;

        system("cls");
        printf("Input Nilai Mahasiswa\n");
        printf("==========================\n");

        if (indexMahasiswa == 0){
            printf("Data Mahasiswa masih kosong. Masuk ke menu 1 untuk menginput data mahasiswa\n");
        } else {
            //Lihat Data Mahasiswa
            lihatDataMahasiswa();
            
            do {
                if (!mahasiswaDitemukan && strcmp(inputNim, "") != 0) printf("\nNIM tidak ditemukan!");
                printf("\nMasukkan NIM Mahasiswa: ");
                scanf(" %[^\n]s", inputNim);

                //Cek Mahasiswa menggunakan NIM
                mahasiswaDitemukan = false;
                
                int i;
                for (i = 0; i < indexMahasiswa; i++){
                    if (strcmp(mahasiswa[i].nim, inputNim) == 0){
                        mahasiswaDitemukan = true;
                        indexMahasiswaAktif = i;
                    }
                }
            } while (!mahasiswaDitemukan);

           
            lihatInformasiMahasiswaDetail(mahasiswa[indexMahasiswaAktif], false);

            printf("Masukkan Nilai Mahasiswa\n");

            int inputNilai(char* teksInput){
                char input[4];
                bool inputError = false;
                do {
                    if (inputError && ((strcmp(input, "0") != 0 && atoi(input) <= 0) || atoi(input) > 100))
                        printf("\n%s harus berupa angka antara 0 - 100\n", teksInput);
                    printf("%s: ", teksInput);
                    scanf(" %[^\n]s", input);
                    inputError = true;
                } while ((strcmp(input, "0") != 0 && atoi(input) <= 0) || atoi(input) > 100);

                return atoi(input);
            }

            mahasiswa[indexMahasiswaAktif].nilaiMahasiswa.nilaiHadir = inputNilai("Nilai Hadir");
            mahasiswa[indexMahasiswaAktif].nilaiMahasiswa.nilaiTugas = inputNilai("Nilai Tugas");
            mahasiswa[indexMahasiswaAktif].nilaiMahasiswa.nilaiQuiz = inputNilai("Nilai Quiz");
            mahasiswa[indexMahasiswaAktif].nilaiMahasiswa.nilaiKeaktifanForum = inputNilai("Nilai Keaktifan Forum");
            mahasiswa[indexMahasiswaAktif].nilaiMahasiswa.nilaiUAS = inputNilai("Nilai UAS");
            mahasiswa[indexMahasiswaAktif].nilaiMahasiswa.sudahDinilai = true;

            lihatInformasiMahasiswaDetail(mahasiswa[indexMahasiswaAktif], true);
        }

        //Kembali Atau Tetap di Menu
        kembaliAtauTetap("Input Nilai Mahasiswa");
    }

    //Menu 3 : Nilai dan Status Mahasiswa -----------------------------------------
    void nilaiDanStatusMahasiswa(){
        char inputNim[20] = "";
        bool mahasiswaDitemukan = false;
        int indexMahasiswaAktif = 0;

        system("cls");
        printf("Nilai & Status Mahasiswa\n");
        printf("==========================\n");

        if (indexMahasiswa == 0){
            printf("Data Mahasiswa masih kosong. Masuk ke menu 1 untuk menginput data mahasiswa\n");
        } else {
            //Lihat Data Mahasiswa
            lihatDataMahasiswa();
            
            do {
                if (!mahasiswaDitemukan && strcmp(inputNim, "") != 0) printf("\nNIM tidak ditemukan!");
                printf("\nMasukkan NIM Mahasiswa: ");
                scanf(" %[^\n]s", inputNim);

                //Cek Mahasiswa menggunakan NIM
                mahasiswaDitemukan = false;
                
                int i;
                for (i = 0; i < indexMahasiswa; i++){
                    if (strcmp(mahasiswa[i].nim, inputNim) == 0){
                        mahasiswaDitemukan = true;
                        indexMahasiswaAktif = i;
                    }
                }
            } while (!mahasiswaDitemukan);

            if (mahasiswa[indexMahasiswaAktif].nilaiMahasiswa.sudahDinilai != 1){
                printf("\nMahasiswa ini belum dinilai. Beri penilaian di menu 2.\n");
            } else {
                lihatInformasiMahasiswaDetail(mahasiswa[indexMahasiswaAktif], true);

                struct structPenilaian nilaiMahasiswa = mahasiswa[indexMahasiswaAktif].nilaiMahasiswa;
                float nilaiAkhir = (nilaiMahasiswa.nilaiHadir / 10.0) + 
                    (nilaiMahasiswa.nilaiTugas / 5.0) + 
                    (nilaiMahasiswa.nilaiQuiz / 10.0) + 
                    (nilaiMahasiswa.nilaiKeaktifanForum / 10.0) + 
                    (nilaiMahasiswa.nilaiUAS / 2.0);

                char grade;
                bool statusLulus = true;
                if (nilaiAkhir >= 90){
                    grade = 'A';
                } else if (nilaiAkhir >= 80){
                    grade = 'B';
                } else if (nilaiAkhir >= 70){
                    grade = 'C';
                } else if (nilaiAkhir >= 60){
                    grade = 'D';
                } else if (nilaiAkhir >= 50){
                    grade = 'E';
                    statusLulus = false;
                } else {
                    grade = 'F';
                    statusLulus = false;
                }

                printf("\nNilai Akhir Mahasiswa\n");
                printf("=======================\n");
                printf("Nilai Akhir: %0.1f\n", nilaiAkhir);
                printf("Grade: %c\n", grade);
                printf("Status: %s\n", statusLulus == 1 ? "Lulus" : "Tidak Lulus");
            }
        }

        //Kembali Atau Tetap di Menu
        kembaliAtauTetap("Nilai & Status Mahasiswa");
    }

    //Navigasi ---------------------------------------------------------------
    while (1){
        if (menu == 0){
            menuUtama();
        } else if (menu == 1){
            inputMahasiswa();
        } else if (menu == 2){
            inputNilaiMahasiswa();
        } else if (menu == 3){
            nilaiDanStatusMahasiswa();
        } else if (menu == 4){
            printf("\nSampai Jumpa, Terima Kasih");
            exit(0);
        } else {
            exit(0);
        }
    }

    return 0;
}
