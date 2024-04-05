// Erdianti Wiga Putri A
// 13522053 - K1

#include <stack>
#include <iostream>
#include "Restaurant.hpp"
using namespace std;


/*
    Constructor untuk membuat restaurant
    Order kosong
*/
Restaurant::Restaurant() {}

/*
    Destructor
*/
Restaurant::~Restaurant() {}

/*
    Menambahkan satu order makanan sejumlah val menu

    Contoh:
    Order = (3, 4, 5)
    val = 2

    Maka order = (2, 3, 4, 5)
*/
void Restaurant::Push(int val) {
    order.push(val);
}

/*
    Memproses order makanan sebanyak val
    Apabila val lebih banyak dari jumlah order makanan yang ada, keluarkan "Proses tidak valid"
    dan tidak ada order makanan yang diproses

    Contoh:
    Order = (3, 4, 5)
    val = 2

    maka order = (5)
*/
void Restaurant::Pop(int val) {
    if (val <= order.size()) {
        for (int i = 0; i < val; i++) {
            order.pop();
        }
    }
    else {
        cout << "Proses tidak valid" << endl;
    }
}

/*
    Menambahkan k order makanan paling akhir diproses sejumlah val menu
    Apabila k lebih besar dari banyaknya order makanan, tambahkan semua order makan sejumlah val menu

    Contoh:
    Order = (1, 2, 3)
    k = 2, val = 3

    maka order = (1, 5, 6)
*/
void Restaurant::AddMenu(int k, int val) {
    stack<int> currStack;

    if (k > order.size()) {
        k = order.size();
    }

    size_t size = order.size();
    int count = order.size() - k;

    for (int i =0; i < size ; i++) {
        if (i >= count){
            currStack.push(order.top()+val);
            order.pop();
        } 
        else {
            currStack.push(order.top());
            order.pop();
        }
    }
    
    while(!currStack.empty()) {
        order.push(currStack.top());
        currStack.pop();
    }
}


/*
    Memutar urutan pemrosesan k order makanan paling bawah
    Contoh: 
    k = 3
    order =  1 2 3 4 5 (1 merupakan order makanan paling atas untuk diproses)

    Hasil
    order = 1 2 5 4 3

    Jika k > jumlah order, putar seluruh urutan order makanan
*/
void Restaurant::Reorder(int k) {
    stack<int> s1;
    stack<int> s2;

    if (k > order.size()){
        k = order.size();
    }

    size_t size = order.size();
    for (int i=0; i < size;i++) {
        s1.push(order.top());
        order.pop();
    }

    for (int i=0; i < k;i++) {
        s2.push(s1.top());
        s1.pop();
    }

    while (!s2.empty()) {
        order.push(s2.top());
        s2.pop();
    }
        
    while (!s1.empty()) {
        order.push(s1.top());
        s1.pop();
    }
}

/*
    Mencetak order makanan pada restaurant dimulai dari paling awal diproses
    Contoh = (1, 2, 3, 4, 5)
    Apabila order kosong cetak ()
*/
ostream& operator<<(ostream& os, Restaurant r) {
    os << "(";
    int size = r.order.size();
    if (size != 0){
        for (int i =0; i< size;i++){
            os << r.order.top();
            r.order.pop();
            if (i != size-1){
                os << ", ";
            }
        }
    }
    os << ")" << endl;
    return os;
}