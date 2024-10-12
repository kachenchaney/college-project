#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 50

void format_rupiah(long long int value, char *result) {
    char temp[20];
    int length, i, j;
    
    sprintf(temp, "%lld", value);
    length = strlen(temp);
    j = 0;
    
    for (i = length - 1; i >= 0; i--) {
        if ((length - i - 1) != 0 && (length - i - 1) % 3 == 0) {
            result[j++] = '.';
        }
        result[j++] = temp[i];
    }
    result[j] = '\0';
    
    // Reverse the string
    for (i = 0; i < j / 2; i++) {
        char t = result[i];
        result[i] = result[j - 1 - i];
        result[j - 1 - i] = t;
    }
}

int hitung_kupon(int total_pembelian) {
    return total_pembelian / 100000;
}

int hitung_diskon(int total_pembelian) {
    if (total_pembelian >= 100000) {
        return total_pembelian * 0.05;
    }
    return 0;
}

void get_kupon_message(int kupon, char *message) {
    if (kupon == 0) {
        strcpy(message, "Maaf, Anda belum mendapatkan kupon.");
    } else if (kupon == 1) {
        strcpy(message, "Selamat! Anda mendapatkan 1 kupon undian.");
    } else {
        sprintf(message, "Selamat! Anda mendapatkan %d kupon undian.", kupon);
    }
}

int main() {
    char nama_pembeli[MAX_NAME_LENGTH];
    int total_pembelian;
    char kupon_message[100];
    char formatted_total[20], formatted_diskon[20], formatted_bayar[20];

    printf("Masukkan nama pembeli: ");
    fgets(nama_pembeli, MAX_NAME_LENGTH, stdin);
    nama_pembeli[strcspn(nama_pembeli, "\n")] = 0; // Menghapus newline dari input

    printf("Masukkan total pembelian: Rp");
    scanf("%d", &total_pembelian);
    
    int kupon = hitung_kupon(total_pembelian);
    int diskon = hitung_diskon(total_pembelian);
    int total_bayar = total_pembelian - diskon;
    
    get_kupon_message(kupon, kupon_message);

    format_rupiah(total_pembelian, formatted_total);
    format_rupiah(diskon, formatted_diskon);
    format_rupiah(total_bayar, formatted_bayar);

    printf("\nHasil Perhitungan untuk %s:\n", nama_pembeli);
    printf("Total Pembelian: Rp%s\n", formatted_total);
    printf("Jumlah kupon: %d\n", kupon);
    printf("Diskon: Rp%s\n", formatted_diskon);
    printf("Total bayar: Rp%s\n", formatted_bayar);
    printf("%s\n", kupon_message);

    return 0;
}