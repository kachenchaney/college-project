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

// Struktur untuk menyimpan data penjualan (history)
typedef struct {
    char kode[10];
    int jumlah;
    int totalHarga;
} History;

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

// Fungsi untuk memastikan file ada atau membuat file kosong jika tidak ada
void cekAtauBuatFile(const char *namaFile) {
    FILE *file = fopen(namaFile, "r");
    if (file == NULL) {
        // Jika file tidak ada, buat file kosong
        file = fopen(namaFile, "w");
        if (file != NULL) {
            printf("Membuat file kosong: %s\n", namaFile);
            fclose(file);
        } else {
            printf("Gagal membuat file: %s\n", namaFile);
        }
    } else {
        fclose(file);
    }
}

// Fungsi untuk membaca data buku dari file
void bacaDataBuku(Buku buku[], int *jumlahBuku) {
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL) {
        printf("File databuku.txt tidak ditemukan!\n");
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
        return;
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

// Fungsi untuk membaca data history dari file
void bacaHistory(History history[], int *jumlahHistory) {
    FILE *file = fopen("datahistory.txt", "r");
    if (file == NULL) {
        printf("File datahistory.txt tidak ditemukan!\n");
        return;
    }

    *jumlahHistory = 0;
    while (fscanf(file, "%s %d %d", history[*jumlahHistory].kode, &history[*jumlahHistory].jumlah, &history[*jumlahHistory].totalHarga) != EOF) {
        (*jumlahHistory)++;
    }
    fclose(file);
}

// Fungsi untuk menampilkan data history penjualan
void viewHistory(History history[], int jumlahHistory) {
    printf("\n=== DATA HISTORY ===\n");
    for (int i = 0; i < jumlahHistory; i++) {
        printf("%d. Kode Buku: %s, Jumlah: %d, Total Harga: %d\n", i + 1, history[i].kode, history[i].jumlah, history[i].totalHarga);
    }
}

// Fungsi untuk menghapus data history berdasarkan index
void deleteHistory(History history[], int *jumlahHistory) {
    int index;
    printf("\nPilih index history yang akan dihapus: ");
    scanf("%d", &index);
    if (index < 1 || index > *jumlahHistory) {
        printf("Index tidak valid!\n");
        return;
    }

    for (int i = index - 1; i < *jumlahHistory - 1; i++) {
        history[i] = history[i + 1];
    }
    (*jumlahHistory)--;
    printf("Data history berhasil dihapus!\n");
}

// Fungsi untuk menyimpan data history ke file
void simpanHistory(History history[], int jumlahHistory) {
    FILE *file = fopen("datahistory.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menyimpan data history!\n");
        return;
    }
    for (int i = 0; i < jumlahHistory; i++) {
        fprintf(file, "%s %d %d\n", history[i].kode, history[i].jumlah, history[i].totalHarga);
    }
    fclose(file);
}

int main() {
    Buku buku[100];
    History history[100];
    int jumlahBuku = 0;
    int jumlahHistory = 0;
    int pilihan;

    // Cek atau buat file databuku.txt dan datahistory.txt jika tidak ada
    cekAtauBuatFile("databuku.txt");
    cekAtauBuatFile("datahistory.txt");

    // Baca data buku dan history dari file
    bacaDataBuku(buku, &jumlahBuku);
    bacaHistory(history, &jumlahHistory);

    while (1) {
        menuUtama();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                inputDataBuku(buku, &jumlahBuku);
                break;
            case 2:
                viewHistory(history, jumlahHistory);
                break;
            case 3:
                viewDataBuku(buku, jumlahBuku);
                break;
            case 4:
                deleteHistory(history, &jumlahHistory);
                simpanHistory(history, jumlahHistory);
                break;
            case 5:
                deleteDataBuku(buku, &jumlahBuku);
                break;
            case 6:
                // Simpan data buku dan history ke file dan keluar
                simpanDataBuku(buku, jumlahBuku);
                simpanHistory(history, jumlahHistory);
                printf("Program selesai. Data disimpan.\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}
