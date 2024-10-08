#include <stdio.h>
#include <string.h>

typedef struct {
    char nama[50];
    int umur;
    char universitas[50];
    char jurusan[50];
} Mahasiswa;

int main() {
    Mahasiswa mhs;
    
    strcpy(mhs.nama, "Zacharia Ananta Wijaya");
    mhs.umur = 19;
    strcpy(mhs.universitas, "Binus University");
    strcpy(mhs.jurusan, "Computer Science");
    
    printf("\nData Mahasiswa:\n");
    printf("Nama: %s\n", mhs.nama);
    printf("Umur: %d tahun\n", mhs.umur);
    printf("Universitas: %s\n", mhs.universitas);
    printf("Jurusan: %s\n", mhs.jurusan);
    
    return 0;
}