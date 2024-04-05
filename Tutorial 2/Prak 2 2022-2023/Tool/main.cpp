#include <iostream>
#include "ReinforcedAxe.hpp"
#include "Pickaxe.hpp"
#include "Tool.hpp"
using namespace std;

// First assumption
int main() {
    Pickaxe p;
    p.use();    /* swing swing */
    p.enchant();    /* pickaxe enchanted! */
    Pickaxe p2(p);
    Pickaxe p3;
    p3 = p3;
    
    ReinforcedAxe r;
    r.use();    /* chip chop chip chop */
    ReinforcedAxe r2(r);
    r.enchant();   /* reinforced axe's grip enchanted! */
    ReinforcedAxe r3 = r2 + r;   /* reinforcing axe */
    // ReinforcedAxe r4(r3);
    r3.repair();    /* reinforced axe is repaired! */
    
    delete &r;
    delete &r2;
    delete &r3;
    delete &p;
    delete &p2;
    
    return 0;
}


// Second assumption
// int main(){
//     Pickaxe *p = new Pickaxe();
//     p->use();
//     p->enchant();
//     Pickaxe *p2 = new Pickaxe(*p);
//     Pickaxe *p3 = new Pickaxe();
//     *p3 = *p3;

//     ReinforcedAxe *r1 = new ReinforcedAxe();
//     r1->use();
//     ReinforcedAxe *r2 = new ReinforcedAxe(*r1);
//     r2->enchant();
//     ReinforcedAxe *r3 = new ReinforcedAxe(*r2 + *r1);
//     r3->repair();

//     delete r1;
//     delete r2;
//     delete r3;
//     delete p;
//     delete p2;
    
//     return 0;
// }

// tool crafted! 3 2
// pickaxe crafted! 3 2
// swing! swing! diamonds found!
// pickaxe enchanted!
// tool copy crafted! 3 2
// pickaxe copy crafted! 3 2
// tool crafted! 3 2
// pickaxe crafted! 3 2
// pickaxe copied! 3 2
// tool crafted! 3 4
// reinforced axe crafted! 3 4
// chip chop chip chop! 3 4
// tool crafted! 3 4
// reinforced axe copy crafted! 3 4
// reinforced axe's grip enchanted! 3 4
// tool crafted! 3 4
// reinforced axe copy crafted! 3 4
// reinforcing axe! 6 8
// tool crafted! 6 8
// reinforced axe copy crafted! 6 8
// reinforced axe is repaired! 6 8
// reinforced axe destroyed! 3 4
// tool destroyed! 3 4
// reinforced axe destroyed! 3 4
// tool destroyed! 3 4
// reinforced axe destroyed! 6 8
// tool destroyed! 6 8
// pickaxe destroyed! 3 2
// tool destroyed! 3 2
// pickaxe destroyed! 3 2
// tool destroyed! 3 2