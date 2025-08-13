#include "Citizen.h"

//use of Constructor
Citizen::Citizen()
{
	c_id = 0;
	fname = "";
	lname = "";
	gender= ' ';
	age = 0;
	phone = 0;
	address = "";
}

//Setting a Citizen
void Citizen::setCitizen(int c_id, string fname, string lname, char gender, int age, int phone, string address)
{
	this -> c_id = c_id;
	this -> fname = fname;
	this -> lname = lname;
	this -> gender = gender;
	this -> age = age;
	this -> phone = phone;
	this -> address = address;
}

int Citizen::getc_id()
{
	return this->c_id;
}

string Citizen::getfname()
{
	return this->fname;
}
string Citizen::getlname()
{
	return this->lname;
}

char Citizen::getgender()
{
	return this->gender;
}

int Citizen::getage()
{
	return this->age;
}

int Citizen::getphone()
{
	return this->phone;
}

string Citizen::getaddress()
{
	return this->address;
}
