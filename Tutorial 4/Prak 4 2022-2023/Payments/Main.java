package Payments;

public class Main {
    public static void main(String[] args) {
        CreditCard cc = new CreditCard();
        DebitCard dc = new DebitCard();
        cc.pay(1000);
        dc.deposit(1000);
        cc.endBillingCycle();
        cc.applyInterest();
        System.out.println("Credit Card Balance: " + cc.getUnpaidBalance());
        System.out.println("Debit Card Balance: " + dc.balance);
    }
}
