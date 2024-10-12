#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMPLOYEES 100

// Struktur data untuk menyimpan informasi pegawai
struct Employee {
    char nip[20];     // Menyimpan NIP pegawai
    char nama[50];    // Menyimpan nama pegawai
    char alamat[100]; // Menyimpan alamat pegawai
    char no_hp[15];   // Menyimpan nomor HP pegawai
    char jabatan[50]; // Menyimpan jabatan pegawai
    char golongan[3]; // Menyimpan golongan pegawai
    int gaji_pokok;   // Menyimpan gaji pokok pegawai berdasarkan golongan
};

struct Employee employees[MAX_EMPLOYEES]; // Array untuk menyimpan data pegawai
int employee_count = 0; // Menyimpan jumlah pegawai yang sudah ditambahkan

// Fungsi untuk mendapatkan gaji pokok berdasarkan golongan pegawai
int get_gaji_pokok(char* golongan) {
    if (strcmp(golongan, "D1") == 0) return 2500000; // Gaji pokok golongan D1
    if (strcmp(golongan, "D2") == 0) return 2000000; // Gaji pokok golongan D2
    if (strcmp(golongan, "D3") == 0) return 1500000; // Gaji pokok golongan D3
    return 0; // Jika golongan tidak valid, gaji pokok 0
}

// Fungsi untuk mendapatkan upah lembur per jam berdasarkan golongan
int get_lembur_per_jam(char* golongan) {
    if (strcmp(golongan, "D1") == 0) return 10000;   // Upah lembur golongan D1
    if (strcmp(golongan, "D2") == 0) return 5000;    // Upah lembur golongan D2
    if (strcmp(golongan, "D3") == 0) return 2500;    // Upah lembur golongan D3
    return 0; // Jika golongan tidak valid, upah lembur 0
}

// Fungsi untuk mengubah huruf string menjadi huruf kapital
void to_upper(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]); // Ubah tiap karakter menjadi kapital
    }
}

// Fungsi untuk memformat nilai integer menjadi format rupiah (dengan titik)
void format_rupiah(int nilai, char *hasil) {
    snprintf(hasil, 20, "%d", nilai); // Mengubah nilai menjadi string
    int len = strlen(hasil);
    // Menambahkan tanda titik setiap tiga digit
    for (int i = len - 3; i > 0; i -= 3) {
        memmove(hasil + i + 1, hasil + i, strlen(hasil + i) + 1);
        hasil[i] = '.';
    }
}

// Fungsi untuk menampilkan data pegawai
void tampilkan_data_pegawai(struct Employee emp) {
    char gaji_formatted[20];
    format_rupiah(emp.gaji_pokok, gaji_formatted); // Format gaji pokok menjadi format rupiah
    
    // Menampilkan data pegawai
    printf("\nData Pegawai:\n");
    printf("NIP: %s\n", emp.nip);
    printf("Nama: %s\n", emp.nama);
    printf("Alamat: %s\n", emp.alamat);
    printf("No HP: %s\n", emp.no_hp);
    printf("Jabatan: %s\n", emp.jabatan);
    printf("Golongan: %s\n", emp.golongan);
    printf("Gaji Pokok: Rp%s\n", gaji_formatted);
}

// Fungsi untuk menambah pegawai baru
void tambah_pegawai() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("Maaf, kapasitas pegawai sudah penuh.\n");
        return;
    }
    
    struct Employee emp;
    // Meminta input data pegawai dari pengguna
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
    
    // Meminta input golongan dengan format yang disederhanakan
    int golongan_input;
    printf("Masukkan Golongan (D1/D2/D3): D");
    scanf("%d", &golongan_input);
    
    // Memastikan bahwa input valid (1, 2, atau 3)
    if (golongan_input >= 1 && golongan_input <= 3) {
        sprintf(emp.golongan, "D%d", golongan_input);  // Menggabungkan "D" dengan angka input
    } else {
        printf("Input golongan tidak valid. Harap masukkan 1, 2, atau 3.\n");
        return;
    }
    
    // Menghitung gaji pokok berdasarkan golongan
    emp.gaji_pokok = get_gaji_pokok(emp.golongan);
    
    // Menambahkan pegawai baru ke dalam array employees
    employees[employee_count++] = emp;
    
    // Menampilkan data pegawai yang baru ditambahkan
    tampilkan_data_pegawai(emp);
}


// Fungsi untuk menghitung gaji pegawai berdasarkan lembur
void hitung_gaji() {
    if (employee_count == 0) {
        printf("Belum ada data pegawai yang tersimpan.\n");
        return;
    }
    
    char nip[20];
    int jam_lembur;
    
    // Meminta input NIP dan jumlah jam lembur dari pengguna
    printf("Masukkan NIP pegawai: ");
    scanf("%s", nip);
    printf("Masukkan jumlah jam lembur: ");
    scanf("%d", &jam_lembur);
    
    struct Employee* emp = NULL;
    
    // Mencari pegawai berdasarkan NIP
    for (int i = 0; i < employee_count; i++) {
        if (strcmp(employees[i].nip, nip) == 0) {
            emp = &employees[i];
            break;
        }
    }
    
    if (emp == NULL) {
        printf("Pegawai dengan NIP %s tidak ditemukan.\n", nip);
        return;
    }
    
    // Menghitung gaji pokok dan total lembur
    int gaji_pokok = emp->gaji_pokok;
    int lembur_per_jam = get_lembur_per_jam(emp->golongan);
    int total_lembur = jam_lembur * lembur_per_jam;
    int total_gaji = gaji_pokok + total_lembur;

    // Variabel untuk menyimpan format gaji yang sudah diubah menjadi format Rupiah
    char gaji_pokok_formatted[20], total_lembur_formatted[20], total_gaji_formatted[20], lembur_per_jam_formatted[20];
    format_rupiah(gaji_pokok, gaji_pokok_formatted);         // Memformat gaji pokok
    format_rupiah(total_lembur, total_lembur_formatted);     // Memformat total lembur
    format_rupiah(total_gaji, total_gaji_formatted);         // Memformat total gaji
    format_rupiah(lembur_per_jam, lembur_per_jam_formatted); // Memformat lembur per jam

    // Menampilkan hasil perhitungan gaji dengan format Rupiah yang benar
    printf("\nHasil Perhitungan Gaji:\n");
    printf("NIP: %s\n", emp->nip);
    printf("Nama: %s\n", emp->nama);
    printf("Golongan: %s\n", emp->golongan);
    printf("Gaji Pokok: Rp%s\n", gaji_pokok_formatted);      // Gaji pokok diformat
    printf("Lembur: %d jam (Rp%s per jam)\n", jam_lembur, lembur_per_jam_formatted); // Lembur per jam diformat
    printf("Total Lembur: Rp%s\n", total_lembur_formatted);  // Total lembur diformat
    printf("Total Gaji Bulan ini: Rp%s\n", total_gaji_formatted);  // Total gaji diformat
}



// Fungsi untuk menampilkan semua data pegawai yang telah tersimpan
void tampilkan_semua_pegawai() {
    if (employee_count == 0) {
        printf("Belum ada data pegawai yang tersimpan.\n");
        return;
    }

    // Menampilkan data semua pegawai
    printf("\nDaftar Semua Pegawai:\n");
    for (int i = 0; i < employee_count; i++) {
        printf("Pegawai #%d\n", i + 1);  // Menampilkan nomor urut pegawai
        tampilkan_data_pegawai(employees[i]);  // Menampilkan data pegawai
        printf("----------------------------------------\n");  // Pembatas antar data pegawai
    }
}


// Fungsi utama yang menampilkan menu program
int main() {
    int pilihan;
    do {
        // Menampilkan menu pilihan
        printf("\nMenu:\n");
        printf("1. Tambah Pegawai\n");
        printf("2. Hitung Gaji\n");
        printf("3. Tampilkan Semua Pegawai\n");
        printf("4. Keluar\n");
        printf("Pilih menu (1-4): ");
        scanf("%d", &pilihan);

        // Menjalankan fungsi berdasarkan pilihan menu
        switch (pilihan) {
            case 1:
                tambah_pegawai();
                break;
            case 2:
                hitung_gaji();
                break;
            case 3:
                tampilkan_semua_pegawai();
                break;
            case 4:
                printf("Terima kasih, program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 4);

    return 0;
}
