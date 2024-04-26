// Erdianti Wiga Putri Andini
// 13522053 - K01

import java.util.*;

public class Pasukan <T extends List<Integer>> {
    private T list;
    private int n;

    public Pasukan(T list, int n) {
        this.n = n;
        this.list = list;
    }

    public void reset(){
        list.clear();
        for (int i = 0; i < n; i++) {
            list.add(0);
        }
    }

    public long get(int idx){
        reset();
        long awal = Util.getTime();
        int val = list.get(idx);
        long akhir = Util.getTime();
        return akhir - awal;
    }

    public long del(int idx, int count){
        reset();
        long awal = Util.getTime();
        for (int i = 0; i < count; i++) {
            list.remove(idx);
        }
        long akhir = Util.getTime();
        return akhir - awal;
    }
}