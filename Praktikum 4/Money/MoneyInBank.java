// Erdianti Wiga Putri Andini
// 13522053


// package Money; /* Pas kumpulin jangan lupa apus package biar ga compile error */

import java.lang.Math;

public class MoneyInBank implements MoneyTransaction{
    private int amount;
    private int interestRate;
    private int totalLoanAmount;

    /*
     * Inisialisasi amount = 0, interest rate = 10 yang berarti bunga sebesar 10%, totalLoanAmount = 0;
     */
    public MoneyInBank() {
        amount = 0;
        interestRate = 10;
        totalLoanAmount = 0;
    }

    /*
     * Inisialisasi amount sesuai masukan dan interest rate sebesar intereseRate% dan totalLoanAmount sesuai masukan
     */
    public MoneyInBank(int amount, int interestRate, int totalLoanAmount) {
        this.amount = amount;
        this.interestRate = interestRate;
        this.totalLoanAmount = totalLoanAmount;
    }

    /*
     * Mengembalikan nilai amount
     */
    public int getAmount() {
        return amount;
    }

    /*
     * Mengembalikan nilai interestRate
     */
    public int getInterestRate() {
        return interestRate;
    }

    /*
     * Mengembalikan nilai totalLoanAmount
     */
    public int getTotalLoanAmount() {
        return totalLoanAmount;
    }

    /*
     * Menambahkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInBank dengan interestRate dari this.interestRate dan totalLoanAmount dari this.totalLoanAmount
     */
    public MoneyTransaction add(MoneyTransaction money) {
        this.amount += money.getAmount();
        return new MoneyInBank(this.amount, this.interestRate, this.totalLoanAmount);
    }

    /*
     * Mengurangkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInBank dengan interestRate dari this.interestRate dan totalLoanAmount dari this.totalLoanAmount
     * Jika amount dari masukan lebih besar dari amount, maka return 0
     */
    public MoneyTransaction subtract(MoneyTransaction money) {
        if (money.getAmount() > this.amount) {
            this.amount = 0;
        }
        else {
            this.amount -= money.getAmount();
        }
        return new MoneyInBank(this.amount, this.interestRate, this.totalLoanAmount);
    }

    /*
     * Menghitung bunga yang diperoleh dari amount
     * Bunga dihitung dengan rumus (amount * interestRate) / 100
     * Jika bunga bukan bilangan bulat, bulatkan ke bawah
     */
    public int calcInterest() {
        int bunga = (amount * interestRate) / 100;
        return bunga;
    }

    /*
     * Meminjam uang
     * Tambahkan amount dengan loanAmount
     * Tambahkan totalLoanAmount dengan (loanAmount * (100 + interestRate)) / 100)
     * Jika penambahan bukan bilangan bulat, bulatkan ke bawah
     */
    public void borrow(int loanAmount) {
        this.amount += loanAmount;
        int additional =loanAmount * (100 + interestRate) / 100;
        this.totalLoanAmount += additional;
    }

    /*
     * Menggambarkan transaksi setiap bulannya pada uang di bank
     * Pertama tambahkan bunga pada amount
     * Kemudian kurangkan amount dengan totalLoanAmount
     * Jika amount kurang dari 0, set amount menjadi 0
     * Set totalLoanAmount menjadi 0
     */

    public void monthlyTransaction() {
        this.amount += calcInterest();
        this.amount -= totalLoanAmount;
        if (this.amount < 0) {
            this.amount = 0;
        }
        this.totalLoanAmount = 0;
    }
}
