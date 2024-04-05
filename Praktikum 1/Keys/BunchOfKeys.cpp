// Erdianti Wiga Putri A 
// 13522053

#include <iostream>
#include "BunchOfKeys.hpp"
using namespace std;

// ctor
BunchOfKeys::BunchOfKeys(){
    n_keys = 0;
}

void BunchOfKeys::add(){
    n_keys ++;
}

void BunchOfKeys::shake(){
    if (n_keys <= 1) {
        cout << "Tidak terjadi apa-apa" << endl;
    }
    else {
        for (int i = 0; i < n_keys; i ++) {
            cout << "krincing" << endl;
        }
    }
}