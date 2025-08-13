#include <iostream>
#include <fstream>
#include <iomanip>  
#include <string>
#include <sstream>
#include"CitizenVaccinated.h"
#include"Citizen.h"
#include"Vaccination.h"
#include"Vaccine.h"
#include"Node.h"

#ifndef RECORDS_H
#define RECORDS_H

using namespace std;

class Record
{
	//friend functions
	friend void PrintCitizen(Record *aRecord); 
	friend void PrintVaccination(Record *aRecord, Record *VC, Record *Vacc, Record *Citi);
	friend void bubbleSortbyFname(Record *aRecord);
	friend void bubbleSortbyVAC(Record *aRecord);
	friend void setcitizenVaccinated(Record *aRecord);
	friend void Menu4(Record *aRecord);
	friend void Menu5(Record *aRecord);
	friend void bubbleSortbyage(Record *aRecord);
	friend void setcitizenVaccinated(Record *CV, Record *rcitizen, Record *Rvaccinated ,Record *Rvaccine);
	
	private:
	Node *head;
	Node *tail;
	int  NumRecord;

	public:
	Record();
	void AddNewCitizenVaccinated(Node *pnode);
	void PrintCitizenVaccinated();
	void bubbleSortbyVAC(Node *aRecord);
	float Roundoff(float Value, int NumPlaces);
	int getNumRecord();
	int GetCitizenVaccinated(int custidkey);
	Node *getHead();
};

#endif
