# Sistem Manajemen Produk

Ini adalah sistem manajemen produk sederhana yang ditulis dalam bahasa C yang memungkinkan pengguna untuk menambahkan dan melihat informasi produk. Program ini menggunakan array of structures untuk menyimpan data produk, seperti nama produk, harga, dan jumlah stok.

## Fitur

- **Tambah Produk**: Pengguna dapat menambahkan produk baru dengan detail seperti nama, harga, dan jumlah stok. Nama produk dapat berisi spasi.
- **Tampilkan Semua Produk**: Pengguna dapat melihat daftar semua produk yang telah ditambahkan, termasuk nama, harga, dan jumlah stoknya.
- **Keluar Program**: Pengguna dapat memilih untuk keluar dari program kapan saja.

## Opsi Menu

Program ini menyajikan opsi menu berikut:

1. **Tambah Produk**: Memungkinkan pengguna untuk memasukkan detail produk. Pengguna dapat memasukkan beberapa produk hingga kapasitas maksimum (100 produk) tercapai.
2. **Tampilkan Semua Produk**: Menampilkan detail semua produk yang telah ditambahkan.
3. **Keluar**: Mengakhiri program.

## Contoh

```
Menu:
1. Tambah Produk
2. Tampilkan Semua Produk
3. Keluar
Pilihan: 1

Masukkan data produk:
Nama: Teh Manis
Harga: 5000
Stok: 20

Produk berhasil ditambahkan.
```

## Penjelasan Kode

- Program ini menggunakan `struct` bernama `Produk` untuk menyimpan informasi tentang setiap produk.
- Data produk mencakup:
  - `nama`: Nama produk (maksimal 50 karakter).
  - `harga`: Harga produk (float).
  - `stok`: Jumlah stok produk (integer).
- Fungsi yang digunakan dalam program:
  - `tambahProduk()`: Menambahkan produk baru ke dalam daftar.
  - `tampilkanSemuaProduk()`: Menampilkan semua produk dalam daftar.

