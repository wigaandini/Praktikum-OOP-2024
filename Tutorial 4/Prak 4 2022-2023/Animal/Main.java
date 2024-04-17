public class Main {
    public static void main(String[] args) {
        Gajah gajah = new Gajah(10, 5);
        Elang elang = new Elang(5);
        gajah.increaseChild(2);
        elang.increaseChild(15);
        elang.bertelur();
        elang.bertelur();
        elang.bertelur();
        System.out.println("Power gajah: " + gajah.getAnimalPower());
        System.out.println("Power elang: " + elang.getAnimalPower());
        System.out.println(gajah.compareTo(elang));
    }
}

// javac (nama folder)\*.java
// java Main