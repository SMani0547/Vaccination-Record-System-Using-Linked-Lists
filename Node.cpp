//node to store Citizen Vaccinated
#include"Node.h"

Node::Node()
{
	this->nCV=NULL;
	this->next=NULL;
	this->NumCitizen=0;
	this->vaccination_counter=0;
	this->vaccine_counter=0;
	this->nCitizen=NULL;	
	this->nVaccination=NULL;	
	this->nVaccine=NULL;
}

void Node::setCV(CitizenVaccinated *aCitizenVaccinated)
{
	this->nCV=aCitizenVaccinated;
}

void Node::setCitizen(Citizen *aCitizen)
{
	this->nCitizen=aCitizen;
	this->NumCitizen++;
}

void Node::setVaccinated(Vaccination *aVaccination)
{
	this->nVaccination=aVaccination;
	this->vaccination_counter++;
}

void Node::setVaccine(Vaccine *aVaccine)
{
	this->nVaccine=aVaccine;
	this->vaccine_counter++;
}

CitizenVaccinated *Node::getCV()
{
	return nCV;
}

Citizen *Node::getCitizen()
{
	return nCitizen;
}

Vaccination *Node::getVaccination()
{
	return nVaccination;
}

Vaccine *Node::getVaccine()
{
	return nVaccine;
}

int Node::getNumCitizen()
{
	return this->NumCitizen;
}

int Node::getvaccination_counter()
{
	return this->vaccination_counter;
}

int Node::getvaccine_counter()
{
	return this->vaccine_counter;
}
