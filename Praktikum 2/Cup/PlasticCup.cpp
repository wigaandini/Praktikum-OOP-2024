// Erdianti Wiga Putri Andini
// 13522053

#include "PlasticCup.hpp"
#include <iostream>
using namespace std;


/**
 * Cangkir plastik layak digunakan jika plastik masih layak,
 * DAN kandungan microplastic di dalamnya di bawah maximum_microplastics.
 *
 * @return Apakah cangkir plastik masih layak digunakan?
 */
bool PlasticCup::is_usable() {
    return PlasticCup::Plastic::is_usable() && (PlasticCup::current_microplastics < PlasticCup::maximum_microplastics);
}

/**
 * Mengisi air ke dalam cangkir.
 *
 * 1. Kandungan air bertambah.
 * 2. Plastik "digunakan".
 * 3. Microplastic terurai berdasarkan rasio <volume air setelah ditambah / kapasitas maksimum>.
 *    Penguraian microplastic menjadi dua kali lipatnya jika air adalah air panas.
 * 4. Kandungan microplastic bertambah sesuai hasil no. 3
 *
 * Jika cangkir tidak usable, tidak melakukan apapun.
 *
 * @param volume Dijamin dalam range [0, INTMAX)
 * @param type
 */
void PlasticCup::fill(int volume, enum WaterType type) {
    if (PlasticCup::is_usable()){
        Cup::fill(volume, type);
        PlasticCup::Plastic::use();

        int ratio = PlasticCup::get_water_volume() / PlasticCup::capacity;
        if (type == 1) {
            ratio *= 2;
        }

        int microplastics = PlasticCup::Plastic::shred_microplastics(volume, PlasticCup::capacity);
        PlasticCup::current_microplastics += microplastics;
    }
}

/**
 * Meminum air dari cangkir.
 *
 * 1. Kandungan air berkurang.
 * 2. Plastik "digunakan".
 * 3. Kandungan microplastic berkurang sejumlah parameter <volume>.
 *
 * Jika cangkir tidak usable, tidak melakukan apapun
 *
 * @param volume Dijamin dalam range [0, INTMAX)
 */
void PlasticCup::drink(int volume) {
    if (PlasticCup::is_usable()) {
        Cup::drink(volume);
        PlasticCup::current_microplastics -= volume;

        if (PlasticCup::current_microplastics < 0) {
            PlasticCup::current_microplastics = 0; 
        }

    PlasticCup::Plastic::use();
    }
}

/**
 * Menjatuhkan cangkir dari ketinggian height.
 *
 * Kandungan microplastic bertambah sejumlah penguraian microplastic
 * dengan rasio berupa <volume air * height / kapasitas>
 *
 * @param height Dijamin dalam range [0, 100]
 */
void PlasticCup::drop(int height) {
    int ratio = PlasticCup::get_water_volume() * height / PlasticCup::capacity;
    int microplastics = PlasticCup::Plastic::shred_microplastics(static_cast<int>(ratio), 100);
    PlasticCup::current_microplastics += microplastics;
}