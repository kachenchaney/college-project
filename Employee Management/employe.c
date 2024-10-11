#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char nip[20];
    char nama[50];
    char alamat[100];
    char no_hp[15];
    char jabatan[50];
    char golongan[3];
    int gaji_pokok;
};

struct Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

int hitung_kupon(int total_pembelian) {
    return total_pembelian / 100000;
}

float hitung_diskon(int total_pembelian) {
    if (total_pembelian >= 100000) {
        return total_pembelian * 0.05;
    }
    return 0;
}

int get_gaji_pokok(char* golongan) {
    if (strcmp(golongan, "D1") == 0) return 2500000;
    if (strcmp(golongan, "D2") == 0) return 2000000;
    if (strcmp(golongan, "D3") == 0) return 1500000;
    return 0;
}

int get_lembur_per_jam(char* golongan) {
    if (strcmp(golongan, "D1") == 0) return 10000;
    if (strcmp(golongan, "D2") == 0) return 5000;
    if (strcmp(golongan, "D3") == 0) return 2500;
    return 0;
}

void tambah_pegawai() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Maaf, kapasitas pegawai sudah penuh.\n");
        return;
    }
    
    struct Employee emp;
    printf("Masukkan NIP: ");
    scanf("%s", emp.nip);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]", emp.nama);
    printf("Masukkan Alamat: ");
    scanf(" %[^\n]", emp.alamat);
    printf("Masukkan No HP: ");
    scanf("%s", emp.no_hp);
    printf("Masukkan Jabatan: ");
    scanf(" %[^\n]", emp.jabatan);
    printf("Masukkan Golongan (D1/D2/D3): ");
    scanf("%s", emp.golongan);

    emp.gaji_pokok = get_gaji_pokok(emp.golongan);

    employees[employee_count++] = emp;

    printf("\nData Pegawai:\n");
    printf("NIP: %s\n", emp.nip);
    printf("Nama: %s\n", emp.nama);
    printf("Alamat: %s\n", emp.alamat);
    printf("No HP: %s\n", emp.no_hp);
    printf("Jabatan: %s\n", emp.jabatan);
    printf("Golongan: %s\n", emp.golongan);
    printf("Gaji Pokok: Rp%d\n", emp.gaji_pokok);
}

void hitung_gaji() {
    char nip[20], golongan[3];
    int jam_lembur;
    printf("Masukkan NIP: ");
    scanf("%s", nip);
    printf("Masukkan Golongan (D1/D2/D3): ");
    scanf("%s", golongan);
    printf("Masukkan Jumlah Jam Lembur: ");
    scanf("%d", &jam_lembur);

    int gaji_pokok = get_gaji_pokok(golongan);
    int lembur_per_jam = get_lembur_per_jam(golongan);
    int total_lembur = jam_lembur * lembur_per_jam;
    int total_gaji = gaji_pokok + total_lembur;

    printf("\nHasil Perhitungan Gaji:\n");
    printf("NIP: %s\n", nip);
    printf("Golongan: %s\n", golongan);
    printf("Lembur: %d jam\n", jam_lembur);
    printf("Total Gaji Bulan ini: Rp%d\n", total_gaji);
}

void tampilkan_semua_pegawai() {
    if (employee_count == 0) {
        printf("Belum ada data pegawai yang tersimpan.\n");
        return;
    }

    printf("\nDaftar Semua Pegawai:\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("Pegawai #%d\n", i+1);
        printf("NIP: %s\n", employees[i].nip);
        printf("Nama: %s\n", employees[i].nama);
        printf("Alamat: %s\n", employees[i].alamat);
        printf("No HP: %s\n", employees[i].no_hp);
        printf("Jabatan: %s\n", employees[i].jabatan);
        printf("Golongan: %s\n", employees[i].golongan);
        printf("Gaji Pokok: Rp%d\n", employees[i].gaji_pokok);
        printf("---------------------------------------\n");
    }
}

int main() {
    int pilihan;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Pegawai\n");
        printf("2. Hitung Gaji\n");
        printf("3. Hitung Kupon dan Diskon\n");
        printf("4. Tampilkan Semua Pegawai\n");
        printf("5. Keluar\n");
        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambah_pegawai();
                break;
            case 2:
                hitung_gaji();
                break;
            case 3:
                {
                    int total_pembelian;
                    printf("Masukkan total pembelian: Rp");
                    scanf("%d", &total_pembelian);
                    int kupon = hitung_kupon(total_pembelian);
                    float diskon = hitung_diskon(total_pembelian);
                    float total_bayar = total_pembelian - diskon;
                    printf("Jumlah kupon: %d\n", kupon);
                    printf("Diskon: Rp%.2f\n", diskon);
                    printf("Total bayar: Rp%.2f\n", total_bayar);
                }
                break;
            case 4:
                tampilkan_semua_pegawai();
                break;
            case 5:
                printf("Terima kasih, program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);

    return 0;
}