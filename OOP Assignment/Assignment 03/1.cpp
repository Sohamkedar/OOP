/* Implement a class Complex which represents the Complex Number data type. 
Implement the following operations:  
1. Constructor (including a default constructor which creates the complex number 
(0+0i).  
2. Overloaded operator + to add two complex numbers.  
3. Overloaded operator * to multiply two complex numbers.  
4. Overloaded << and >> to print and read Complex Numbers.*/
#include <iostream>
using namespace std;

class complex {
    float x;
    float y;

public:
    complex() : x(0), y(0) {}  // Member initializer list for default constructor

    complex operator+(complex);
    complex operator*(complex);

    friend istream &operator>>(istream &input, complex &t) {
        cout << "Enter the real part: ";
        input >> t.x;
        cout << "Enter the imaginary part: ";
        input >> t.y;
        return input;  // Return input stream
    }

    friend ostream &operator<<(ostream &output, const complex &t) { // Use const reference
        output << t.x << "+" << t.y << "i"; // Removed extra newline character
        return output;  // Return output stream
    }
};

complex complex::operator+(complex c) {
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return temp;
}

complex complex::operator*(complex c) {
    complex temp2;
    temp2.x = (x * c.x) - (y * c.y);
    temp2.y = (y * c.x) + (x * c.y);
    return temp2;
}

int main() {  // Corrected the function signature
    complex c1, c2, c3, c4;
    cout << "Default constructor value: " << c1 << endl;  // Corrected output format
    cout << "\nEnter the 1st number:\n";
    cin >> c1;
    cout << "\nEnter the 2nd number:\n";
    cin >> c2;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "\nThe first number is: " << c1 << endl;
    cout << "The second number is: " << c2 << endl;
    cout << "The addition is: " << c3 << endl;
    cout << "The multiplication is: " << c4 << endl;
    return 0;
}
