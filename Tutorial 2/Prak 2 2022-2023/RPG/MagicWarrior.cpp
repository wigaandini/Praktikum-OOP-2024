#include <iostream>
#include "MagicWarrior.hpp"
using namespace std;


MagicWarrior::MagicWarrior(std::string name) : Hero(name) {}

// reduce enemy health by power
void MagicWarrior::attack(Hero* h) {
    h->setHealth(h->getHealth() - this->getPower());
}       

// heal target by power/2
void MagicWarrior::heal(Hero* h) {
    h->setHealth(h->getHealth() + this->getPower()/2);
}       

// deal damage by target_health/2  
void MagicWarrior::magicAttack(Hero* h) {
    h->setHealth(h->getHealth() - h->getHealth()/2);
}

// current power *2 
void MagicWarrior::powerUp() {
    this->setPower(this->getPower() * 2);
}             