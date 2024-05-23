import java.util.*;
public class Shuffle {
 public static void main(String[] args) {
 List<String> list = new ArrayList<String>();
 for (String a : args)
 list.add(a);
 Collections.shuffle(list, new Random());
 System.out.println(list);
 }
}
