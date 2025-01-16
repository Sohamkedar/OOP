/* 6. Write a C++ program to calculate the average of all the elements present in 
an array. */
#include <iostream> 
using namespace std; 
int main() 
{ 
int n; 
cin>>n; 
int arr[n]; 
float sum = 0.0; 
for(int i = 0;i<n;i++) 
    cin>>arr[i]; 
for(int i = 0;i<n;i++) 
    sum += arr[i]; 
cout<<(float)(sum/(float)n); 
return 0; 
} 