#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>

using namespace std;

class doctor {
public:
	string dusername;
	string dfname;
	string dlname;
	void dSignup();
	void dLogin(); 
	//void dPinfographics();
	void dChoice();
	void DviewPhsitory(int dpatientIDToView);
	void DeditHistory(int dpatientIDtoEdit);

	//code used to generate random user id 
	doctor() {
		srand(time(NULL));
		duserid = rand() % 999999;
	}
	//static function used, allows fuction to be called withut creating an instance of class
	static int s_doctormain() {
		doctor Doctor;
		Doctor.dLogin(); //automatically redirects user to loginpage, so can't create new account
		return 0;
	}


private:
	int duserid;
	string duserpswd;
};












