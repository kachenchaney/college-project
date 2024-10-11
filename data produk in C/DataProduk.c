#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Struktur untuk menyimpan data produk
typedef struct {
    char nama[50];
    float harga;
    int stok;
} Produk;

// Fungsi untuk menambahkan data produk
void tambahProduk(Produk produk[], int *jumlah) {
    if (*jumlah >= MAX_PRODUCTS) {
        printf("\nTidak dapat menambahkan lebih banyak produk. Batas maksimum tercapai.\n");
        return;
    }
    
    printf("\nMasukkan data produk:\n");
    printf("Nama: ");
    getchar(); // Membersihkan newline character dari buffer
    fgets(produk[*jumlah].nama, sizeof(produk[*jumlah].nama), stdin);
    produk[*jumlah].nama[strcspn(produk[*jumlah].nama, "\n")] = 0; // Menghapus newline di akhir input
    printf("Harga: ");
    scanf("%f", &produk[*jumlah].harga);
    printf("Stok: ");
    scanf("%d", &produk[*jumlah].stok);
    (*jumlah)++;
    printf("\nProduk berhasil ditambahkan.\n");
}

// Fungsi untuk menampilkan semua produk
void tampilkanSemuaProduk(Produk produk[], int jumlah) {
    if (jumlah == 0) {
        printf("\nBelum ada produk yang ditambahkan.\n");
        return;
    }
    
    printf("\nDaftar semua produk:\n");
    for (int i = 0; i < jumlah; i++) {
        printf("\nProduk %d:\n", i + 1);
        printf("Nama: %s\n", produk[i].nama);
        printf("Harga: %.2f\n", produk[i].harga);
        printf("Stok: %d\n", produk[i].stok);
    }
}

int main() {
    Produk produk[MAX_PRODUCTS];
    int jumlah = 0;
    int pilihan;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Produk\n");
        printf("2. Tampilkan Semua Produk\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahProduk(produk, &jumlah);
                break;
            case 2:
                tampilkanSemuaProduk(produk, jumlah);
                break;
            case 3:
                printf("\nTerima kasih!\n");
                exit(0);
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}