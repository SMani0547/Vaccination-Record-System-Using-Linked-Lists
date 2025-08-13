#include <iostream>
#include <fstream>
#include <iomanip>  
#include <string>
#include <sstream>

#ifndef VACCINE_H
#define VACCINE_H

using namespace std;

class Vaccine
{

	private:
	int vaccine_code;
	string vaccine_name;
	int vaccine_minspace;

	public:
	Vaccine();
	void setVaccine(int vaccine_code,string vaccine_name,int vaccine_minspace);
	int getvaccine_code();
	string getvaccine_name();
	int getvaccine_minspace();
};

#endif	
