#include <iostream>
using namespace std;
#include "ExplodableBarrel.hpp"


// Default Constructor
// health dari ExplodableBarrel selalu 1 dan
// default radiusnya adalah 5
ExplodableBarrel::ExplodableBarrel() : Damageable(), Explodable() {
    this->radius = 5;
}

// Masukan: radius (integer positif) dan baseDamage (integer positif)
// health dari ExplodableBarrel selalu 1
ExplodableBarrel::ExplodableBarrel(int radius, int baseDamage) : Damageable(1), Explodable(baseDamage) {
    this->radius = radius;
}

// Masukan: damage (integer positif) dan element (string)
//
// Berikut adalah urutan aksi yang dilakukan:
//
// Apabila barrel telah hancur, maka tidak akan terjadi
// apa-apa.
//
// Barrel menerima damage dan tidak menghiraukan element.
// Apabila barrel hancur setelah menerima damage, maka
// barrel akan meledak sebesar radius yang telah ditentukan.
void ExplodableBarrel::takeDamage(int damage, string element) {
    if (!isDestroyed()) {
        Damageable::takeDamage(damage);
        if (isDestroyed()) {
            explode(this->radius);
        }
    }
}