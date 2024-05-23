import java.util.*;
 
public class DequeExample {
 public static void main(String[] args){
 Deque<String> deque = new LinkedList<String>();
 deque.add("Element 1"); // Tail
 deque.addFirst("Element 2"); // Head
 deque.addLast("Element 3"); // Tail
 deque.push("Element 4"); // Head
 deque.offerFirst("Element 5"); // Head
 deque.offerLast("Element 6"); // Tail
// Pop returns the head, and removes it from the deque
 System.out.println("Pop " + deque.pop());
 System.out.println("After pop: " + deque);
 // We can remove the first / last element.
 deque.removeFirst();
 deque.removeLast();
 System.out.println("Deque after removing " + "first and last: " + deque);
 }
} 