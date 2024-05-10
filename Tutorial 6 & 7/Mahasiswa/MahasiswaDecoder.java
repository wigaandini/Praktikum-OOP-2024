import java.lang.reflect.*;

public class MahasiswaDecoder {
    private Mahasiswa mahasiswa;
    
    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Method addMatkul = this.mahasiswa.getClass().getDeclaredMethod("addMatkul", String.class);
        addMatkul.setAccessible(true);
        addMatkul.invoke(this.mahasiswa, name);
    }

    public int getNIM() throws Exception {
        Field nim = this.mahasiswa.getClass().getDeclaredField("NIM");
        nim.setAccessible(true);
        return (int) nim.get(this.mahasiswa);
    }

    public double getIPK() throws Exception {
        Field ipk = this.mahasiswa.getClass().getDeclaredField("IPK");
        ipk.setAccessible(true);
        return (double) ipk.get(this.mahasiswa);
    }
}