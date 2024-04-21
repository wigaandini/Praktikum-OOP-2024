// Erdianti Wiga Putri Andini
// 13522053


// package Hero; /* Pas kumpulin jangan lupa apus package biar ga compile error */

public class Agility extends Hero {
    public Agility() {
        super();
    }

    public Agility(int level) {
        super(level);
    }

    public void printInfo() {
        System.out.println("Agility Hero (Lvl " + getLevel() + ")");
    }

    public Double value() {
        return (getLevel() + 9.5);
    }
}
