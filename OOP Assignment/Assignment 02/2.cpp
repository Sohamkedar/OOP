/* 2. Write a C++ Program to print your roll number and Name using class and 
object. */
#include <iostream> 
using namespace std; 
class Student { 
public: 
int id;//data member (also instance variable)     
string name;//data member(also instance variable)     
}; 
int main() { 
Student s1; //creating an object of Student  
s1.id = 1162;   
s1.name = "Soham Kedar";  
cout<<s1.id<<endl; 
cout<<s1.name<<endl; 
return 0; 
}