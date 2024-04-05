#include <iostream>
#include "Kompleks.h"
using namespace std;


// ctor tanpa parameter
// inisialisasi seluruh koefisien dengan nilai 0
Kompleks::Kompleks(){
    real = 0;
    imaginer = 0;
    n_kompleks ++;
}

// ctor dengan parameter
Kompleks::Kompleks(int real, int imaginer){
    this->real = real;
    this->imaginer = imaginer;
    n_kompleks ++;
}

//mengembalikan bagian riil
int Kompleks::GetReal() const{
    return real;
}

int Kompleks::GetImaginer() const{
    return imaginer;
}

// mengisi bagian riil
void Kompleks::SetReal(int num){
    real = num;
}

// mengisi bagian imaginer
void Kompleks::SetImaginer(int num){
    imaginer = num;
}


// operator overloading

// operator+ untuk melakukan penjumlahan dengan rumus berikut
// (a + bi) + (c + di) = (a+c) + (b+d)i
Kompleks operator+ (const Kompleks& a, const Kompleks& b){
    return Kompleks((a.real + b.real), (a.imaginer + b.imaginer));
}

// operator- untuk melakukan pengurangan dengan rumus berikut
// (a + bi) − (c + di) = (a−c) + (b−d)i
Kompleks operator- (const Kompleks& a, const Kompleks& b){
    return Kompleks((a.real - b.real), (a.imaginer - b.imaginer));   
}

// operator* untuk melakukan perkalian dengan rumus berikut
// (a + bi)(c + di) = ac + bci + adi + bd i^2 = (ac−bd) + (bc+ad)i
Kompleks operator* (const Kompleks& a, const Kompleks& b){
    return Kompleks(((a.real * b.real) - (a.imaginer * b.imaginer)), ((a.imaginer * b.real) + (a.real * b.imaginer)));
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta
// (a + bi)(c) = (ac) + (bc)i
Kompleks operator* (const Kompleks& a, const int num){
    return Kompleks((a.real * num), (a.imaginer * num));
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta (sifat komutatif)
Kompleks operator* (const int num, const Kompleks& a){
    return a * num;
}

// mengembalikan jumlah instance yang pernah dibuat
int Kompleks::CountKompleksInstance(){
    return n_kompleks;
}

// mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line 
// contoh:
// 3+5i
// 0+0i
// -5-4i
void Kompleks::Print(){
    cout << real;
    if (imaginer < 0){
        cout << "-";
    }
    else{
        cout << "+";
    }
    cout << imaginer << "i" << endl;
}