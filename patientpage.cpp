#include "patientpage.h"
#include <vector>
 
using std::cin;
using std::cout;



void patient::pSignup() { 
	cout << endl << "To sign up, please create a username: " << endl;
	cin >> username;
	cout << "Please Enter your First Name: " << endl;
	cin >> pfname;
	cout << "Please Enter your Last Name: " << endl;
	cin >> plname;

	while (cout << "Please Enter your Age: " << endl && !(cin >> age)) {
		cin.clear();
		string temp;
		std::getline(cin, temp);
		cout << "Invalid input, please re-enter.\n"; //deals with wrong data input
	}


	double insulinCostforaDay = 0.0, insulinCostforaWeek = 0.0, insulinCostforaMonth = 0.0, insulinCostforaYear = 0.0;
	double insulinCostforaDay2 = 0.0, insulinCostforaWeek2 = 0.0, insulinCostforaMonth2 = 0.0, insulinCostforaYear2 = 0.0;
	//these variables are created for calcuation costs

	cout << endl << "Do you have Diabetes? \n1. Yes \n2. No " << endl;
	cin >> diabetes; 
	if (diabetes == "yes" || diabetes == "Yes" || diabetes == "y" || diabetes == "1"){
		totalCost += insulinPshot * 2 * 365;
		cout << "What types of diabetes do you have? \n 1. Type 1 \n 2. Type 2 \n ";
		cin >> diabetesType;
		if (diabetesType = 1) {
			cout << endl << "Insulin Treatment, 2 shots per day" << endl;
			insulinCostforaDay = insulinPshot * 2;
			insulinCostforaWeek = insulinCostforaDay * 7;
			insulinCostforaMonth = insulinCostforaDay * 30;
			insulinCostforaYear = insulinCostforaDay * 365;
			//automotically calauclate costs as patients puts medical information in
		}
		else if (diabetesType = 2) {
			cout << endl << "Insulin Treatment, 1 shots per day" << endl;
			insulinCostforaDay2 = insulinPshot;
			insulinCostforaWeek2 = insulinCostforaDay * 7;
			insulinCostforaMonth2 = insulinCostforaDay * 30;
			insulinCostforaYear2 = insulinCostforaDay * 365;
			//calculation cost for a day year and month for type 2 diabetes 
		}
		else {
			cout << "Invalid Value, Please try Again";
			pSignup();
		}

	}
	else {
		cout << "--You do not have diabetes!---" << endl;
		diabetes = "No";
	}


	
	double totalCoststage1 = 15000;
	double totalCoststage2 = 30000;
	double totalCoststage3 = 120000;

	double chemoCostforaWeek1 = 0.0, chemoCostforaDay1 = 0.0, chemoCostforaMonth1 = 0.0, chemoCostforaYear1 = 0.0;
	double chemoCostforaWeek2 = 0.0, chemoCostforaDay2 = 0.0, chemoCostforaMonth2 = 0.0, chemoCostforaYear2 = 0.0;
	double  chemoCostforaWeek3 = 0.0, chemoCostsforaDay3 = 0.0, chemoCostsforaMonth3 = 0.0, chemoCostsforaYear3 = 0.0;

	//calculation costs for cancer treatments 

	cout << endl << "Do you have Lung Cancer? \n Yes \n No" << endl;
	cin >> cancer;
	if (cancer == "yes" || cancer == "Yes" || cancer == "y" || cancer == "1") {
		cout << "What is the stage of your cancer \n 1. Stage 1 \n 2. Stage 2 \n 3. Stage 3 \n 4. Stage 4 " << endl;
		cin >> cancerType;

		if (cancerType = 1) {
			cout << endl << "Chemotheraphy, Once every 4 Weeks" << endl;
			chemoCostforaWeek1 = totalCoststage1 / (6 * 4);
			chemoCostforaDay1 = chemoCostforaWeek1 / 7;
			chemoCostforaMonth1 = chemoCost;
			chemoCostforaYear1 = chemoCostforaMonth1 * 12;
		}
		else if (cancerType == 2) {
			cout << endl << "Chemotheraphy, Once every 2 Weeks" << endl;
			chemoCostforaWeek2 = totalCoststage2 / (2 * 4);
			chemoCostforaDay2 = chemoCostforaWeek2 / 7;
			chemoCostforaMonth2 = chemoCostforaWeek2 * 4;
			chemoCostforaYear2 = chemoCostforaMonth2 * 12;
		}
		else if (cancerType == 3) {
			cout << endl << "Chemotheraphy, Once every Week" << endl;
			chemoCostforaWeek3 = totalCoststage3 / (12 * 4);
			chemoCostsforaDay3 = chemoCostforaWeek3 / 7;
			chemoCostsforaMonth3 = chemoCostforaWeek3 * 4;
			chemoCostsforaYear3 = chemoCostsforaMonth3 * 12;
		}
		else if (cancerType == 4) {
			cout << endl << "Terminal cancer, No treatment" << endl;
			
		}
	}
	else {
		cout << "--You do not have Cancer!---" << endl;
		cancer = "No";
	}
	//gathering infior

	cout << "Do you Smoke \n 1. Yes \n 2. No" << endl;
	cin >> smoker;
	if (smoker == "yes" || smoker == "Yes" || smoker == "y" || smoker == "1") {
		cout << "How often do you smoke? \n 1. One pack per month \n 2. One pack per week \n 3. One pack per day  ";
		cin >> smokerfreq;
	}
	else {
		cout << "--You do not smoke!---" << endl;
		smoker = "No";
	}

	cout << endl << "Please create a password: " << endl;
	cin >> userpswd;

	
	//stores patient info into patient file
	ofstream outputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\patientsinfo.csv", ios_base::app);
		if (outputFile.is_open()){
			outputFile << userid << "," << username << "," << userpswd << "," << pfname << "," << plname << "," << age << "," << diabetes << "," 
				<< diabetesType << "," << cancer << "," << cancerType << "," << smoker << "," << smokerfreq << endl;
			
		}
		else {
			cout << "An Error Occured. Please Try Again!";
		}
		outputFile.close();

		//stores treatment info into treatment file
		ofstream outputtFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\treatmentcosts.csv", ios_base::app);
		if (outputtFile.is_open()) {
			outputtFile << userid << "," << insulinCostforaDay << "," << insulinCostforaWeek << "," << insulinCostforaMonth << "," << insulinCostforaYear << "," << insulinCostforaDay2 << "," << insulinCostforaWeek2 << "," << insulinCostforaMonth2 << "," << insulinCostforaYear2 << ","
				<< chemoCostforaWeek1 << "," << chemoCostforaDay1 << "," << chemoCostforaMonth1 << "," << chemoCostforaYear1 << "," << chemoCostforaWeek2 << "," << chemoCostforaDay2 << "," << chemoCostforaMonth2 << "," << chemoCostforaYear2 << ","
				<< chemoCostforaWeek3 << "," << chemoCostsforaDay3 << "," << chemoCostsforaMonth3 << "," << chemoCostsforaYear3 << endl;
			outputtFile.close();
		}
		else {
			cout << "An Error Occured. Please Try Again!";
		}
	

		

		cout << endl << "Your ID is " << userid << endl;
		cout << endl << "--- Your Signup was successful ----" << endl;
		userid++;
		

	pLogin();
}

void patient::pLogin() {
	string log_username;
	string log_pswd;
	int log_id;

		cout << endl << "---- Welcome to the Patient Login Page ----" << endl;
		cout << "Please enter your ID number: " << endl;
		cin >> log_id;
		cout << "Please enter your username: " << endl;
		cin >> log_username;
		cout << "Enter your password: " << endl;
		cin >> log_pswd;

		ifstream inputFile("patientsinfo.csv");
		if (inputFile.is_open()) {
			string line;

			while (std::getline(inputFile, line)) {
				stringstream inputString(line);
				string userid, username, userpswd; //input variables for comparions
				
				std::getline(inputString, userid, ',');
				std::getline(inputString, username, ',');
				std::getline(inputString, userpswd, ','); // Read password from CSV

				int id_int = stoi(userid);

				if (id_int == log_id){
					if (username == log_username) {
						if (userpswd == log_pswd) { // Compare password
							cout << endl << "----Login was SUCCESSFUL!----" << endl;
							pLoggedMenu();
							//redirect to logged console 
							return;
						}
					}
				}
			}
		}
		inputFile.close(); // Close the file after reading
		
		cout << endl << "Your details are incorrect. Please Try Again" << endl;
		pChoice();
}


void patient::pChoice() {
	//when a patient logs in they will ave this options displayed on their console 
	int option;
	cout << endl << "Do you want to \n 1. Sign up \n 2. Login \n" << endl;
	cin >> option;

	switch (option)
	{
	case 1:
		pSignup();
		break;
	case 2:
		pLogin();
		break;
	default:
		cout << "Invalid Option! Please Try again. \n";
		pChoice();
		break;
	}
}

void patient::pLoggedMenu() {
	int choice2;
	int patientIDToView;
	string line;
	int userIDsearch;

	cout << endl << "Please choose an option: " << endl;
	cout << "1. View Patient History  \n2. View Patient Costs " << endl;
	cin >> choice2;

	switch (choice2)
	{
	case 1:
		cout << "Please Enter your Unique ID Again: ";
		cin >> patientIDToView;
		viewPatientHistory(patientIDToView); // Remove "int" from the function call
		break;


	case 2:
		cout << "Please Enter your Unique ID Again: ";
		cin >> userIDsearch;
		viewPcosts(userIDsearch);
		break;
	default:
		pLoggedMenu();
		break;

	}


}

string yesDiabetes(int value) { 
//turns interger into numrical values for the doctor to view patient history more clearly 
	switch (value) {
	case 1:
		return "Yes";
	case 2:
		return "No";
	default:
		return "Oops, it broke :-)";
	}
}

string convertCancer(int type) {
//turns interger into numrical values for the doctor to view patient history more clearly 
	switch (type) {
	case 1:
		return "1";
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	default:
		return "No History";
	}
}


string convertSmoking(int type) {
//turns interger into numrical values for the doctor to view patient history more clearly 
	switch (type) {
	case 1:
		return "1 pack per month";
	case 2:
		return "1 pack per week";
	case 3:
		return "1 pack per day";
	default:
		return "No History";
	}
}


void patient::viewPatientHistory(int patientIDtoView) {


	ifstream inputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\patientsinfo.csv");
	if (inputFile.is_open()) {
	//using an if loop makes sure this function is done only when the file is open, if not error message will be displayed
		string line;
		while (std::getline(inputFile, line)) {
			stringstream inputString(line);

			string userid, username, pfname, plname, age, diabetes, diabetesType, cancer, cancerType, smoker, smokerfreq, temp;
			std::getline(inputString, userid, ',');
			std::getline(inputString, username, ',');
			std::getline(inputString, temp, ',');
			std::getline(inputString, pfname, ',');
			std::getline(inputString, plname, ',');
			std::getline(inputString, age, ',');
			std::getline(inputString, diabetes, ',');
			std::getline(inputString, diabetesType, ',');
			std::getline(inputString, cancer, ',');
			std::getline(inputString, cancerType, ',');
			std::getline(inputString, smoker, ',');
			std::getline(inputString, smokerfreq, ',');

			// Check if the userid matches the patientIDtoView
			int id_int = stoi(userid);
			if (id_int == patientIDtoView) {
				// Display patient information
				cout << "User ID: " << userid << endl;
				cout << "Username: " << username << endl;
				cout << "First Name: " << pfname << endl;
				cout << "Last Name: " << plname << endl;
				cout << "Age: " << age << endl;
				cout << "Diabetes: " << convertCancer(stoi(diabetes)) << endl;
				if (diabetes == "1") {
					cout << "Diabetes Type: " + diabetesType + "\n";
				}
				cout << "Cancer: " << cancer << endl;
				if (cancer == "1") {
					cout << "Cancer Stage: " + convertCancer(stoi(cancerType)) + "\n";
				}
				cout << "Smoker: " << smoker << endl;
				if (smoker == "1") {
					cout << "Smoker Frequency: " + convertSmoking(stoi(smokerfreq)) + "\n";
				}
				
				cout << "----------------------------------------" << endl;
				break; 
			}
		}
		inputFile.close(); //close file after reading is done 
	}
	else {
		cout << "Unable to open file!" << endl;
	}


}


//this function is for the patient to view their treatment costs 
void patient::viewPcosts(int userIDsearch) {

	//declaration of variables
		string userid;
		string insulinCostforaDay;
		string insulinCostforaWeek;
		string insulinCostforaMonth;
		string insulinCostforaYear;
		string chemotherapyCostforaDay;
		string chemotherapyCostforaWeek;
		string chemotherapyCostforaMonth;
		string chemotherapyCostforaYear;
		string smokingCostforaDay;
		string smokingCostforaWeek;
		string smokingCostforaMonth;
		string  smokingCostforaYear;

//get informationf from the cs file 
	ifstream inputFile("C:\\Users\\CGRAL17J\\Documents\\NHSBooking\\treatmentcosts.csv");
	if (inputFile.is_open()) {
		string line;

		while (std::getline(inputFile, line)) {
			stringstream inputString(line);
		
			std::getline(inputString, userid, ',');
			std::getline(inputString, insulinCostforaDay, ',');
			std::getline(inputString, insulinCostforaWeek, ',');
			std::getline(inputString, insulinCostforaMonth, ',');
			std::getline(inputString, insulinCostforaYear, ',');
			std::getline(inputString, chemotherapyCostforaDay, ',');
			std::getline(inputString, chemotherapyCostforaWeek, ',');
			std::getline(inputString, chemotherapyCostforaMonth, ',');
			std::getline(inputString, chemotherapyCostforaYear, ',');
			std::getline(inputString, smokingCostforaDay, ',');
			std::getline(inputString, smokingCostforaWeek, ',');
			std::getline(inputString, smokingCostforaMonth, ',');
			std::getline(inputString, smokingCostforaYear, ',');

			//put the csv file into a readble format 
			int pid_int = stoi(userid);
			if (pid_int == userIDsearch) {
				cout << "Treatment Costs for Patient: " << userid << endl;
				cout << "-----------------------------------" << endl;
				if (stoi(insulinCostforaDay) > 0) {
					cout << "Diabetes Treatment Costs:" << endl;
					cout << "In Dollars - Daily: $" << insulinCostforaDay
						<< ", Weekly: $" << insulinCostforaWeek
						<< ", Monthly: $" << insulinCostforaMonth
						<< ", Yearly: $" << insulinCostforaYear << endl;
					cout << "In Pounds - Daily: GBP" << insulinCostforaDay
						<< ", Weekly: GBP" << insulinCostforaWeek
						<< ", Monthly: GBP" << insulinCostforaMonth
						<< ", Yearly: GBP" << insulinCostforaYear << endl;
					cout << endl;
				}
				if (stoi(chemotherapyCostforaDay) > 0) {//converts string into integer
					cout << "Cancer Treatment Costs:" << endl;
					cout << "In Dollars - Daily: $"
						<< chemotherapyCostforaDay
						<< ", Weekly: $" << chemotherapyCostforaWeek
						<< ", Monthly: $" << chemotherapyCostforaMonth
						<< ", Yearly: $" << chemotherapyCostforaYear << endl;

					cout << "In Pounds - Daily: GBP" << chemotherapyCostforaDay
						<< ", Weekly: GBP" << chemotherapyCostforaWeek
						<< ", Monthly: GBP" << chemotherapyCostforaMonth
						<< ", Yearly: GBP" << chemotherapyCostforaYear << endl;
					cout << endl;
				}
				if (stoi(smokingCostforaDay) > 0) { //converts smoking into integer
					cout << "Smoking Cessation Costs:" << endl;
					cout << "In Dollars - Daily: $" << smokingCostforaDay
						<< ", Weekly: $" << smokingCostforaWeek
						<< ", Monthly: $" << smokingCostforaMonth
						<< ", Yearly: $" << smokingCostforaYear << endl;

					cout << "In Pounds - Daily: GBP" << smokingCostforaDay
						<< ", Weekly: GBP" << smokingCostforaWeek
						<< ", Monthly: GBP" << smokingCostforaMonth
						<< ", Yearly: GBP" << smokingCostforaYear << endl;

					cout << "-----------------------------------" << endl;
				}
			}
		


	}


	inputFile.close();
} 


