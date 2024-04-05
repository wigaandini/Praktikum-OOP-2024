// Erdianti Wiga Putri A
// 13522053

#include "Paper.hpp"
#include <iostream>
using namespace std;


int main() {
    Paper *a = new Paper('A');
    Paper *b = new Paper('B');
    Paper *c = new Paper('C');
    Paper *d = new Paper(*c);

    a->fold();
    b->fold();
    c->fold();
    c->glue();
    a->~Paper();
    c->setName('X');
    d->fold();
    d->glue();
    d->~Paper();
    c->~Paper();
    b->~Paper();
    return 0;
}

// Program di atas jika dijalankan dengan kelas Paper yang disediakan, akan mengeluarkan output:

// ctor A
// fold A(1)
// fold A(2)
// dtor A 

// Sebagai seorang mahasiswa yang telah memahami konsep dasar OOP dengan baik, anda ditugaskan untuk membuat program utama dengan memanfaatkan kelas Paper yang mengeluarkan output sebagai berikut:

// ctor A
// ctor B
// ctor C
// cctor C
// fold A(1)
// fold B(1)
// fold C(1)
// glue C
// fold C(2)
// dtor A
// setName C => X
// fold C(1)
// glue C
// fold C(2)
// dtor C
// dtor X
// dtor B