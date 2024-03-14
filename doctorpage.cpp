#include "doctorpage.h"
#include "patientpage.h"



void doctor::dLogin() {
	string dlog_username;
	string dlog_pswd;
	int dlog_id;

	bool found = false;

		cout << endl << "---- Welcome to the Doctor/Nurse Login Page ----" << endl;
		while (cout << "Please Enter your Id Number: " << endl && !(cin >> dlog_id)) {
			cin.clear();
			string temp;
			getline(cin, temp);
			cout << "Invalid input, please re-enter.\n"; //handles invalid data input
		}
		cout << "Please enter your username: " << endl;
		cin >> dlog_username;
		cout << "Enter your password: " << endl;
		cin >> dlog_pswd;

		ifstream inputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\doctorsinfo.csv");
		if (inputFile.is_open()) {
			string line;

			while (getline(inputFile, line)) {
				stringstream ss(line);
				string duserid, dusername, dpswd; //vairbales are taken from csv file for comaprion to login 

				getline(ss, duserid, ',');
				getline(ss, dusername, ',');
				getline(ss, dpswd, ','); 

				int Did_int = stoi(duserid);

				if (Did_int == dlog_id && dusername == dlog_username && dpswd == dlog_pswd) { //allwos comparision fo stored variables to inputted vairables 
					cout << endl << "----Login was SUCCESSFUL!----" << endl;
					found = true;
					dChoice();
					// Redirect to main menu
					break;
				}
			}
			inputFile.close(); // Close the file after reading
		}

		if (!found) {
			cout << endl << "Your details are incorrect. Please Try Again" << endl;
			dLogin();
		}
	}


void doctor::dSignup() {
	cout << endl << "---- You have choosen to create a new Doctor/Nurse Profile. ----" << endl;
	cout << "Please create a username for the New Doctor/Nurse: " << endl;
	cin >> dusername;
	cout << "Please Enter their First Name: " << endl;
	cin >> dfname;
	cout << "Please Enter their Last Name: " << endl;
	cin >> dlname;
	cout << "Please enter a password: " << endl;
	cin >> duserpswd;
	cout << endl << "--- Your Signup was successful ----" << endl;
	duserid++;
	cout << "Your ID is " << duserid << endl;

	ofstream outputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\doctorsinfo.csv", ios_base::app);
	if (outputFile.is_open()) {
		outputFile << endl << duserid << "," << dusername << "," << duserpswd << "," << dfname << "," << dlname << "," << endl;
		//when a new docotro is created their information will be stored in the format in the csv file 
		outputFile.close();
		dLogin();
	}
	else {
		cout << "An Error Occured. Please Try Again!";
		dLogin();

	}


}
void doctor::dChoice() {
	int option;
	int choice2;
	int dpatientIDtoView;
	int dpatientIDtoEdit;

	cout << endl << "Do you want to \n 1. Sign up a New Nurse/Doctor \n 2. View Patient Information \n 3. Change Patient Information \n 4. View Patient Infographics" << endl;
	cin >> option;

	switch (option) {
	case 1:
		dSignup();
		break;
	case 2:
		cout << "Please Enter the Unique ID of the Patient you want to view: " << endl;
		cin >> dpatientIDtoView;
		DviewPhsitory(dpatientIDtoView); // Remove "int" from the function call
		break;
	case 3:
		cout << "Please Enter the Unique ID of the Patient you want to view: " << endl;
		cin >> dpatientIDtoEdit;
		DeditHistory(dpatientIDtoEdit);
		break;
	case 4:
		//dPinfographics();
		break;
	default:
		cout << "Invalid Option! Please Try again. \n";
		dChoice();
		break;
	}
}


string dconvertCancer(int type) {
	switch (type) {
	case 1:
		return "Yes";
	case 2:
		return "No";
	default:
		return "No History";
	}
}

string dconvertSmoking(int type) {
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

string dconvertDiabetes(int type) {
	switch (type) {
	case 1:
		return "Yes";
	case 2:
		return "No";
	default:
		return "No History";
	}
}

void doctor::DviewPhsitory(int dpatientIDToView) {

	int Dchoice1;

	ifstream inputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\patientsinfo.csv");
	if (inputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream inputString(line);

			string userid, username, pfname, plname, age, diabetes, diabetesType, cancer, cancerType, smoker, smokerfreq, temp;
			getline(inputString, userid, ',');
			getline(inputString, username, ',');
			getline(inputString, temp, ',');
			getline(inputString, pfname, ',');
			getline(inputString, plname, ',');
			getline(inputString, age, ',');
			getline(inputString, diabetes, ',');
			getline(inputString, diabetesType, ',');
			getline(inputString, cancer, ',');
			getline(inputString, cancerType, ',');
			getline(inputString, smoker, ',');
			getline(inputString, smokerfreq, ',');

			// Check if the userid matches the patientIDtoView
			int did_int = stoi(userid);
			if (did_int == dpatientIDToView) {
				// Display patient information
				cout << "Existing Information stored in database for: " << pfname << " " << plname << endl;
				cout << "Age: " << age << endl;

				cout << "Diabetes: " << dconvertDiabetes(stoi(diabetes)) << endl;
				if (diabetes == "1") {
					cout << "Diabetes Type: " + diabetesType + "\n";
				}
				cout << "Cancer: " << dconvertCancer(stoi(cancer)) << endl;
				if (cancer == "1") {
					cout << "Cancer Stage: " + cancerType + "\n";
				}
				cout << "Smoker: " << smoker << endl;
				if (smoker == "1") {
					cout << "Smoker Frequency: " + dconvertSmoking(stoi(smokerfreq)) + "\n";
				}
				// You may add more information as needed
				cout << "----------------------------------------" << endl;
				break; // Stop searching after finding the patient
			}
		}
		inputFile.close(); // Close the file after reading
	}
	else {
		cout << "Unable to open file!" << endl;
	}

	

}

	

void doctor::DeditHistory(int dpatientIDtoEdit) { 
	//this code is to edit information in the CSV file 

	string m_diabetes, m_diabetesType, m_cancer, m_cancerType, m_smoker, m_smokerfreq;

	ifstream inputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\patientsinfo.csv");
	if (inputFile.is_open()) {
		string line;
		while (getline(inputFile, line)) {
			stringstream inputString(line);

			string userid, username, userpswd, pfname, plname, age, diabetes, diabetesType, cancer, cancerType, smoker, smokerfreq, temp;

			getline(inputString, userid, ',');

			int pid_int = stoi(userid);
			if (pid_int == dpatientIDtoEdit) {
				getline(inputString, userid, ',');
				getline(inputString, username, ',');
				getline(inputString, userpswd, ',');
				getline(inputString, pfname, ',');
				getline(inputString, plname, ',');
				getline(inputString, age, ',');
				getline(inputString, diabetes, ',');
				getline(inputString, diabetesType, ',');
				getline(inputString, cancer, ',');
				getline(inputString, cancerType, ',');
				getline(inputString, smoker, ',');
				getline(inputString, smokerfreq, ',');

				cout << "Existing Information stored in database for: " << pfname << " " << plname << endl;

				cout << "Diabetes: " << diabetes << endl;
				if (diabetes == "1") {
					cout << "Diabetes Type: " + diabetesType + "\n";
				}
				cout << "Cancer: " << cancer << endl;
				if (cancer == "1") {
					cout << "Cancer Stage: " + dconvertCancer(stoi(cancerType)) + "\n";
				}
				cout << "Smoker: " << smoker << endl;
				if (smoker == "1") {
					cout << "Smoker Frequency: " + dconvertSmoking(stoi(smokerfreq)) + "\n";
				}

				//in this information the docotr is aksed about new condition of the patient 
				cout << endl << "-------------------------------" << endl;
				cout << "Does the patient still have diabetes?" << endl;
				cin >> m_diabetes;
				cout << "What is the Patients New Diabetes Type?" << endl;
				cin >> m_diabetesType;



				cout << endl << "-------------------------------" << endl;
				cout << "Does the patient still have Cancer?" << endl;
				cin >> m_cancer;
				cout << "What is the Patients New Cancer Stage?" << endl;
				cin >> m_cancerType;



				cout << "----------------------------------------" << endl;

				cout << "Does the patient still smoke?" << endl;
				cin >> m_smoker;
				cout << "How often does the patient smoke?" << endl;
				cin >> m_smokerfreq;
			

				//this code writes to the csv file, it takes the new information and replaces it with the old one based on userid of patient 
				ofstream outputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\patientsinfo.csv", ios_base::app);
				if (outputFile.is_open()) {
					outputFile << pid_int << "," << username << "," << pfname << "," << plname << "," << userpswd << "," << age << "," << diabetes << ","
						<< diabetesType << "," << cancer << "," << cancerType << "," << smoker << "," << smokerfreq << endl;
					cout << endl << "---Your Information has been Successfully stored----" << endl;
				}
				else {
					cout << "An Error Occured. Please Try Again!" << endl;

				}
				outputFile.close();

			}

		}
	}

	else
	cout << endl << "------------------------------------" << endl;
	cout << "     USER INFORMATION NOT FOUND!       ";
	cout << endl << "------------------------------------" << endl;
	dChoice();

}


