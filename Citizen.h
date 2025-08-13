#include <iostream>
#include <fstream>
#include <iomanip>  
#include <string>
#include <sstream>
#ifndef CITIZEN_H
#define CITIZEN_H

using namespace std;

class Citizen
{
	
	private:
	int c_id;
	string fname;
	string lname;
	char gender;
	int age;
	int phone;
	string address;

	public:
	Citizen();
	void setCitizen(int c_id, string fname, string lname, char gender, int age, int phone, string address);
	int getc_id();
	string getfname();
	string getlname();
	char getgender();
	int getage();
	int getphone();
	string getaddress();
	int getNumCitizen();
};

#endif
