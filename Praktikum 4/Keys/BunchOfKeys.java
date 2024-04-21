// Erdianti Wiga Putri Andini
// 13522053


class BunchOfKeys {
    private int n_keys;

    public BunchOfKeys() {
        this.n_keys = 0;
    }

    public void add() {
        this.n_keys++;
    }

    public void shake() {
        if (n_keys > 1) {
            for (int i = 0; i < n_keys; i ++) {
                System.out.println("krincing");
            }
        }
        else {
            System.out.println("Tidak terjadi apa-apa");
        }
    }
}