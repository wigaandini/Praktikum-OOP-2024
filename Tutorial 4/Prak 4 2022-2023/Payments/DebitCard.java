package Payments;

public class DebitCard implements IPaymentMethod{
    double balance;

    public DebitCard() {
        this.balance = 0;
    }

    public boolean deposit(double amount) {
        this.balance += amount;
        return true;
    }

    public boolean withdraw(double amount) {
        if (this.balance >= amount) {
            this.balance -= amount;
            return true;
        } 
        else {
            return false;
        }
    }

    public boolean pay(double price) {
        if (this.balance >= price) {
            this.balance -= price;
            return true;
        } 
        else {
            return false;
        }
    }
}