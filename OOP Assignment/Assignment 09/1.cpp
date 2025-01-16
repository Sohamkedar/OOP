/*Write a function in C++ to count and display the number of lines not starting with 
alphabet 'A' present in a text file "STORY.TXT". 
Example: 
If the file "STORY.TXT" contains the following lines, 
The roses are red. 
A girl is playing there. 
There is a playground. 
An aeroplane is in the sky. 
Numbers are not allowed in the password. 
The function should display the output as 3.*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int nooflines() {
    ifstream fin; // File Handling
    fin.open("STORY.txt");
    
    if (!fin) {
        cout << "Error: Could not open file.\n";
        return -1;
    }
    
    char str[80];
    int count = 0;

    // Use getline correctly
    while (fin.getline(str, 80)) {
        if (str[0] != 'A') {
            count++;
        }
    }
    
    cout << "Number of lines not starting with A are: " << count << endl;
    fin.close();
    return count;
}

int main() {
    nooflines();
    cout << "\n";
    return 0;
}
