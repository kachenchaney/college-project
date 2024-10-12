# Sistem Manajemen Pegawai

Proyek ini adalah Sistem Manajemen Pegawai sederhana yang ditulis dalam bahasa C. Program ini memungkinkan pengguna untuk menambahkan data pegawai, menghitung gaji, dan menampilkan informasi semua pegawai. Program ini mencakup fitur untuk mengelola informasi pegawai seperti NIP, nama, alamat, nomor telepon, jabatan, dan detail gaji berdasarkan golongan pegawai.

## Fitur
1. **Tambah Pegawai**: Menambahkan informasi pegawai baru seperti NIP, nama, alamat, nomor telepon, jabatan, dan golongan. Gaji ditentukan berdasarkan golongan pegawai.
2. **Hitung Gaji**: Menghitung total gaji seorang pegawai, termasuk upah lembur.
3. **Tampilkan Semua Pegawai**: Menampilkan detail semua pegawai dalam sistem.
4. **Keluar Program**: Mengakhiri program.

## Cara Menggunakan
Setelah menjalankan program, Anda akan disajikan dengan menu yang memungkinkan Anda memilih antara opsi yang tersedia:

- **1. Tambah Pegawai**: Anda dapat memasukkan detail pegawai baru. Sistem akan secara otomatis menghitung gaji pokok berdasarkan golongan yang dimasukkan.
- **2. Hitung Gaji**: Menghitung gaji seorang pegawai berdasarkan NIP dan jumlah jam lembur yang telah dikerjakan.
- **3. Tampilkan Semua Pegawai**: Menampilkan semua data pegawai yang telah ditambahkan ke sistem.
- **4. Keluar**: Keluar dari program.

## Contoh Output
Berikut adalah beberapa contoh output yang menunjukkan fungsionalitas program.

### 1. Tambah Pegawai
```
Masukkan NIP: 123456
Masukkan Nama: Budi Santoso
Masukkan Alamat: Jl. Mawar No. 10, Jakarta
Masukkan No HP: 081234567890
Masukkan Jabatan: Manager
Masukkan Golongan (D1/D2/D3): D1

Data Pegawai:
NIP: 123456
Nama: Budi Santoso
Alamat: Jl. Mawar No. 10, Jakarta
No HP: 081234567890
Jabatan: Manager
Golongan: D1
Gaji Pokok: Rp2.500.000
```

### 2. Hitung Gaji
```
Masukkan NIP pegawai: 123456
Masukkan jumlah jam lembur: 5

Hasil Perhitungan Gaji:
NIP: 123456
Nama: Budi Santoso
Golongan: D1
Gaji Pokok: Rp2.500.000
Lembur: 5 jam (Rp10.000 per jam)
Total Lembur: Rp50.000
Total Gaji Bulan ini: Rp2.550.000
```

### 3. Tampilkan Semua Pegawai
```
Daftar Semua Pegawai:
Pegawai #1
Data Pegawai:
NIP: 123456
Nama: Budi Santoso
Alamat: Jl. Mawar No. 10, Jakarta
No HP: 081234567890
Jabatan: Manager
Golongan: D1
Gaji Pokok: Rp2.500.000
----------------------------------------
Pegawai #2
Data Pegawai:
NIP: 654321
Nama: Siti Aisyah
Alamat: Jl. Melati No. 15, Bandung
No HP: 082112345678
Jabatan: Supervisor
Golongan: D2
Gaji Pokok: Rp2.000.000
----------------------------------------
```

### 4. Keluar Program
```
Terima kasih, program selesai.
```

## Cara Kompilasi dan Menjalankan
Untuk mengompilasi program, gunakan perintah berikut:
```
gcc employee_management.c -o employee_management
```

Untuk menjalankan program yang telah dikompilasi:
```
./employee_management
```

---
Silakan gunakan, modifikasi, dan tingkatkan proyek ini. Setiap masukan sangat dihargai!
