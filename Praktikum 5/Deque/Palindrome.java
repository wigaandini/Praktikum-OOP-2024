// Erdianti Wiga Putri Andini
// 13522053

public class Palindrome<T> {
    //Method untuk mengecek apakah Deque dq merupakan palindrome
    //Deque dq merupakan palindrome jika elemen-elemen pada Deque dq dapat dibaca sama dari depan dan belakang
    public boolean isPalindrome(Deque<T> dq) {
        try {
            Deque<T> temp = new Deque<>(dq);

            while (temp.size() > 1) {
                T front = temp.popFront();
                T back = temp.popBack();

                if (!front.equals(back)) {
                    return false;
                }
            }

            return true;

        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
}
