// Erdianti Wiga Putri A
// 13522053

import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah> {
    private float rating;
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;

    public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating) {
        this.nama = nama;
        this.kodeJurusan = kodeJurusan;
        this.tahunPengambilan = tahunPengambilan;
        this.rating = rating;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public int getKodeJurusan() {
        return kodeJurusan;
    }

    public void setKodeJurusan(int kodeJurusan) {
        this.kodeJurusan = kodeJurusan;
    }

    public int getTahunPengambilan() {
        return tahunPengambilan;
    }

    public void setTahunPengambilan(int tahunPengambilan) {
        this.tahunPengambilan = tahunPengambilan;
    }

    public float getRating() {
        return rating;
    }

    public void setRating(float rating) {
        this.rating = rating;
    }

    public int compareTo(MataKuliah m) {
        // MataKuliah A disebut kurang dari MataKuliah B bila:
        // kode jurusan MataKuliah A lebih kecil dari MataKuliah B
        // kode jurusan MataKuliah A sama dengan MataKuliah B, tapi tahun pengambilannya lebih kecil
        // kode jurusan dan tahun pengambilan MataKuliah A sama dengan MataKuliah B, tapi rating nya lebih kecil
        if (this.kodeJurusan < m.kodeJurusan) {
            return -1;
        } 
        else if (this.kodeJurusan == m.kodeJurusan) {
            if (this.tahunPengambilan < m.tahunPengambilan) {
                return -1;
            } 
            else if (this.tahunPengambilan == m.tahunPengambilan) {
                if (this.rating < m.rating) {
                    return -1;
                } 
                else if (this.rating == m.rating) {
                    return 0;
                } 
                else {
                    return 1;
                }
            } 
            else {
                return 1;
            }
        } 
        else {
            return 1;
        }
    }
}