package Slide;
import java.util.*;
class ForEachMain {
 public static void main(String[] args) {
List<String> names = Arrays.asList("Larry", "Steve", "James");
// Mencetak setiap nama dalam names
names.forEach(System.out::println);
// Keluarannya:
// Larry
// Steve
// James
 }
}
