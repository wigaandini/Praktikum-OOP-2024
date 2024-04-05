// Erdianti Wiga Putri A
// 13522053

class Kompleks {
    private static int n_kompleks = 0;
    private int real;
    private int imaginer;

    // ctor tanpa parameter
    // inisialisasi seluruh koefisien dengan nilai 0
    public Kompleks() {
        real = 0;
        imaginer = 0;
        n_kompleks++;
    }

    // ctor dengan parameter
    public Kompleks(int real, int imaginer) {
        this.real = real;
        this.imaginer = imaginer;
        n_kompleks++;
    }
    
    //mengembalikan bagian riil
    public int getReal() {
        return real;
    }

    // mengembalikan bagian imaginer
    public int getImaginer() {
        return imaginer;
    }

    // mengisi bagian riil
    public void setReal(int r) {
        this.real = r;
    }

    // mengisi bagian imaginer
    public void setImaginer(int i) {
        this.imaginer = i;
    }

    // operator overloading

    // operator+ untuk melakukan penjumlahan dengan rumus berikut
    public Kompleks plus(Kompleks b) {
        return new Kompleks(this.real + b.real, this.imaginer + b.imaginer);
    }

    // operator- untuk melakukan pengurangan dengan rumus berikut
    public Kompleks minus(Kompleks b) {
        return new Kompleks(this.real - b.real, this.imaginer - b.imaginer);
    }
    
    // operator* untuk melakukan perkalian dengan rumus berikut
    public Kompleks multiply(Kompleks b) {
        return new Kompleks(this.real * b.real - this.imaginer * b.imaginer, this.imaginer * b.real + this.real * b.imaginer);
    }
    
    // operator* untuk mengkalikan bilangan kompleks dengan konstanta
    public Kompleks multiply(int k) {
        return new Kompleks(this.real * k, this.imaginer * k);
    }

    // mengembalikan jumlah instance yang pernah dibuat
    public static int countKompleksInstance() {
        return n_kompleks;
    }

    // mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line 
    // contoh:
    // 3+5i
    // 0
    // 3i
    // -3
    // -5-4i
    public void print() {
        if (real == 0 && imaginer == 0) {
            System.out.println(0);
        } 
        else if (real == 0) {
            System.out.println(imaginer + "i");
        } 
        else if (imaginer == 0) {
            System.out.println(real);
        } 
        else if (imaginer > 0) {
            System.out.println(real + "+" + imaginer + "i");
        } 
        else {
            System.out.println(real + "" + imaginer + "i");
        }
    }
}