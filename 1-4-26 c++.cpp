#include <iostream>
using namespace std;

class Student {
private:
    int roll_number;
    string name;
    float marks[5];

public:
    // Default Constructor
    Student() {
        roll_number = 0;
        name = "";
        for(int i = 0; i < 5; i++)
            marks[i] = 0;
    }

    // Destructor
    ~Student() {
        // Optional cleanup
    }

    // Add Student (User Input)
    void addStudent() {
        cout << "\nEnter Roll Number: ";
        cin >> roll_number;
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter 5 Marks:\n";
        for(int i = 0; i < 5; i++) {
            cout << "Subject " << i+1 << ": ";
            cin >> marks[i];
        }
    }

    // Modify Student
    void modifyStudent() {
        cout << "\nEnter New Name: ";
        cin >> name;

        cout << "Enter New Marks:\n";
        for(int i = 0; i < 5; i++) {
            cout << "Subject " << i+1 << ": ";
            cin >> marks[i];
        }
    }

    // Display Student
    void displayStudent() {
        cout << "\n------------------------";
        cout << "\nRoll Number: " << roll_number;
        cout << "\nName: " << name;
        cout << "\nMarks: ";
        for(int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nAverage: " << calculateAverage();
        cout << "\n------------------------\n";
    }

    // Calculate Average
    float calculateAverage() {
        float sum = 0;
        for(int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return sum / 5;
    }

    // Get Roll Number
    int getRoll() {
        return roll_number;
    }
};

int main() {
    Student students[100];
    int count = 0;
    int choice, roll;
    bool found;

    do {
        cout << "\n===== STUDENT RECORD SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Modify Student";
        cout << "\n3. Display All Students";
        cout << "\n4. Search Student";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            students[count].addStudent();
            count++;
            break;

        case 2:
            cout << "\nEnter Roll Number to Modify: ";
            cin >> roll;
            found = false;

            for(int i = 0; i < count; i++) {
                if(students[i].getRoll() == roll) {
                    students[i].modifyStudent();
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Student not found!\n";
            break;

        case 3:
            if(count == 0) {
                cout << "\nNo records available!\n";
            } else {
                for(int i = 0; i < count; i++) {
                    students[i].displayStudent();
                }
            }
            break;

        case 4:
            cout << "\nEnter Roll Number to Search: ";
            cin >> roll;
            found = false;

            for(int i = 0; i < count; i++) {
                if(students[i].getRoll() == roll) {
                    students[i].displayStudent();
                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "Student not found!\n";
            break;

        case 5:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}