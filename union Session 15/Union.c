#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[50];
    long nim;  // Mengubah tipe data menjadi long untuk menampung NIM yang lebih besar
    float ipk;
};

void tampilkanMahasiswa(struct Mahasiswa mhs) {
    printf("Nama: %s\n", mhs.nama);
    printf("NIM: %ld\n", mhs.nim);  // Menggunakan %ld untuk mencetak long
    printf("IPK: %.2f\n", mhs.ipk);
}

int main() {
    struct Mahasiswa mhs1, mhs2;

    // Mengisi data mahasiswa 1
    strcpy(mhs1.nama, "Zacharia Ananta Wijaya");
    mhs1.nim = 2802547452;
    mhs1.ipk = 3.75;

    // Mengisi data mahasiswa 2
    strcpy(mhs2.nama, "Kachen Chaney");
    mhs2.nim = 2802547452;
    mhs2.ipk = 4.00;

    // Menampilkan data mahasiswa
    printf("Data Mahasiswa 1:\n");
    tampilkanMahasiswa(mhs1);

    printf("\nData Mahasiswa 2:\n");
    tampilkanMahasiswa(mhs2);

    // Menghitung dan menampilkan rata-rata IPK
    float rataRataIPK = (mhs1.ipk + mhs2.ipk) / 2;
    printf("\nRata-rata IPK: %.2f\n", rataRataIPK);

    printf("\nUkuran struct Mahasiswa: %lu bytes\n", sizeof(struct Mahasiswa));

    return 0;
}


1. Penjelasan Program:

Program ini adalah contoh penggunaan struktur (struct) dalam bahasa C untuk menyimpan dan menampilkan data mahasiswa. 

- Program mendefinisikan struktur `Mahasiswa` yang memiliki tiga anggota: `nama` (array karakter), `nim` (long integer), dan `ipk` (float).
- Fungsi `tampilkanMahasiswa()` digunakan untuk mencetak data mahasiswa.
- Di dalam `main()`, program membuat dua variabel bertipe `struct Mahasiswa`: `mhs1` dan `mhs2`.
- Data untuk kedua mahasiswa diisi menggunakan `strcpy()` untuk nama dan assignment langsung untuk NIM dan IPK.
- Program kemudian menampilkan data kedua mahasiswa, menghitung rata-rata IPK, dan mencetak ukuran dari struct Mahasiswa.

2. Output Program:

output dari program ini:

```
Data Mahasiswa 1:
Nama: Zacharia Ananta Wijaya
NIM: 2802547452
IPK: 3.75

Data Mahasiswa 2:
Nama: Kachen Chaney
NIM: 2802547452
IPK: 4.00

Rata-rata IPK: 3.88

Ukuran struct Mahasiswa: 64 bytes
```

3. Analisis:

a) Penggunaan Struct:
   - Struct digunakan dengan baik untuk mengelompokkan data terkait (nama, NIM, IPK) menjadi satu entitas.
   - Ini memudahkan pengelolaan dan pengorganisasian data mahasiswa.

b) Tipe Data:
   - Penggunaan `long` untuk NIM adalah pilihan yang baik karena memungkinkan penyimpanan angka yang lebih besar dibandingkan dengan `int`.
   - `float` digunakan untuk IPK, yang cukup untuk keperluan ini.

c) Fungsi:
   - Fungsi `tampilkanMahasiswa()` meningkatkan modularitas kode dan mengurangi pengulangan.

d) Pengisian Data:
   - `strcpy()` digunakan dengan benar untuk mengisi string nama.
   - Assignment langsung digunakan untuk NIM dan IPK, yang efisien.

e) Perhitungan:
   - Rata-rata IPK dihitung dengan benar.

f) Ukuran Struct:
   - Program mencetak ukuran struct, yang berguna untuk memahami penggunaan memori.

g) Potensi Perbaikan:
   - NIM kedua mahasiswa sama (2802547452). Ini mungkin kesalahan atau disengaja, tetapi perlu diperhatikan.
   - Program bisa ditingkatkan dengan menambahkan input dari pengguna atau membaca dari file.
   - Validasi input (misalnya untuk IPK) bisa ditambahkan untuk meningkatkan keandalan.

h) Keamanan:
   - Penggunaan `strcpy()` aman dalam contoh ini, tetapi bisa menjadi risiko keamanan jika digunakan dengan input yang tidak terkontrol.

i) Efisiensi:
   - Program ini efisien untuk tugasnya yang sederhana. Untuk data mahasiswa dalam jumlah besar, struktur data yang lebih kompleks seperti array atau linked list mungkin lebih sesuai.

