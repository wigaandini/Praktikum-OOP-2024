package Belanja;

public class Main {
    public static void main(String[] args) {
        DaftarBelanja db = new DaftarBelanja(10);
        db.belanja("Beras", 2);
        db.belanja("Gula", 1);
        db.belanja(3, 7, "Susu");
        db.belanja(10, "Sabun harus lifebuoy");
        db.belanja("Kinderjoy", 100);
        db.belanja("Air putih");
        db.print();
    }
}
