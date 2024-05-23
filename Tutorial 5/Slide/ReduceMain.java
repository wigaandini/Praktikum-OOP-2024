package Slide;
import java.util.*;
class ReduceMain {
 public static void main(String[] args) {
List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6);
// Total semua elemen dalam list
int result = numbers
 .stream()
 .reduce(0, (subtotal, element) -> subtotal + element);
// Hasilnya 21
System.out.println(result);
 }
}
