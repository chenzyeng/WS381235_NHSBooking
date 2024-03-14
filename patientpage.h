#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <cstring>

using namespace std;

class patient{
public:
	string username; //array of characters with size of n
	string pfname;
	string plname;
	string diabetes;
	string smoker;
	string cancer;
	int diabetesType;
	int cancerType;
	int smokerfreq;
	int age;
	double totalCost; 

	//class construcutor - assigns values to object members
	patient(int id, string user, string fname, string lname, int a, string dia, int diaType, string can, int canType, string smk, int smkFreq)
		:userid(id), username(user), pfname(fname),plname(lname), age(a), diabetes(dia), diabetesType(diaType), cancer(can), cancerType(canType), smoker(smk), smokerfreq(smkFreq) {}


	patient() {
		srand(time(NULL));
		// % is modulus operator, basically just a remainder calculation
		// check highest id currently in the csv, add 1 and call it a day
		userid = rand()%999999;
	}

	const double insulinPshot = 7.52;
	const double chemoCost = 10000;
	const double nicotinTabletCost = 5.63;
	const double nicotinPatchCost = 3.64;

	
	const int weeksinMonth = 4;
	const int daysinYear = 365;
	const int Smyears = 2;
	const int sixMonths = 6;
	const int oneYear = 12;



	void pSignup();
	void pLogin();
	void pChoice();
	void pLoggedMenu();
	void viewPatientHistory(int patientIDtoView);
	void viewPcosts(int userIDsearch);

	static int s_patientmain() {
		patient Patient;
		Patient.pChoice();
		return 0;

	}
	

private:
	friend class doctor;
	int userid; 
	string userpswd; 
	
};

