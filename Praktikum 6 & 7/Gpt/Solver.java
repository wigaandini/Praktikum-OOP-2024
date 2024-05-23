// Erdianti Wiga Putri Andini
// 13522053

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.List;

public class Solver {
  private ArrayList<String> prompts;

  public Solver() {
    this.prompts = new ArrayList<String>();
  }

  public void addPiece(String prompt) {
    this.prompts.add(prompt);
  }

  public String scrapeAnswer() {
    // Kode berikut masih melakukan scrap ke GPT secara sekuensial.
    // Agar lebih cepat, ubahlah kode di bawah ini menjadi paralel
    // menggunakan wait dan notify, dengan membuat instance Scraper
    // Perhatikan juga bahwa piece answer di sini belum terurut.
    List<Scraper> scr = new ArrayList<>();
    List<Character> chr = Collections.synchronizedList(new ArrayList<>());

    for (String prompt : prompts) {
        Scraper s = new Scraper(prompt, chr);
        scr.add(s);
        s.start();
    }

    for (Scraper scrap : scr) {
        try {
            scrap.join();
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    Collections.sort(chr);

    StringBuilder answer = new StringBuilder();
    for (char c : chr) {
        answer.append(c);
    }

    return answer.toString();
  }
}