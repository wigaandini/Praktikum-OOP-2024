// Erdianti Wiga Putri Andini
// 13522053


// package Hero; /* Pas kumpulin jangan lupa apus package biar ga compile error */

public class Intelligence extends Hero {
    public Intelligence() {
        super();
    }

    public Intelligence(int level) {
        super(level);
    }

    public void printInfo() {
        System.out.println("Intelligence Hero (Lvl " + getLevel() + ")");
    }

    public Double value() {
        return (getLevel() + 1.5);
    }
}
