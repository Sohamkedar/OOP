// 5. Write a C++ program to compute the power a given number to a given power.
#include <iostream> 
using namespace std; 
int main()  
{ 
int power; 
float base, result = 1; 
cin >> base >>power; 
while (power != 0) { 
    result *= base; 
    power--; 
} 
cout << result; 
return 0; 
}