// Erdianti Wiga Putri Andini
// 13522053

// package Money;

public interface MoneyTransaction {
    int getAmount();
    MoneyTransaction add(MoneyTransaction money);
    MoneyTransaction subtract(MoneyTransaction money);
}