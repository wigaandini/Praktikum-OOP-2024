#include "DepreciatingAsset.hpp"
#include <cmath>
#include <iostream>
using namespace std;


// Udah ada di Asset.cpp
// DepreciatingAsset::DepreciatingAsset(Asset* x, double rate) : Asset() {
//     this->x = x;
//     this->rate = rate;
// }

double DepreciatingAsset::getValue(int years) {
    return x->getValue(years) * pow((1 - rate), years);
}