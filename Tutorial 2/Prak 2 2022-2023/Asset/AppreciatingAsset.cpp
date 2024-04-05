#include "AppreciatingAsset.hpp"
#include <cmath>
#include <iostream>
using namespace std;


// Udah ada di Asset.cpp
// AppreciatingAsset::AppreciatingAsset(Asset* x, double rate) : Asset() {
//     this->x = x;
//     this->rate = rate;
// }

double AppreciatingAsset::getValue(int years) {
    return x->getValue(years) * pow((1 + rate), years);
}