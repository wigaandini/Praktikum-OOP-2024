// Erdianti Wiga Putri Andini
// 13522053

import java.util.ArrayList;

public class NotificationManager {
    private ArrayList<Service> services;

    public NotificationManager(ArrayList<Service> services) {
        this.services = new ArrayList<Service>();
    }

    public void addService(Service service) {
        // Tambahkan service ke dalam ArrayList services
        this.services.add(service);
    }

    public ArrayList<Service> getServices() {
        // Mengembalikan ArrayList services
        return services;
    }

    public void removeService(Service service) {
        // Hapus service dari dalam ArrayList services
        this.services.remove(service);
    }

    public void notifyService(String message) {
        // Kirim pesan ke user dengan isi pesan message
        for (Service s: services) {
            s.sendMessage(message);
        }
    }
}
