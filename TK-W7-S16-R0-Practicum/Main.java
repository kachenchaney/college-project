public class Main {
    public static void main(String[] args) {
        // Buat instance sistem antrean
        QueueSystem queueSystem = new QueueSystem();

        long startTime, endTime, duration;

        // 1. Tambah beberapa pelanggan ke dalam antrean
        String[] newCustomers = {"Zacha", "Pricella", "Mia"};
        for (String name : newCustomers) {
            System.out.println("Menambahkan pelanggan baru: " + name);
            startTime = System.nanoTime();             // waktu mulai
            queueSystem.addCustomer(name);
            endTime = System.nanoTime();               // waktu selesai
            duration = endTime - startTime;            // selisih waktu (ns)
            System.out.println("Waktu eksekusi penambahan: " + duration + " ns");
            queueSystem.displayQueue();                // tampilkan antrean setelah penambahan
            System.out.println(); // baris kosong untuk kejelasan output
        }

        // 2. Layani beberapa pelanggan dari antrean
        int jumlahPelayanan = 2;  // misal layani 2 pelanggan terlebih dahulu
        for (int i = 0; i < jumlahPelayanan; i++) {
            System.out.println("Melayani pelanggan...");
            startTime = System.nanoTime();             // waktu mulai
            String servedCustomer = queueSystem.serveCustomer();
            endTime = System.nanoTime();               // waktu selesai
            duration = endTime - startTime;            // selisih waktu (ns)
            System.out.println("Waktu eksekusi pelayanan: " + duration + " ns");
            if (servedCustomer != null) {
                System.out.println("Pelanggan yang dilayani: " + servedCustomer);
            } else {
                System.out.println("Tidak ada pelanggan yang dilayani (antrean kosong).");
            }
            queueSystem.displayQueue();                // tampilkan antrean setelah pelayanan
            System.out.println();
        }
    }
}
