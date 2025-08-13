#include"Record.h"

//use of constructor
Record::Record()
{
	this->head=NULL;
	this->tail=NULL;
	NumRecord=0;
}

//function for Roundx
float Record::Roundoff(float Value, int NumPlaces)
{
	int k, Temp;
	float Factor;
	Factor = 1;
	
	for (k = 0; k < NumPlaces; k++)
	{
		Factor = Factor * 10;
	}
	
	Temp = Value * Factor + 0.5;
	return Temp / Factor;
}

//function for Creating a CitizenVaccinated
void Record::AddNewCitizenVaccinated(Node *pnode)
{
	if (head == NULL)
	{
	
		head = pnode;
		tail = pnode;
	}
	else
	{
		tail->next = pnode;
		pnode->prev = tail;
		tail = pnode;
	}
	
	this->NumRecord++; 
}

int Record::getNumRecord()
{
	return this->NumRecord;
}

//function to Sort by Vac number
void Record::bubbleSortbyVAC(Node *aRecord)
{
	Node *iter = aRecord;
	CitizenVaccinated *temp = new CitizenVaccinated();
	
	while(iter!=NULL)
	{
		if (iter->getCV()->getnum_vac()<iter->next->getCV()->getnum_vac())
        {
	        temp=iter->getCV();
	        iter->setCV(iter->next->getCV());
	        iter->next->setCV(temp);
		}
		
		iter=iter->next;
	}
}

Node *Record::getHead()
{
	return this->head;
}
