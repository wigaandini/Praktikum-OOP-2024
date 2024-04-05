#include <iostream>
#include "Polinom.hpp"
using namespace std;
#include <cmath>



// ctor, cctor, dtor, op=
// untuk konstruktor, inisialisasi seluruh nilai koefisien dengan 0.
Polinom::Polinom(){ // ctor Polinom dengan orde = 0
    derajat = 0;
    koef = new int[derajat+1];
    for(int i = 0; i <= derajat; i ++){
        koef[i] = 0;
    }
}

Polinom::Polinom(int n){ // ctor Polinom dengan orde = n (sesuai parameter)
    derajat = n;
    koef = new int[derajat+1];
    for(int i = 0; i <= derajat; i ++){
        koef[i] = 0;
    }
}

Polinom::Polinom(const Polinom& other){
    derajat = other.derajat;
    koef = new int[derajat+1];
    for(int i = 0; i <= derajat; i ++){
        koef[i] = other.koef[i];
    }
}

Polinom::~Polinom(){
    delete[] koef;
    derajat = 0;
}

Polinom& Polinom::operator=(const Polinom& num){
    derajat = num.derajat;
    koef = new int[derajat + 1];
    for(int i = 0; i <= derajat; i ++){
        koef[i] = num.koef[i];
    }
    return *this;
}



// getter, setter
int Polinom::getKoefAt(int idx) const{
    return koef[idx];
}

int Polinom::getDerajat() const{
    return derajat;
}

void Polinom::setKoefAt(int idx, int val){
    koef[idx] = val;
}

void Polinom::setDerajat(int num){
    derajat = num;
}



// member function
// Melakukan pembacaan koefisien sejumlah derajat Polinom, dimulai dari x^0 (konstanta)
void Polinom::input(){
    for(int i = 0; i <= derajat; i ++){
        cin >> koef[i];
    }
}

// Mencetak seluruh koefisien polinom. Untuk setiap koefisien akhiri dengan end-of-line
// Cetaklah apa adanya dari koefisien ke-0 hingga derajat tertinggi (termasuk apabila koefisien = 0)
void Polinom::printKoef(){
    for(int i = 0; i <= derajat; i ++){
        cout << koef[i] << endl;
    }    
}

// Menghitung hasil substitusi x dengan sebuah bilangan ke dalam polinom
int Polinom::substitute(int x){
    int res = koef[0];
    for(int i = 0; i <= derajat; i ++){
        res += koef[i] * pow(x, i);
    }
    return res;
}

// Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
// Apabila suatu koefisien bernilai < 0, gunakan tanda "-" untuk menggantikan tanda "+"
// Apabila suatu koefisien bernilai 0, lewati koefisien tersebut dan lanjutkan ke koefisien selanjutnya
// Jika seluruh koefisien bernilai 0, keluarkan "0"
void Polinom::print(){
    if (derajat == 0){
        cout << koef[0] << endl;
    }
    else{
        for(int i = 0; i <= derajat; i ++){
            if (koef[i] != 0){
                if (i == 0){
                    cout << koef[i];
                }
                else{
                    if (koef[i] >= 0){
                        cout << "+";
                    }
                    else{
                        cout << "-";
                    }
                    cout << koef[i] << "x^" << i;
                }
            }
        }
        cout << endl;
    }
}