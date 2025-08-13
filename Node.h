#include"CitizenVaccinated.h"

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
	private:
	CitizenVaccinated *nCV;	
	Citizen *nCitizen;	
	Vaccination *nVaccination;	
	Vaccine *nVaccine;	
	int NumCitizen;
	int vaccination_counter;
	int vaccine_counter;
		 
	public:
	Node *next;
	Node *prev;
	Node();
	void setCV(CitizenVaccinated *aCitizenVaccinated);
	void setCitizen(Citizen *aCitizen);
	void setVaccinated(Vaccination *aVaccination);
	void setVaccine(Vaccine *aVaccine);
	int getNumCitizen();
	int getvaccination_counter();
	int getvaccine_counter();
	CitizenVaccinated *getCV();
	Citizen *getCitizen();
	Vaccination *getVaccination();
	Vaccine *getVaccine();
};

#endif
