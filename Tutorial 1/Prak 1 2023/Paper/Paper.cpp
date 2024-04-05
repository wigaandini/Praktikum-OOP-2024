#include <iostream>
#include "Paper.hpp"
using namespace std;

Paper::Paper(char c) {
    name = c;
    n_fold = 0;
    cout << "ctor" << c << endl;
}

Paper::Paper(const Paper& other) {
    name = other.name;
    n_fold = other.n_fold;
    cout << "cctor" << other.name << endl;
}

Paper::~Paper(){
    cout << "dtor" << name << endl;
}

void Paper::fold(){
    n_fold ++;
    cout << "fold" << name << "(" << n_fold << ")" << endl;
} 

void Paper::glue(){
    cout << "glue" << name << endl;
    fold();
}

void Paper::setName(char c){
    cout << "setName" << name << "=>" << c << endl;
    name = c;
}