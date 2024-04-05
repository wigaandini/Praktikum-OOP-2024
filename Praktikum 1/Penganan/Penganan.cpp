// Erdianti Wiga Putri A
// 13522053

#include <iostream>
#include "Penganan.hpp"
using namespace std;


int Penganan::uang = 0;
int Penganan::n_rumah = 0;


// ctor tanpa parameter
// inisialisasi seluruh koefisien dengan nilai 0
Penganan::Penganan() {
    keik = 0; 
    panekuk = 0;
}

// ctor dengan parameter
Penganan::Penganan(int keik, int panekuk) {
    this->keik = keik;
    this->panekuk = panekuk;
}

//mengembalikan bagian jumlah keik
int Penganan::GetKeik() const {
    return keik;
}

// mengembalikan bagian jumlah panekuk
int Penganan::GetPanekuk() const {
    return panekuk;
}

// mengisi bagian keik
void Penganan::SetKeik(int k) {
    keik = k;
}

// mengisi bagian panekuk
void Penganan::SetPanekuk(int p) {
    panekuk = p;
}

// operator overloading

// operator+ 
Penganan operator+ (const Penganan& recent, const Penganan& stock) {
    Penganan res;
    res.keik = recent.keik + stock.keik;
    res.panekuk = recent.panekuk + stock.panekuk;
    res.n_rumah = recent.n_rumah + 1;
    return res;
}

// operator- 
Penganan operator- (const Penganan& jual, const Penganan& beli) {
    Penganan res;
    if (beli.keik > jual.keik) {
        res.keik = 0;
        res.uang = jual.uang + jual.keik * 51;
    }
    else {
        res.keik = jual.keik - beli.keik;
        res.uang = jual.uang + beli.keik * 51;
    }
    if (beli.panekuk > jual.panekuk) {
        res.panekuk = 0;
        res.uang = jual.uang + jual.panekuk * 37;
    }
    else {
        res.panekuk = jual.panekuk - beli.panekuk;
        res.uang = jual.uang + beli.panekuk * 37;
    }
    res.n_rumah = jual.n_rumah;
    return res;
}

// operator^ 
Penganan operator^ (const Penganan& stock, const int n) {
    Penganan res;
    if (stock.keik < n) {
        res.uang = stock.uang - ((n - stock.keik) * 51); 
        res.keik = 0;
    }
    else {
        res.keik = stock.keik - n;
    }
    if (stock.panekuk < n) {
        res.uang = stock.uang - ((n - stock.panekuk) * 37); 
        res.panekuk = 0;
    }
    else {
        res.panekuk = stock.panekuk - n;
    }
    res.n_rumah = stock.n_rumah;
    return res;
}

// operator^ (sifat komutatif)
Penganan operator^ (const int n, const Penganan& stock) {
    Penganan res;
    if (stock.keik < n) {
        res.uang = stock.uang - ((n - stock.keik) * 51); 
        res.keik = 0;
    }
    else {
        res.keik = stock.keik - n;
    }
    if (stock.panekuk < n) {
        res.uang = stock.uang - ((n - stock.panekuk) * 37); 
        res.panekuk = 0;
    }
    else {
        res.panekuk = stock.panekuk - n;
    }
    return res;
}

// mengembalikan jumlah uang yang diperoleh
int Penganan::JumlahUang() {
    return uang;
}

// mengembalikan jumlah kunjungan ke rumah
int Penganan::HitungNRumah() {
    return n_rumah;
}

// mencetak isi kantong
// Jangan lupa tambahkan endline di akhir print
// Contoh:
// 0keik-0panekuk
// 111keik-122panekuk
void Penganan::Print() {
    cout << this->keik << "keik-" << this->panekuk << "panekuk" << endl;
}