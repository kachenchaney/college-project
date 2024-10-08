1. Penjelasan program:
- Program ini menggunakan `typedef` untuk membuat alias untuk sebuah struct bernama `Mahasiswa`.
- Struct `Mahasiswa` memiliki empat anggota: `nama`, `umur`, `universitas`, dan `jurusan`.
- Di dalam `main()`, kita membuat variabel `mhs` dengan tipe `Mahasiswa`.
- Program mengisi data mahasiswa langsung dalam kode, tanpa meminta input dari pengguna.
- Kemudian, program menampilkan semua data mahasiswa yang telah diisi.

2. Output program:
Ketika dijalankan, program akan menampilkan output seperti ini:

Data Mahasiswa:
Nama: Zacharia Ananta Wijaya
Umur: 19 tahun
Universitas: Binus University
Jurusan: Computer Science


3. Analisa:
- Penggunaan `typedef` membuat kode lebih mudah dibaca dan dipelihara. Kita bisa langsung menulis `Mahasiswa mhs;` alih-alih `struct Mahasiswa mhs;`.
- `typedef` memungkinkan kita untuk memberi nama yang lebih deskriptif dan sesuai konteks untuk tipe data kompleks seperti struct.
- Dalam contoh ini, `Mahasiswa` menjadi tipe data baru yang bisa digunakan seperti tipe data bawaan lainnya.
- Struktur `Mahasiswa` sekarang mencakup lebih banyak informasi, menunjukkan fleksibilitas struct dalam mengelompokkan data terkait.
- Penggunaan `strcpy()` diperlukan untuk menyalin string ke dalam array char dalam struct. Ini adalah cara yang aman untuk menginisialisasi string dalam C.
- Program ini mendemonstrasikan bagaimana `typedef` dapat digunakan untuk membuat tipe data kustom yang mencerminkan entitas dunia nyata (dalam hal ini, seorang mahasiswa).
