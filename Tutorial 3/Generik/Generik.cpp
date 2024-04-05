#include <iostream>
using namespace std;

template <class T>
void func (T param1, T param2) {
    cout << "Masukan Anda: " << param1 << " dan " << param2 << ", memiliki tipe yang sama" << endl;
}

template <class T, class U>
void func (T param1, U param2) {
    cout << "Masukan Anda: " << param1 << " dan " << param2 << ", mungkin memiliki tipe yang berbeda" << endl;
}

template <>
void func (char param1, int param2) {
    for (int i = 0; i < param2; i++) {
        cout << param1 << endl;
    }
}

// int main(){
//     func(1, 2);
//     func(1.0, 2);
//     func('a', 'b');
//     func(1, 'a');
//     func<char,int>('a',2);
// }