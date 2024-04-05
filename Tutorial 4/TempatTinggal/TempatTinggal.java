// Erdianti Wiga Putri A
// 13522053

class TempatTinggal {
    private int luas;
    private double hargaBahanBangunan;

    public TempatTinggal(int luas, double hargaBahanBangunan) {
        this.luas = luas;
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public int getLuas() {
        return luas;
    }

    public void setLuas(int luas) {
        this.luas = luas;
    }

    public double getHargaBahanBangunan() {
        return hargaBahanBangunan;
    }

    public void setHargaBahanBangunan(double hargaBahanBangunan) {
        this.hargaBahanBangunan = hargaBahanBangunan;
    }    

    public double hitungBiayaBangun() {
        return luas * hargaBahanBangunan;
    }
}


class Rumah extends TempatTinggal {
    public Rumah(int luas, double hargaBahanBangunan) {
        super(luas, hargaBahanBangunan);
    }

    public Rumah(int lebar, int panjang, double hargaBahanBangunan) {
        super(lebar * panjang, hargaBahanBangunan);
    }

    public void setLuas(int lebar, int panjang) {
        super.setLuas(lebar * panjang);
    }

    public double hitungBiayaBangun(double biayaOrmas) {
        return super.hitungBiayaBangun() + biayaOrmas;
    }
}


interface Kendaraan {
    public double hitungJarakTempuh();
}


class Karavan extends Rumah implements Kendaraan {
    private float bensin;
    private float pemakaianBensin;

    public Karavan(){
        super(0,0);
        this.setBensin(0);
        this.setPemakaianBensin(0);
    }

    public float getBensin(){
        return this.bensin;
    }

    public void setBensin(float bensin){
        this.bensin = bensin;
    }

    public float getPemakaianBensin(){
        return this.pemakaianBensin;
    }

    public void setPemakaianBensin(float pemakaianBensin){
        this.pemakaianBensin = pemakaianBensin;
    }

    public double hitungBiayaBangun() {
        return super.hitungBiayaBangun() * 3;
    }

    public double hitungJarakTempuh() {
        return bensin * pemakaianBensin;
    }
}