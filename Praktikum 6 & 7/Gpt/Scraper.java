// Erdianti Wiga Putri Andini
// 13522053

import java.util.List;

public class Scraper extends Thread {
    private String str;
    private List<Character> chr;
    
    public Scraper(String str, List<Character> chr) {
        this.str = str;
        this.chr = chr;
    }

    public void run() {
        Gpt gpt = new Gpt(str);
        char piece = gpt.getPieceAnswer();

        synchronized (chr) {
            chr.add(piece);
        }
    }
}
