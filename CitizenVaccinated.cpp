#include"CitizenVaccinated.h"

//use of constructor
CitizenVaccinated::CitizenVaccinated()
{
	c_id=0;
	fullname="";
	age=0;
	num_vac=0;
	V1name="";
	V1_date=0;
	V2name="";
	V2_date=0;
	Bname="";
	B_date=0;
}

int CitizenVaccinated::getc_id()
{
	return this->c_id;
}

void CitizenVaccinated::setc_id(int c_id)
{
	this->c_id=c_id;
}

void CitizenVaccinated::setfullname(string fullname)
{
	this->fullname=fullname;
}

void CitizenVaccinated::setnum_vac(int num_vac)
{
	this->num_vac=num_vac;
}

void CitizenVaccinated::setgender(char gender)
{
	this->gender=gender;
}

void CitizenVaccinated::setage(int age)
{
	this->age=age;
}

void CitizenVaccinated::setV1name(string V1name)
{
	this->V1name=V1name;
}

void CitizenVaccinated::setV1_date(int V1_date)
{
	this->V1_date=V1_date;
}

void CitizenVaccinated::setV2name(string V2name)
{
	this->V2name=V2name;
}

void CitizenVaccinated::setV2_date(int V2_date)
{
	this->V2_date=V2_date;
}

void CitizenVaccinated::setBname(string Bname)
{
	this->Bname=Bname;
}

void CitizenVaccinated::setB_date(int B_date)
{
	this->B_date=B_date;
}

string CitizenVaccinated::getfullname()
{
	return this->fullname;
}

int CitizenVaccinated::getnum_vac()
{
	return this->num_vac;
}

char CitizenVaccinated::getgender()
{
	return this->gender;
}

int CitizenVaccinated::getage()
{
	return this->age;
}

string CitizenVaccinated::getV1name()
{
	return this->V1name;
}

int CitizenVaccinated::getV1_date()
{
	return this->V1_date;
}

string CitizenVaccinated::getV2name()
{
	return this->V2name;
}

int CitizenVaccinated::getV2_date()
{
	return this->V2_date;
}

string CitizenVaccinated::getBname()
{
	return this->Bname;
}

int CitizenVaccinated::getB_date()
{
	return this->B_date;
}
