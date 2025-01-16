// Write a function to find the length of a string in C++. 
#include <iostream> 
using namespace std; 
int main()  
{ 
string str; 
cin>>str; 
int count = 0; 
for(int i = 0;str[i];i++) // till the string character is null 
    count++; 
cout<<count; 
}