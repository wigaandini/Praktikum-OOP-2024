package Belanja;

public class DaftarBelanja {
    private Barang[] listBelanja;
    private int idx;

    public DaftarBelanja(int max) {
        listBelanja = new Barang[max];
        idx = 0;
    }

    public void belanja(int lorong, String keterangan) {
        belanja(lorong, 1, keterangan);
    }

    public void belanja(int lorong, int quantity, String keterangan) {
        if (idx < listBelanja.length) {
            String nama = keterangan + " (lorong " + lorong + ")";
            Barang b = new Barang(nama, quantity);
            listBelanja[idx] = b;
            idx++;
        }
    }

    public void belanja(String barang) {
        belanja(barang, 1);
    }

    public void belanja(String barang, int quantity) {
        if (idx < listBelanja.length) {
            Barang b = new Barang(barang, quantity);
            listBelanja[idx] = b;
            idx++;
        }
    }

    public void print() {
        for (int i = 0; i < idx; i++) {
            System.out.println(i+1 + ". " + (listBelanja[i].toString()));
        }
    }
}
