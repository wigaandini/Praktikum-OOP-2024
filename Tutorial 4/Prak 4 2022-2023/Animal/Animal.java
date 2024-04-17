public abstract class Animal implements Comparable<Animal> {
    public int numberOfLegs;
    public int children = 0;

    public Animal(int legs) {
        numberOfLegs = legs;
    }

    public int getNumberOfLegs() {
        return numberOfLegs;
    }

    public int getNumberOfChildren() {
        return children;
    }

    public void increaseChild(int inc) {
        children += inc;
    }

    public abstract int getAnimalPower();

    public int compareTo(Animal a) {
        if (this.getAnimalPower() > a.getAnimalPower()) {
            return 1;
        } else if (this.getAnimalPower() < a.getAnimalPower()) {
            return -1;
        } else {
            return 0;
        }
    }
}

// interface Comparable {
//     public int getNumberOfLegs();
//     public int getNumberOfChildren();
//     public void increaseChild(int inc);
//     public int compareTo(Animal a);
// }