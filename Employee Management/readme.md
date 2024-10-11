# Employee Management System

## Deskripsi
Program ini adalah sistem manajemen pegawai sederhana yang dibuat menggunakan bahasa pemrograman C. Aplikasi ini memungkinkan pengguna untuk menambah data pegawai, menghitung gaji pegawai, menghitung kupon dan diskon, serta menampilkan semua data pegawai yang tersimpan. Program ini cocok digunakan sebagai latihan dasar dalam membuat aplikasi berbasis teks yang melibatkan operasi data, input, dan output.

## Fitur
1. **Tambah Pegawai**: Menambahkan data pegawai baru, seperti NIP, nama, alamat, nomor HP, jabatan, dan golongan. Gaji pokok akan dihitung berdasarkan golongan yang dipilih.
2. **Hitung Gaji**: Menghitung total gaji pegawai berdasarkan gaji pokok dan jumlah jam lembur. Setiap golongan memiliki tarif lembur yang berbeda. Sistem akan mencari data pegawai berdasarkan NIP untuk menghindari input ulang data golongan yang dapat menyebabkan kesalahan.
3. **Hitung Kupon dan Diskon**: Menghitung jumlah kupon dan diskon yang didapatkan berdasarkan total pembelian. Kupon undian diberikan untuk setiap kelipatan Rp100.000 dan diskon 5% hanya diberikan jika total pembelian lebih dari atau sama dengan Rp100.000.
4. **Tampilkan Semua Pegawai**: Menampilkan seluruh data pegawai yang tersimpan di sistem.
5. **Keluar**: Mengakhiri program.

## Struktur Data
Program ini menggunakan struktur data `struct Employee` untuk menyimpan informasi pegawai, yang terdiri dari:
- **nip**: Nomor Induk Pegawai
- **nama**: Nama pegawai
- **alamat**: Alamat pegawai
- **no_hp**: Nomor handphone pegawai
- **jabatan**: Jabatan pegawai
- **golongan**: Golongan pegawai (D1, D2, D3)
- **gaji_pokok**: Gaji pokok pegawai berdasarkan golongan

## Fungsi Utama
1. `tambah_pegawai()`: Menambahkan data pegawai baru.
2. `hitung_gaji()`: Menghitung gaji pegawai berdasarkan golongan dan jumlah jam lembur. Sistem mencari data pegawai berdasarkan NIP untuk memastikan informasi yang akurat.
3. `hitung_kupon(int total_pembelian)`: Menghitung jumlah kupon berdasarkan total pembelian.
4. `hitung_diskon(int total_pembelian)`: Menghitung diskon berdasarkan total pembelian.
5. `tampilkan_semua_pegawai()`: Menampilkan semua data pegawai yang tersimpan.

## Contoh Penggunaan
- Untuk menambah pegawai, pilih menu **1** dan masukkan informasi pegawai seperti NIP, nama, alamat, nomor HP, jabatan, dan golongan.
- Untuk menghitung gaji, pilih menu **2** dan masukkan NIP dan jumlah jam lembur pegawai. Sistem akan otomatis mengambil informasi golongan dan gaji pokok dari data pegawai yang tersimpan.
- Untuk menghitung kupon dan diskon dari total pembelian, pilih menu **3** dan masukkan total pembelian.
- Untuk menampilkan semua data pegawai, pilih menu **4**.

## Contoh Output
### Menu 1: Tambah Pegawai
```
Masukkan NIP: 12345
Masukkan Nama: Budi Santoso
Masukkan Alamat: Jalan Merdeka No. 10
Masukkan No HP: 081234567890
Masukkan Jabatan: Supervisor
Masukkan Golongan (D1/D2/D3): D1

Data Pegawai:
NIP: 12345
Nama: Budi Santoso
Alamat: Jalan Merdeka No. 10
No HP: 081234567890
Jabatan: Supervisor
Golongan: D1
Gaji Pokok: Rp2500000
```

### Menu 2: Hitung Gaji
```
Masukkan NIP: 12345
Masukkan Golongan (D1/D2/D3): D1
Masukkan Jumlah Jam Lembur: 10

Hasil Perhitungan Gaji:
NIP: 12345
Golongan: D1
Lembur: 10 jam
Total Gaji Bulan ini: Rp2600000
```

### Menu 3: Hitung Kupon dan Diskon
```
Masukkan total pembelian: Rp250000
Jumlah kupon: 2
Diskon: Rp12500.00
Total bayar: Rp237500.00
```

### Menu 4: Tampilkan Semua Pegawai
```
Daftar Semua Pegawai:
---------------------------------------
Pegawai #1
NIP: 12345
Nama: Budi Santoso
Alamat: Jalan Merdeka No. 10
No HP: 081234567890
Jabatan: Supervisor
Golongan: D1
Gaji Pokok: Rp2500000
---------------------------------------
```

### Menu 5: Keluar
```
Terima kasih, program selesai.
```

## Batasan
- Program ini hanya dapat menyimpan hingga **100 pegawai**.
- Golongan pegawai yang tersedia adalah **D1**, **D2**, dan **D3**.
- Sistem belum memiliki mekanisme penyimpanan data permanen; semua data akan hilang setelah program ditutup.

## Catatan
- Pastikan untuk memasukkan data dengan benar untuk menghindari kesalahan perhitungan gaji.
- Program ini dibuat untuk keperluan belajar dan pengembangan lebih lanjut.
