// Erdianti Wiga Putri Andini
// 13522053


// package Hero; /* Pas kumpulin jangan lupa apus package biar ga compile error */

public class Strength extends Hero {
    public Strength() {
        super();
    }

    public Strength(int level) {
        super(level);
    }

    public void printInfo() {
        System.out.println("Strength Hero (Lvl " + getLevel() + ")");
    }

    public Double value() {
        return (getLevel() + 5.5);
    }
}
