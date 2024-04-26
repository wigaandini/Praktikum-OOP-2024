// Erdianti Wiga Putri Andini
// 13522053 - K01

import java.util.*;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> kataTito = new HashMap<>();
        Map<String, Integer> kataWiwid = new HashMap<>();
        
        for (String word : tito) {
            kataTito.put(word, kataTito.getOrDefault(word, 0) + 1);
        }
        
        for (String word : wiwid) {
            kataWiwid.put(word, kataWiwid.getOrDefault(word, 0) + 1);
        }

        for (String word : kataTito.keySet()) {
            if (kataWiwid.containsKey(word)) {
                System.out.println(word);
            }
        }
    }
}