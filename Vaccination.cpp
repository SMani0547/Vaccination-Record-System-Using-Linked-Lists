#include "Vaccination.h"

//use of Constructor
Vaccination::Vaccination()
{
	c_id=0;
	num_vac=0;
	V1_code=0;
	V1_date=0;
	V2_code=0;
	V2_date=0;
	B_code=0;
	B_date=0;
}

//function for Setting Vaccination
void Vaccination::setVaccination(int c_id,int num_vac,int V1_code,int V1_date,int V2_code,int V2_date,int B_code,int B_date)
{
	this->c_id=c_id;
	this->num_vac=num_vac;
	this->V1_code=V1_code;
	this->V1_date=V1_date;
	this->V2_code=V2_code;
	this->V2_date=V2_date;
	this->B_code=B_code;
	this->B_date=B_date;
}

int Vaccination::getc_id()
{
	return this->c_id;
}

int Vaccination::getnum_vac()
{
	return this->num_vac;
}

int Vaccination::getV1_code()
{
	return this->V1_code;
}

int Vaccination::getV1_date()
{
	return this->V1_date;
}

int Vaccination::getV2_code()
{
	return this->V2_code;
}

int Vaccination::getV2_date()
{
	return this->V2_date;
}

int Vaccination::getB_code()
{
	return this->B_code;
}

int Vaccination::getB_date()
{
	return this->B_date;
}
