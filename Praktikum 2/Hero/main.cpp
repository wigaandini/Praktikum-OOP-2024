// Erdianti Wiga Putri Andini
// 13522053

#include "Hero.hpp"
#include "Axe.hpp"
#include "Invoker.hpp"
#include <iostream>
using namespace std;

int main() {
    Invoker *i1 = new Invoker(10,1000);
    i1->useSkill();
    Invoker *i2 = new Invoker(*i1);
    i1->Hero::heal(1);
    Invoker *i3 = new Invoker();
    i3->move(10, 25);
    *i1 = *i2;
    Axe *a1 = new Axe(200,10);
    a1->move(2, 20);
    a1->heal(10);
    Axe *a2 = new Axe(*a1);
    Axe *a3 = new Axe(*a1 + *a2);
    a1->useSkill();
    a3->useSkill();

    delete a1;
    delete a3;
    delete i1;


    return 0;
}