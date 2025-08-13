#include "Vaccine.h"

//use of Constructor
Vaccine::Vaccine()
{
	vaccine_code = 0;
	vaccine_name = "";
	vaccine_minspace = 0;
}

//function for Setting a Vaccine
void Vaccine::setVaccine(int vaccine_code,string vaccine_name,int vaccine_minspace)
{
	this -> vaccine_code=vaccine_code;
	this -> vaccine_name=vaccine_name;
	this -> vaccine_minspace=vaccine_minspace;
}


int Vaccine::getvaccine_code()
{
	return this->vaccine_code;
}

string Vaccine::getvaccine_name()
{
	return this->vaccine_name;
}

int Vaccine::getvaccine_minspace()
{
	return this->vaccine_minspace;
}
