public class Elang extends Animal {
    private int basePower;
    private int jumlahTelur;

    public Elang(int basePower) {
        super(2);
        this.basePower = basePower;
        this.jumlahTelur = 0; 
    }

    public int getJumlahTelur() {
        return jumlahTelur;
    }

    public void bertelur() {
        this.jumlahTelur++;
    }

    public int getAnimalPower() {
        return basePower * getNumberOfChildren() - getJumlahTelur();
    }
}
