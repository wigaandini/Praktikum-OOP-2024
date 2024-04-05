// Erdianti Wiga Putri Andini
// 13522053

#include "A.hpp"
#include "B.hpp"

void setA(A* x){
    x->setMe(10);
}

int main() {
    B b;

    // Start editing here :D
    setA(&b);
    b.setMe(200);
    b.print();
    return 0;
}   