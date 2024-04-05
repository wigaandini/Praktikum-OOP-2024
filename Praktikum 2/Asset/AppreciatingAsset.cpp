// Erdianti Wiga Putri Andini
// 13522053

#include "AppreciatingAsset.hpp"
#include <cmath>
#include <iostream>
using namespace std;


double AppreciatingAsset::getValue(int years) {
    return x->getValue(years) * pow((1 + rate), years);
}