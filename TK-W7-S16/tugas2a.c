#include <stdio.h> // Fungsi input dan output seperti printf dan scanf
#include <string.h> // Untuk manipulasi string seperti strlen, strcpy, dan sprintf
#define MAX_NAME_LENGTH 50 // Mendefinisikan panjang maksimum nama pembeli yang dapat diinputkan

/*
 * Fungsi untuk memformat angka menjadi format rupiah
 * Misalnya, 1000000 akan menjadi "1.000.000"
 */
void format_rupiah(long long int value, char *result) {
    char temp[20]; // Menyimpan sementara nilai yang diubah menjadi string
    int length, i, j;
    
    // Mengubah nilai angka menjadi string
    sprintf(temp, "%lld", value);
    length = strlen(temp); // Menghitung panjang string
    j = 0;
    
    // Menambahkan tanda titik setiap 3 digit dari belakang
    for (i = length - 1; i >= 0; i--) {
        if ((length - i - 1) != 0 && (length - i - 1) % 3 == 0) {
            result[j++] = '.'; // Menambahkan tanda titik setelah setiap 3 digit
        }
        result[j++] = temp[i]; // Menyalin karakter dari belakang
    }
    result[j] = '\0'; // Menambahkan null terminator di akhir string
    
    // Membalik string untuk mendapatkan hasil akhir
    for (i = 0; i < j / 2; i++) {
        char t = result[i];
        result[i] = result[j - 1 - i];
        result[j - 1 - i] = t;
    }
}

/*
 * Fungsi untuk menghitung jumlah kupon yang diperoleh
 * Setiap kelipatan Rp100.000 dari total pembelian mendapatkan 1 kupon
 */
int hitung_kupon(int total_pembelian) {
    return total_pembelian / 100000; // Menghitung jumlah kupon berdasarkan kelipatan Rp100.000
}

/*
 * Fungsi untuk menghitung diskon berdasarkan total pembelian
 * Diskon 5% diberikan jika total pembelian minimal Rp100.000
 */
int hitung_diskon(int total_pembelian) {
    if (total_pembelian >= 100000) {
        return total_pembelian * 0.05; // Menghitung diskon 5% jika memenuhi syarat
    }
    return 0; // Tidak ada diskon jika total pembelian kurang dari Rp100.000
}

/*
 * Fungsi untuk menghasilkan pesan jumlah kupon yang didapatkan
 */
void get_kupon_message(int kupon, char *message) {
    if (kupon == 0) {
        strcpy(message, "Maaf, Anda belum mendapatkan kupon."); // Pesan jika tidak mendapatkan kupon
    } else if (kupon == 1) {
        strcpy(message, "Selamat! Anda mendapatkan 1 kupon undian."); // Pesan jika mendapatkan 1 kupon
    } else {
        sprintf(message, "Selamat! Anda mendapatkan %d kupon undian.", kupon); // Pesan jika mendapatkan lebih dari 1 kupon
    }
}

int main() {
    char nama_pembeli[MAX_NAME_LENGTH]; // Menyimpan nama pembeli
    int total_pembelian; // Menyimpan total pembelian
    char kupon_message[100]; // Menyimpan pesan kupon
    char formatted_total[20], formatted_diskon[20], formatted_bayar[20]; // Menyimpan nilai yang sudah diformat

    // Membaca nama pembeli
    printf("Masukkan nama pembeli: ");
    fgets(nama_pembeli, MAX_NAME_LENGTH, stdin); // Mengambil input nama pembeli
    nama_pembeli[strcspn(nama_pembeli, "\n")] = 0; // Menghapus karakter newline dari input

    // Membaca total pembelian
    printf("Masukkan total pembelian: Rp");
    scanf("%d", &total_pembelian); // Mengambil input total pembelian
    
    // Menghitung jumlah kupon, diskon, dan total pembayaran
    int kupon = hitung_kupon(total_pembelian); // Menghitung jumlah kupon yang diperoleh
    int diskon = hitung_diskon(total_pembelian); // Menghitung diskon yang diperoleh
    int total_bayar = total_pembelian - diskon; // Menghitung total yang harus dibayar
    
    // Menghasilkan pesan kupon yang didapatkan
    get_kupon_message(kupon, kupon_message); // Membuat pesan kupon berdasarkan jumlah kupon

    // Memformat nilai rupiah untuk output
    format_rupiah(total_pembelian, formatted_total); // Memformat total pembelian
    format_rupiah(diskon, formatted_diskon); // Memformat diskon
    format_rupiah(total_bayar, formatted_bayar); // Memformat total bayar

    // Menampilkan hasil perhitungan
    printf("\nHasil Perhitungan untuk %s:\n", nama_pembeli); // Menampilkan nama pembeli
    printf("Total Pembelian: Rp%s\n", formatted_total); // Menampilkan total pembelian
    printf("Jumlah kupon: %d\n", kupon); // Menampilkan jumlah kupon
    printf("Diskon: Rp%s\n", formatted_diskon); // Menampilkan diskon
    printf("Total bayar: Rp%s\n", formatted_bayar); // Menampilkan total bayar
    printf("%s\n", kupon_message); // Menampilkan pesan kupon

    return 0;
}
