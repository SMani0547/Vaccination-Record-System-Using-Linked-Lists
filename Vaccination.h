#include <iostream>
#include <fstream>
#include <iomanip>  
#include <string>
#include <sstream>

#ifndef VACCINATION_H
#define VACCINATION_H

using namespace std;

class Vaccination
{
	private:
	int c_id;
	int num_vac;
	int V1_code;
	int V1_date;
	int V2_code;
	int V2_date;
	int B_code;
	int B_date;
	
	public:
	Vaccination();
	void setVaccination(int c_id,int num_vac,int V1_code,int V1_date,int V2_code,int V2_date,int B_code,int B_date);
	int getc_id();
	int getnum_vac();
	int getV1_code();
	int getV1_date();
	int getV2_code();
	int getV2_date();
	int getB_code();
	int getB_date();
	int get_vaccination_counter();
};

#endif
