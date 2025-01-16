/* Implement a class Quadratic that represents degree two polynomials i.e., 
polynomials of type ax2+bx+c. The class will require three data members 
corresponding to a, b and c. Implement the following operations:  
1. A constructor (including a default constructor which creates the 
0polynomial).   
2. Overloaded operator+ to add two polynomials of degree2.  
3. Overloaded << and >> to print and read polynomials. To do this, you will 
need to decide what you want your input and output format to look like.  
4. A function eval that computes the value of a polynomial for a given value 
of x.  
5. A function that computes the two solutions of the equationax2+bx+c=0. */
#include <iostream>
#include <cmath>
using namespace std;

class Quadratic {
public:
    int a, b, c, s;

    Quadratic() {
        a = 0;
        b = 0;
        c = 0;
    }

    Quadratic operator+(Quadratic &d) {
        Quadratic c4;
        c4.a = a + d.a;
        c4.b = b + d.b;
        c4.c = c + d.c;
        return c4;
    }

    friend void operator<<(ostream &o, Quadratic &e) {
        o << e.a << "x\u00B2" << "+" << e.b << "x" << "+" << e.c;
    }

    friend void operator>>(istream &i, Quadratic &q) {
        i >> q.a >> q.b >> q.c;
    }

    void eval(int se) {
        s = (a * se * se) + (b * se) + c;
        cout << "The result of polynomial for a given x: " << s;
    }

    void sol() { // Added void return type
        cout << "\nThe roots of quadratic equation of polynomial is: ";
        cout << "\nRoot1: " << ((-b) + (sqrt(b * b - 4 * a * c))) / (2 * a);
        cout << "\nRoot2: " << ((-b) - (sqrt(b * b - 4 * a * c))) / (2 * a);
    }
};

int main() {
    Quadratic c1, c2, c3, c6;
    int x;

    cout << "Initially polynomial is: ";
    cout << c1;
    cout << "\nEnter first polynomial: " << endl;
    cin >> c1;
    cout << "Enter second polynomial: " << endl;
    cin >> c2;
    c3 = c1 + c2;
    cout << "First polynomial is: " << endl;
    cout << c1;
    cout << "\nSecond polynomial is: " << endl;
    cout << c2;
    cout << "\nAddition of two polynomial: " << endl;
    cout << c3;
    cout << "\nEnter the value of x to evaluate polynomial 1: " << endl;
    cin >> x;
    c1.eval(x);
    c1.sol();
    cout << "\nEnter the value of x to evaluate polynomial 2: " << endl;
    cin >> x;
    c2.eval(x);
    c2.sol();
    return 0;
}
