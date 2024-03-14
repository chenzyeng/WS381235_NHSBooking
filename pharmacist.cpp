#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "pharmacistpage.h";

using namespace std;




void pharmacist::phLogin() {
	string phlog_username;
	string phlog_pswd;
	int phlog_id;
	
	bool found = false;

		cout << endl << "---- Welcome to the Pharmacist Login Page ----" << endl;
		while (cout << "Please Enter your Id Number: " << endl && !(cin >> phlog_id)) {
			cin.clear(); //this code handles incorrect data input, by doing this it stops the code from crashing
			string temp;
			getline(cin, temp);
			cout << "Invalid input, please re-enter.\n";
		}
		cout << "Please enter your username: " << endl;
		cin >> phlog_username;
		cout << "Enter your password: " << endl;
		cin >> phlog_pswd;

		ifstream inputFile("pharmacistinfo.csv");
		if (inputFile.is_open()) {
			string line;

			while (getline(inputFile, line)) {
				stringstream seprater(line);
				string phuserid, phusername, phpswd; // Add pswd variable for password comparison

				getline(seprater, phuserid, ',');
				getline(seprater, phusername, ',');
				getline(seprater, phpswd, ','); // Read password from CSV

				int Did_int = stoi(phuserid);

				if (Did_int == phlog_id && phusername == phlog_username && phpswd == phlog_pswd) { // Compare password
					cout << endl << "----Login was SUCCESSFUL!----" << endl;
					found = true;
					phChoice();
					// Redirect to patient treatment
					break;
				}
			}
			inputFile.close(); // Close the file after reading
		}

		if (!found) {
			cout << endl << "Your details are incorrect. Please Try Again" << endl;
		}
	}


void pharmacist::phSignup() {

	string phusername;
	string phfname;
	string phlname;
	string phuserpswd;

	cout << endl << "---- You have choosen to create a new Pharmacist Profile. ----" << endl;
	cout << "Please create a username for the Pharmacist: " << endl;
	cin >> phusername;
	cout << "Please Enter their First Name: " << endl;
	cin >> phfname;
	cout << "Please Enter their Last Name: " << endl;
	cin >> phlname;
	cout << "Please enter a password: " << endl;
	cin >> phuserpswd;
	cout << endl << "--- Your Signup was successful ----" << endl;
	phuserid++;
	cout << "Your ID is " << phuserid << endl;

	ofstream outputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\pharmacistinfo.csv", ios_base::app);
	if (outputFile.is_open()) {
		outputFile << endl << phuserid << "," << phusername << "," << phuserpswd << "," << phfname << "," << phlname << "," << endl; //stores information in this format in the csv file 
		outputFile.close();
		phLogin();
	}
	else {
		cout << "An Error Occured. Please Try Again!";
		phChoice(); //when incoorect infromation is given. it allws the yuser to try again

	}


}
void pharmacist::phChoice() {
	int option;
	int phpatientIDtoView;

	cout << endl << "Do you want to \n 1. Sign up a Pharmacist \n 2. View Patient Medication \n 3.  Change Patient Medication \n" << endl;
	cin >> option;

	switch (option) {
	case 1:
		phSignup();
		break;
	case 2:
		//to fetch th data from the csv file, patient id has to be entered. 
		cout << "Please Enter the Unique ID of the Patient you want to view: " << endl;
		cin >> phpatientIDtoView;
		phViewData(phpatientIDtoView);
		break;
	case 3:
		cout << "Change P info: " << endl;
		break;
	default:
		cout << "Invalid Option! Please Try again. \n";
		phChoice();
		break;
	}
}

string phconvertCancer(int type) {
	switch (type) {
	case 1:
		return "Yes";
	case 2:
		return "No";
	default:
		return "No History";
	}
}

string phconvertSmoking(int type) {
	switch (type) {
	case 1:
		return "1 Pack a Month";
	case 2:
		return "1 Pack a Week";
	case 3:
		return "1 Pack a Day";
	default:
		return "No History";
	}
}

string phconvertDiabetes(int type) {
	switch (type) {
	case 1:
		return "Yes";
	case 2:
		return "No";
	default:
		return "No History";
	}
}

void pharmacist::phViewData(int phpatientIDtoView) {
	//this allows the paharmaicsists to look a thte condition of the patient 
	ifstream inputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\patientsinfo.csv");
	if (inputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream inputString(line);

			string userid, temp1, pfname, plname, temp2, temp3, diabetes, diabetesType, cancer, cancerType, smoker, smokerfreq, temp;

			getline(inputString, userid, ',');

			int pid_int = stoi(userid);
			if (pid_int == phpatientIDtoView) {
				getline(inputString, userid, ',');
				getline(inputString, temp1, ',');
				getline(inputString, pfname, ',');
				getline(inputString, plname, ',');
				getline(inputString, temp2, ',');
				getline(inputString, diabetes, ',');
				getline(inputString, diabetesType, ',');
				getline(inputString, cancer, ',');
				getline(inputString, cancerType, ',');
				getline(inputString, smoker, ',');
				getline(inputString, smokerfreq, ',');

				cout << "Existing Information stored in database for: " << pfname << " " << plname << endl;

				cout << "Diabetes: " << phconvertDiabetes(stoi(diabetes)) << endl;
				if (diabetes == "1") {
					cout << "Diabetes Type: " + diabetesType + "\n";
				}
				cout << "Cancer: " << phconvertCancer(stoi(cancer)) << endl;
				if (cancer == "1") {
					cout << "Cancer Stage: " + cancerType + "\n";
				}
				cout << "Smoker: " << phconvertSmoking(stoi(smoker)) << endl;
				if (smoker == "1") {
					cout << "Smoker Frequency: " + smokerfreq + "\n";
				}

			}
		}

	inputFile.close();
	}
}

	