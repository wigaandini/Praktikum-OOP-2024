#include "Rekening.h" // include the Account header file
#include "RekeningGiro.h"
#include <iostream>
using namespace std;


// Konstruktor menginisialisi saldo (parameter 1) dan suku bunga (parameter 2)
// Set suku bunga 0.0 apabila suku bunga bernilai negatif
RekeningGiro::RekeningGiro(double saldo, double bunga) : Rekening(saldo) {
    if (bunga < 0.0) {
        this->sukuBunga = 0.0;
    }
    else {
        this->sukuBunga = bunga;
    }
}


// Getter, Setter
void RekeningGiro::setSukuBunga(double bunga) {
    this->sukuBunga = bunga;
}

double RekeningGiro::getSukuBunga() const {
    return sukuBunga;

}


// Member Function
// Bunga dihitung dari saldo dikali suku bunga
double RekeningGiro::hitungBunga(){
    return getSaldo() * sukuBunga;
}