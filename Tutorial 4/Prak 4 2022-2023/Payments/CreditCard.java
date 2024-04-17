package Payments;

public class CreditCard implements IPaymentMethod {
    public static final double defaultLimit = 2500;
    public static final double defaultInterest = 0.0005;

    private double monthlyBalance;
    private double monthlyLimit;
    private double unpaidBalance;
    private double dailyInterest;

    public CreditCard() {
        this.monthlyBalance = 0;
        this.monthlyLimit = defaultLimit;
        this.unpaidBalance = 0;
        this.dailyInterest = defaultInterest;
    }

    public CreditCard(double limit, double interest) {
        this.monthlyBalance = 0;
        this.monthlyLimit = limit;
        this.unpaidBalance = 0;
        this.dailyInterest = interest;
    }

    public double getMonthlyBalance() {
        return monthlyBalance;
    }

    public double getMonthlyLimit() {
        return monthlyLimit;
    }

    public double getUnpaidBalance() {
        return unpaidBalance;
    }

    public double getDailyInterest() {
        return dailyInterest;
    }

    public void endBillingCycle() {
        this.unpaidBalance += this.monthlyBalance;
        this.monthlyBalance = 0;
    }

    public void applyInterest() {
        this.unpaidBalance += (this.unpaidBalance * this.dailyInterest);
    }

    public boolean pay(double price) {
        if (monthlyBalance + price > monthlyLimit) {
            return false;
        }
        else {
            monthlyBalance += price;
            return true;
        }
    }

    public boolean payOffBalance(double amount) {
        if (amount > monthlyBalance + unpaidBalance) {
            return false;
        }
        if (amount <= monthlyBalance) {
            monthlyBalance -= amount;
        }
        else {
            amount -= monthlyBalance;
            monthlyBalance = 0;
            unpaidBalance -= amount;
        }
        return true;
    }
}