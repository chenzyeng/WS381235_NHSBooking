


#include <iostream>
#include <vector>
#include <string>

using namespace std;

//dependencies
#include "patientpage.h";
#include "doctorpage.h";
#include "pharmacistpage.h";



int main() {
    char role;
     

    while (true) {
        std::cout << std::endl << "----------------------------" << std::endl;
        std::cout << std::endl << "  NHS North Somerset Website  " << std::endl;
        std::cout << std::endl << "----------------------------" << std::endl;
        std::cout << "What is your role ?";

        while (cout << "\n 1. Patient \n 2. Doctor/Nurse \n 3. Pharmacist \n" << endl && !(cin >> role)) {
            cin.clear();
            string temp;
            getline(cin, temp); //when other input other than 1,2,3 are inputed, it says "invalid input"
            //this was done to stop the program from crashing
            cout << "Invalid input, please re-enter.\n";
        }

        switch (role) {
        case '1': {
            patient::s_patientmain();
            break;
        }
        case '2': {
            doctor::s_doctormain();
             break;
        }
        case '3': {
            pharmacist::pharmacistmain();
            break;
        }

        default:
            std::cout << "Invalid Choice. Try Again" << std::endl;
        }
        break; // Exit the loop once a valid role is chosen
    }
}

	