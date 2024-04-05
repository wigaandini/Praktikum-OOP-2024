// Erdianti Wiga Putri Andini
// 13522053

#include "GlassCup.hpp"
#include <iostream>
using namespace std;


/**
 * @return Apakah cangkir kaca masih dapat digunakan?
 */
bool GlassCup::is_usable() {
    return Glass::is_usable();
}

/**
 * Mengisi air ke dalam cangkir
 *
 * Jika cangkir tidak usable, tidak melakukan apapun
 *
 * @param volume Dijamin dalam range [0, INTMAX)
 * @param type
 */
void GlassCup::fill(int volume, enum WaterType type) {
    if (GlassCup::is_usable()) {
        Cup::fill(volume, type);
    }
}

/**
 * Meminum air dari cangkir
 *
 * Jika cangkir tidak usable, tidak melakukan apapun
 *
 * @param volume Dijamin dalam range [0, INTMAX)
 */
void GlassCup::drink(int volume) {
    if (GlassCup::is_usable()) {
        Cup::drink(volume);
    }
}

/**
 * Menjatuhkan cangkir dari ketinggian height
 *
 * Mengaplikasikan force sejumlah <height * volume air saat ini>
 * Jika volume air saat ini = 0, mengaplikasikan force hanya sejumlah <height>
 *
 * @param height Dijamin dalam range [0, 100]
 */
void GlassCup::drop(int height) {
    int force = height * get_water_volume();
    if (get_water_volume() == 0) {
        force = height;
    }
    Glass::apply_force(force);
}