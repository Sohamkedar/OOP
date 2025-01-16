/* Create employee bio-data using following classes: 
i) Personal record 
ii) Professional record 
iii) Academic record Assume appropriate data members and member function to 
accept required data & print bio-data.  */
#include <iostream>
using namespace std;

class personal {
protected:
    char name[50];
    char address[50];
    char birthdate[50];
    char gender;

public:
    void get_personal() {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "\nEnter Address: ";
        cin >> address;
        cout << "\nEnter Birthdate (dd/mm/yyyy): ";
        cin >> birthdate;
        cout << "\nEnter gender (M/F): ";
        cin >> gender;
    }
};

class professional {
protected:
    int expinnoofyear;
    char orgname[50];
    char projname[50];
    char projdetails[50];

public:
    void get_professional() {
        cout << "\nEnter number of years of experience: ";
        cin >> expinnoofyear;
        cout << "\nEnter organization name: ";
        cin >> orgname;
        cout << "\nEnter project name: ";
        cin >> projname;
        cout << "\nEnter project details: ";
        cin >> projdetails;
    }
};

class academic {
protected:
    int year;
    int marks;
    int percentage;
    char grade[50]; // Renamed from 'clas'

public:
    void get_academic() {
        cout << "\nEnter academic year: ";
        cin >> year;
        cout << "\nEnter total marks: ";
        cin >> marks;
        cout << "\nEnter percentage: ";
        cin >> percentage;
        cout << "\nEnter class: ";
        cin >> grade; // Updated variable name
    }
};

class biodata : public personal, public academic, public professional {
public:
    void display() {
        cout << "\n--------------Employee Biodata------------" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Personal Details" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: " << birthdate << endl;
        cout << "Gender: " << gender << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "----------------Academic Details--------------" << endl;
        cout << "Academic Year\tMarks\tPercentage\tClass" << endl;
        cout << year << "\t" << marks << "\t" << percentage << "\t" << grade << endl; // Updated variable name
        cout << "-------------------------------------------------------" << endl;
        cout << "-----------------Professional Details--------------------" << endl;
        cout << "Organization Name: " << orgname << endl;
        cout << "Years of Experience: " << expinnoofyear << endl;
        cout << "Project Done: " << projname << endl;
        cout << "Project Details: " << projdetails << endl;
    }
};

int main() {
    biodata b;
    b.get_personal();
    b.get_academic();
    b.get_professional();
    b.display();
    return 0;
}
