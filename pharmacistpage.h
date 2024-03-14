#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <cstring>
#include "doctorpage.h";


class  pharmacist {
public:
	void phLogin();
	void phSignup();
	void phChoice();
	void phViewData(int phpatientIDtoView);
	void phChangeData();
	

	//this is for userid, this creates a random number
	int phuserid;

	pharmacist() {
		srand(time(NULL));
		phuserid = rand() % 999999;
	}
	//this fuction acts as an entry point for the 'pharmacist role'
	//static means the same, it is applied to everything everytime pharacist main is called phLogin will be applied (stops duplication)
	static int pharmacistmain() { 
		pharmacist Pharmacist;
		Pharmacist.phLogin();
		return 0;
	}
};
