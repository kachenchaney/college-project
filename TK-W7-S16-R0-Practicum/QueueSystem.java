import java.util.LinkedList;

public class QueueSystem {
    // LinkedList untuk menyimpan antrean pelanggan (FIFO)
    private LinkedList<String> queue;

    // Konstruktor: inisialisasi antrean kosong
    public QueueSystem() {
        this.queue = new LinkedList<>();
    }

    // Menambah pelanggan baru ke akhir antrean
    public void addCustomer(String customerName) {
        queue.addLast(customerName);
    }

    // Melayani pelanggan di depan antrean (menghapusnya dari antrean)
    // Mengembalikan nama pelanggan yang dilayani, atau null jika antrean kosong
    public String serveCustomer() {
        if (queue.isEmpty()) {
            return null;
        }
        return queue.removeFirst();
    }

    // Menampilkan daftar pelanggan dalam antrean saat ini
    public void displayQueue() {
        System.out.println("Daftar antrean saat ini: " + queue.toString());
    }
}
