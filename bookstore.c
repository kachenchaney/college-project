#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan data buku
typedef struct {
    char kode[10];
    char nama[50];
    char jenis[30];
    int harga;
} Buku;

// Fungsi untuk menampilkan menu utama
void menuUtama() {
    printf("\n=== MENU UTAMA ===\n");
    printf("1. Input Data Buku\n");
    printf("2. View History\n");
    printf("3. View Buku\n");
    printf("4. Delete History\n");
    printf("5. Delete Buku\n");
    printf("6. Exit\n");
    printf("Pilih menu: ");
}

// Fungsi untuk membaca data buku dari file
void bacaDataBuku(Buku buku[], int *jumlahBuku) {
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL) {
        printf("File tidak ditemukan!\n");
        return;
    }

    *jumlahBuku = 0;
    while (fscanf(file, "%s %s %s %d", buku[*jumlahBuku].kode, buku[*jumlahBuku].nama, buku[*jumlahBuku].jenis, &buku[*jumlahBuku].harga) != EOF) {
        (*jumlahBuku)++;
    }
    fclose(file);
}

// Fungsi untuk menyimpan data buku ke file
void simpanDataBuku(Buku buku[], int jumlahBuku) {
    FILE *file = fopen("databuku.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menyimpan data!\n");
        return; // Tambahkan pengecekan jika file gagal dibuka
    }
    for (int i = 0; i < jumlahBuku; i++) {
        fprintf(file, "%s %s %s %d\n", buku[i].kode, buku[i].nama, buku[i].jenis, buku[i].harga);
    }
    fclose(file);
    printf("Data berhasil disimpan ke databuku.txt\n");
}

// Fungsi untuk menambahkan data buku baru
void inputDataBuku(Buku buku[], int *jumlahBuku) {
    printf("\nInput Kode Buku: ");
    scanf("%s", buku[*jumlahBuku].kode);
    printf("Input Nama Buku: ");
    scanf("%s", buku[*jumlahBuku].nama);
    printf("Input Jenis Buku: ");
    scanf("%s", buku[*jumlahBuku].jenis);
    printf("Input Harga Buku: ");
    scanf("%d", &buku[*jumlahBuku].harga);
    (*jumlahBuku)++;
    printf("Data buku berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan seluruh data buku
void viewDataBuku(Buku buku[], int jumlahBuku) {
    printf("\n=== DATA BUKU ===\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("%d. Kode: %s, Nama: %s, Jenis: %s, Harga: %d\n", i + 1, buku[i].kode, buku[i].nama, buku[i].jenis, buku[i].harga);
    }
}

// Fungsi untuk menghapus data buku berdasarkan index
void deleteDataBuku(Buku buku[], int *jumlahBuku) {
    int index;
    printf("\nPilih index buku yang akan dihapus: ");
    scanf("%d", &index);
    if (index < 1 || index > *jumlahBuku) {
        printf("Index tidak valid!\n");
        return;
    }

    for (int i = index - 1; i < *jumlahBuku - 1; i++) {
        buku[i] = buku[i + 1];
    }
    (*jumlahBuku)--;
    printf("Data buku berhasil dihapus!\n");
}

int main() {
    Buku buku[100];
    int jumlahBuku = 0;
    int pilihan;

    // Baca data buku dari file
    bacaDataBuku(buku, &jumlahBuku);

    while (1) {
        menuUtama();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                inputDataBuku(buku, &jumlahBuku);
                break;
            case 2:
                // Fitur View History belum diimplementasikan
                printf("Fitur View History belum tersedia.\n");
                break;
            case 3:
                viewDataBuku(buku, jumlahBuku);
                break;
            case 4:
                // Fitur Delete History belum diimplementasikan
                printf("Fitur Delete History belum tersedia.\n");
                break;
            case 5:
                deleteDataBuku(buku, &jumlahBuku);
                break;
            case 6:
                // Simpan data buku ke file dan keluar
                simpanDataBuku(buku, jumlahBuku);
                printf("Program selesai. Data disimpan.\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}
