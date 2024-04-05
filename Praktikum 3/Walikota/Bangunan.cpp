// Erdianti Wiga Putri A
// 13522053 - K1

#include <string>
#include "Bangunan.hpp"
using namespace std;


/*
    Membuat objek Bangunan dengan nama "Bangunan Kosong"
*/
Bangunan::Bangunan() {
    this->namaBangunan = "Bangunan Kosong";
}

/*
    Membuat objek Bangunan dengan nama "namaBangunan"
*/
Bangunan::Bangunan(string namaBangunan) {
    this->namaBangunan = namaBangunan;
}
/*
    Mendapatkan nama Bangunan
*/
string Bangunan::getNamaBangunan() {
    return this->namaBangunan;
}
