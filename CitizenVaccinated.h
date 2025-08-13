#include <iostream>
#include <fstream>
#include <iomanip>  
#include <string>
#include <sstream>
#include"Citizen.h"
#include"Vaccination.h"
#include"Vaccine.h"

#ifndef CITIZENVACCINATED_H
#define CITIZENVACCINATED_H

using namespace std;

class CitizenVaccinated
{
	private:
		
	int c_id;
	string fullname;
	char gender;
	int age;
	int num_vac;
	string V1name;
	int V1_date;
	string V2name;
	int V2_date;
	string Bname;
	int B_date;
	
	public:
	CitizenVaccinated();
	void AddCitizenVaccinated(Vaccination *pVaccination, Citizen *pCitizen,Vaccine *pVaccine);
	//Setter Function
	void setc_id(int c_id);
	void setfullname(string fullname);
	void setgender(char gender);
	void setnum_vac(int num_vac);
	void setage(int age);
	void setV1name(string V1name);
	void setV1_date(int V1_date);
	void setV2name(string V2name);
	void setV2_date(int V2_date);
	void setBname(string Bname);
	void setB_date(int B_date);
	//Getter Function
	int getc_id();
	string getfullname();
	char getgender();
	int getage();
	int getnum_vac();
	string getV1name();
	int getV1_date();
	string getV2name();
	int getV2_date();
	string getBname();
	int getB_date();
};

#endif
