// Erdianti Wiga Putri Andini
// 13522053

#include "DepreciatingAsset.hpp"
#include <cmath>
#include <iostream>
using namespace std;


double DepreciatingAsset::getValue(int years) {
    return x->getValue(years) * pow((1 - rate), years);
}