// Erdianti Wiga Putri Andini
// 13522053

import java.util.ArrayList;

public class Service {
    private String servicePhone;
    private String serviceName;
    private String serviceEmail;
    private IMessageSender messageSender;
    private ArrayList<User> users;


    public Service(String serviceName, String serviceEmail, String servicePhone) {
        // Inisialisasi service dengan serviceName, serviceEmail, dan servicePhone, users diinisialisasi dengan list kosong
        this.serviceName = serviceName;
        this.serviceEmail = serviceEmail;
        this.servicePhone = servicePhone;
        this.users = new ArrayList<User>();
    }

    public void addUser(User user) {
        this.users.add(user);

    }

    public void sendMessage(String message) {
        // Kirim pesan ke semua user dengan isi pesan message
        // Panggil method sendMessage dari messageSender
        // Cek apakah user memiliki email, jika ada kirim email, dst. Email, device, phone yang kosong tidak perlu dikirim. Data yang kosong ditandai dengan ""
        for (User u : users) {
            if (u.getEmail() != "") {
                this.messageSender = new EmailMessageSender(serviceEmail);
                messageSender.sendMessage(u, message);
            }
            if (u.getDevice() != "") {
                this.messageSender = new PushNotifMessageSender(serviceName);
                messageSender.sendMessage(u, message);
            }
            if (u.getPhone() != "") {
                this.messageSender = new SMSMessageSender(servicePhone); 
                messageSender.sendMessage(u, message);
            }
        }
    }
}
