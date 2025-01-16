/* Create student database with appropriate data members that should use the following 
features of object oriented programming in C++. Class, Object, array of objects, 
new, delete, default constructor to initialize student class fields, parameterized 
constructor to set the values into the objects, access specifiers, this pointer. */
#include <iostream>
#include <string.h>
#include <climits> // Include this for INT_MAX
using namespace std;

class info {
public:
    char dob[10];
    char add[30];
    char name[30], year[3];
    float marks;
    long tel_no;
    static int cnt;

    info();
    info(info &);
    void accept();
    void display();
    static int count();
};

// Initialize static member
int info::cnt = 0;

// Default constructor
info::info() {
    strcpy(name, "Default");
    strcpy(year, "FE");
    strcpy(add, "Default");
    marks = 0;
    tel_no = 10;
    strcpy(dob, "1/1/90");
}

// Parameterized constructor
info::info(info &p) {
    strcpy(name, p.name);
    strcpy(year, p.year);
    marks = p.marks;
    tel_no = p.tel_no;
    strcpy(dob, p.dob);
}

void info::accept() {
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the address: ";
    cin >> add;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter telephone number: ";
    cin >> tel_no;
    cout << "Enter Marks: ";
    cin >> marks;
    cout << "Enter date of birth: ";
    cin >> dob;
}

void info::display() {
    cout << "\n\nName: " << this->name; // Use of 'this' pointer
    cout << "\nAddress: " << this->add;
    cout << "\nYear: " << this->year;
    cout << "\nTelephone number: " << this->tel_no;
    cout << "\nMarks: " << this->marks;
    cout << "\nDate of birth: " << this->dob;
}

int info::count() {
    cnt = cnt + 1;
    return (cnt);
}

int main() {
    int ch, i, n = 0, ch1, pos, temp, flag = 0; // Initialize n
    info o[50];
    char name[30]; // Match size of name with class

    do {
        cout << "\n\n==============";
        cout << "\n MENU";
        cout << "\n==============";
        cout << "\n1. Accept";
        cout << "\n2. Display";
        cout << "\n3. Insert record";
        cout << "\n4. Search record";
        cout << "\n5. Delete record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        // Validate input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(INT_MAX, '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            continue;
        }

        switch (ch) {
        case 1:
            cout << "\n1. Inbuilt record..?";
            cout << "\n2. New record..?";
            cin >> ch1;
            switch (ch1) {
            case 1: {
                info a1; // Correct syntax for default constructor
                cout << "\nDefault values initialized....";
                n = info::count();
                break;
            }
            case 2:
                if (n < 50) { // Bounds check
                    o[n].accept(); // Accept data into the array
                    n = info::count();
                } else {
                    cout << "\nNo more records can be added!";
                }
                break;
            }
            break;

        case 2:
            for (i = 0; i < n; i++) {
                o[i].display();
            }
            break;

        case 3:
            cout << "\nEnter the position to insert record: ";
            cin >> pos;
            if (pos > 0 && pos <= n + 1 && n < 50) { // Bounds check
                pos = pos - 1;
                for (i = n; i > pos; i--) {
                    o[i] = o[i - 1]; // Shift elements
                }
                o[pos].accept(); // Insert new record
                n = info::count(); // Update record count
            } else {
                cout << "\nInvalid position or array full.";
            }
            break;

        case 4:
            cout << "Enter the name to be searched: ";
            cin >> name;
            flag = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(name, o[i].name) == 0) {
                    flag = 1;
                    o[i].display();
                    break;
                }
            }
            if (flag == 0)
                cout << "Sorry.. Record not found";
            break;

        case 5:
            cout << "\nEnter the position to delete record: ";
            cin >> pos;
            if (pos > 0 && pos <= n) { // Bounds check
                pos = pos - 1;
                for (i = pos; i < n - 1; i++) {
                    o[i] = o[i + 1]; // Shift elements
                }
                cout << "\nRecord is deleted..";
                n--; // Decrement record count
                info::cnt--; // Update static count
            } else {
                cout << "\nInvalid position.";
            }
            break;

        case 6:
            cout << "\nExiting the program...";
            break;

        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 6.";
        }
    } while (ch != 6);

    return 0;
}
