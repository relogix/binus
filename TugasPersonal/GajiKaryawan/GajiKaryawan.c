//Program Perhitungan Gaji Karyawan
//------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Fungsi format angka
char * formatAngka(long int angka){
        char charAngka[20];
        char formatAngka[30] = {};
        static char result[30];
        sprintf(charAngka, "%d", angka);

		int i;
        for (i = 0; i < strlen(charAngka); i++){
            strncat(formatAngka, charAngka+i, 1);
            
            if ((strlen(charAngka) - (i + 1)) % 3 == 0 && strlen(charAngka)-1 != i){
                strcat(formatAngka, ".");
            }
        }
        
        strcpy(result, formatAngka);
        return result;
    }
    
//Fungsi LowerCase String
char * toLowerCase(char str[20]){
    static char newStr[20];
    strcpy(newStr, str);
    int i;
    for(i = 0; str[i]; i++){
      newStr[i] = tolower(str[i]);
    }
    return newStr;
}

int main() {
    //Deklarasi Variable ---------------------
    
    char nama[30];
    char inputGolongan[10];
    int golongan = 0;
    char pendidikan[5];
    char inputJamKerja[10];
    int jamKerja;
    
    //Input ----------------------------------
    printf("PROGRAM HITUNG GAJI KARYAWAN\n");
    printf("----------------------------\n");
    
    //Input Nama
    printf("Nama Karyawan: ");
    scanf(" %[^\n]s", nama);
    
    //Input Golongan
    printf("Golongan Jabatan: ");
    scanf(" %[^\n]s", inputGolongan);
    
    golongan = atoi(inputGolongan);

	while (golongan != 1 && golongan != 2 && golongan != 3) {
		printf("Golongan Jabatan (1/2/3): ");
		scanf(" %[^\n]s", inputGolongan);
		
		golongan = atoi(inputGolongan);
	}
    
    //Input Pendidikan
    printf("Pendidikan: ");
    scanf(" %[^\n]s", pendidikan);
    
    while (
            strcmp(toLowerCase(pendidikan), "sma") != 0 &&
            strcmp(toLowerCase(pendidikan), "d3") != 0 &&
            strcmp(toLowerCase(pendidikan), "s1") != 0
        ){
        printf("Pendidikan (SMA/D3/S1): ");
        scanf(" %[^\n]s", pendidikan);
    }
    
    //Input Jam Kerja
    printf("Jumlah Jam Kerja: ");
    scanf(" %[^\n]s", inputJamKerja);
    
    jamKerja = atoi(inputJamKerja);
    
    while (jamKerja <= 8){
        printf("Jumlah Jam Kerja (> 8 Jam): ");
        scanf(" %[^\n]s", inputJamKerja);
        
        jamKerja = atoi(inputJamKerja);
    }
    
    //Perhitungan Gaji ---------------------------
    
    long int gajiPokok = 2000000;
    
    //Tunjangan Golongan
    int persentaseGolongan;
    switch(golongan){
        case 1:
            persentaseGolongan = 5;
            break;
            
        case 2:
            persentaseGolongan = 10;
            break;
            
        case 3:
            persentaseGolongan = 15;
            break;
    };
    
    long int tunjanganGolongan = gajiPokok * persentaseGolongan / 100;
    
    //Tunjangan Golongan
    float persentasePendidikan;
    if (strcmp(toLowerCase(pendidikan), "sma") == 0) {
		persentasePendidikan = 0.025;
	} else if (strcmp(toLowerCase(pendidikan), "d3") == 0) {
		persentasePendidikan = 0.05;
	}
    else if (strcmp(toLowerCase(pendidikan), "s1") == 0) {
    	persentasePendidikan = 0.1;
	}
    
    long int tunjanganPendidikan = gajiPokok * persentasePendidikan;
    
    //Lembur
    int jamKerjaPerBulan = 25;
    int honorLembur = jamKerja > 8 ? (jamKerja - 8) * 3000 * jamKerjaPerBulan : 0;
    
    //Gaji Akhir
    long int gajiAkhir = gajiPokok + tunjanganGolongan + tunjanganPendidikan + honorLembur;
    
    
    //Output -------------------------------------
    
    printf("\n\n");
    printf("LAPORAN GAJI KARYAWAN\n");
    printf("---------------------\n");
    printf("Nama Karyawan: %s\n", nama);
    printf("\tTunjangan Jabatan: Rp. %s\n", formatAngka(tunjanganGolongan));
    printf("\tTunjangan Pendidikan: Rp. %s\n", formatAngka(tunjanganPendidikan));
    printf("\tHonor Lembur: Rp. %s\n", formatAngka(honorLembur));
    printf("Total Gaji: Rp. %s\n", formatAngka(gajiAkhir));
    
    //Hold program
    getchar();
    
    return 0;
}
