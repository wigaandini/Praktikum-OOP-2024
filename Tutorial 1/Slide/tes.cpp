#include <iostream>
using namespace std;
#include <cmath>

int main() {
    std::cout << "Hello World!" << std::endl;
    std::cout << "punten bang" << std::endl;

    int x = 5;
    int y = 10;
    std::cout << x + y << endl;

    int myAge = 35;
    cout << "I am " << myAge << " years old.\n";
    

    for (int i = 0; i < 5; i++){
        cout << ++myAge << endl;
    }


    float f1 = 35e3;
    double d1 = 12E4;
    cout << f1 << endl;
    cout << d1 << endl;

    char a = 65, b = 66, c = 67;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    int p = 11;
    int q = 3;
    cout << p / q << endl;
    cout << (p > q) << endl;

    // string fullName;
    // cout << "Type your full name: ";
    // cin >> fullName;
    // getline (cin, fullName);
    // cout << "Your name is: " << fullName << endl; 

    cout << sqrt(64) << endl;
    cout << round(2.6) << endl;
    cout << log10(100) << endl;

    string food = "Pizza";
    cout << &food << endl;

    return 0;
}
