//Name: Shiva Mani Goundar ID: S11208749
//Name: Prashant Reddy	   ID: S11213580

//--------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>  
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include"Record.h"

using namespace std;

//function prototyping
float Roundoff(float Value, int NumPlaces);
void bubbleSortbyVAC(Record *aRecord);
void PrintCitizen(Record *Krecord);
void PrintVaccination(Record *Krecord, Record *VC, Record *Vacc, Record *Citi);
void Menu4(Record *Krecord, Record *citi);
void Menu6(Record *Krecord, Record *citi, Record *Vacc);
void Menu5(Record *Krecord, Record *Citi, Record *Vacc);
void setcitizenVaccinated(Record *Krecord, Record *rcitizen, Record *Rvaccinated ,Record *Rvaccine);
void read_citizens(Record *Krecord, bool &filecitizen);
void read_vaccination(Record *Krecord, bool &filevaccination);
void read_vaccines(Record *Krecord, bool &filevaccine);

int main() 
{
	//Declaration for boolean
	bool filecitizen = false;
	bool filevaccination = false;
	bool filevaccine = false;
	
	//Class declaration
	Record Rcitizen = Record();
	Record Rvaccinated = Record();
	Record Rvaccine = Record();
	Record RCV = Record();
	
	//Calling reading functions to read files
	read_citizens(&Rcitizen, filecitizen);
	read_vaccination(&Rvaccinated, filevaccination);
	read_vaccines(&Rvaccine, filevaccine);
	Node *iter = Rvaccinated.getHead();
	Node *PCiti = Rcitizen.getHead();
	Node *PVac = Rvaccine.getHead();
	Node *CV =RCV.getHead();
	setcitizenVaccinated(&RCV, &Rcitizen, &Rvaccinated, &Rvaccine);
	
	//initializing varibles for options
	int choice;
	int num_1 = 1;
	int num_2 = 2;
	int num_3 = 3;
	int num_4 = 4;
	int num_5 = 5;
	int num_6 = 6;

	if(filevaccine && filevaccination && filecitizen )
	{
		cout << "----------------------------------------------------------" << endl;
		cout << "\tWelcome To Vaccination Reports And Analysis" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "\tEnter 1 To Exit The Programme" << endl;
		cout << "\tEnter 2 To Print The Citizens" << endl;
		cout << "\tEnter 3 To Print Vaccination data" << endl;
		cout << "\tEnter 4 To Search Citizen Using Their ID's" << endl;
		cout << "\tEnter 5 To Print Recommendation" << endl;	
		cout << "----------------------------------------------------------" << endl;

		while(choice != num_1)
		{
			cout << "\n\n Enter Your Choice between 1 to 5: ";
			cin >> choice;
			cout << endl;
		
			if (cin.fail())
			{
				cin.clear();
				string dummy;
				cin >> dummy;
				cout << "----------------------------------------------------------" << endl;
				cout << "Invalid Input: '" << dummy << "' Please Enter your numbers between 1 to 5" << endl;
				cout << "----------------------------------------------------------" << endl;
			}
		
			else if (choice==num_2)
			{
				//Calling function 2
				PrintCitizen(&Rcitizen);
				cout<<endl<<endl;
			}
				
			else if (choice==num_3)
			{
				//Calling function 3
				PrintVaccination(&RCV, &Rvaccinated, &Rvaccine, &Rcitizen);
				cout<<endl<<endl;
			}
			
			else if (choice==num_4)
			{
				//Calling function 4
				Menu4(&RCV, &Rcitizen);
				cout<<endl<<endl;
				
			}
			
			else if (choice==num_5)
			{
				//Calling function 5
				Menu5(&RCV, &Rcitizen, &Rvaccine);
				cout<<endl<<endl;
			
			}
			
			else if (choice==num_6)
			{
				//Calling function 6
				Menu6(&RCV, &Rcitizen, &Rvaccine);
				cout<<endl<<endl;
			}
			
			else if(choice < num_1 || choice > num_6)
			{
				cout << "----------------------------------------------------------" << endl;
				cout << "Invalid Input: '" << choice << "' Please Enter your numbers between 1 to 5" << endl;
				cout << "----------------------------------------------------------" << endl;
			}
		}
	}
	return 0;
}

//------------------------------------------------------------------------------------------------------------------
//Function to convert to 2 decimal place
float Roundoff(float Value, int NumPlaces)
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

//------------------------------------------------------------------------------------------------------------------
//function to sort vac
void bubbleSortbyVAC(Record *aRecord)
{
	Vaccination *temp = new Vaccination();
	Node *iter = aRecord->head;
	Node *T = aRecord->head;
	
	while(iter !=NULL)
	{
		T=T->next;
		
		if (iter->getVaccination()->getnum_vac()<T->getVaccination()->getnum_vac())
	    { 
	        temp=iter->getVaccination();
	        iter->setVaccinated(iter->next->getVaccination());
	    	iter->next->setVaccinated(temp);
		}
		
		iter=iter->next;
	}   
}

//------------------------------------------------------------------------------------------------------------------
//function to print citizens
void PrintCitizen(Record *Krecord)
{
	//bubbleSortbyFname(Krecord);	
	cout << "-----------------------------------------------------------------------" << endl;
    cout << "CID\tFname\tLname\tGender\t\tAge\tPhone\tAddress" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    
    Node *iter = Krecord->tail;
    int num;
    
	while(iter!=NULL)
	{
		cout << iter->getCitizen()->getc_id() << "\t" << iter->getCitizen()->getfname() << " " << iter->getCitizen()->getlname() << "\t" << iter->getCitizen()->getgender() << "\t\t" << iter->getCitizen()->getage()<<"\t" << iter->getCitizen()->getphone() << "\t" << iter->getCitizen()->getaddress() << endl;
		iter = iter->prev;
		num++;
	}
	
	cout << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "Total users: " << num << endl;
	cout << "-----------------------------------------------------------------------" << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
void PrintVaccination(Record *Krecord, Record *VC, Record *Vacc, Record *Citi)
{
	int num = Krecord->getNumRecord();
	
	cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "C ID\tFull Name\tAge\t#Vac\tV1 name\t\tV1 Date\t\tV2 name\t\tV2 Date\t\tBooster Name\tBooster Date" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
 	
	Node *iter=Krecord->head;
 	Node *vc=VC->head;
 	Node *vcc=Vacc->head;
 	
	double vac1 = 0;
	double vac2 = 0;
	double vac3 = 0;
	
	//bubbleSortbyVAC(iter);
	//To print all the records
	for(int i=0; i<Krecord->NumRecord;i++)
 	{
 		cout<<iter->getCV()->getc_id()<<"\t"<<iter->getCV()->getfullname()<<"\t"<<iter->getCV()->getage()<<"\t";
 		
		if(iter->getCV()->getnum_vac()==1)
		{
			vac1++;
		}
		
		else if(iter->getCV()->getnum_vac()==2)
		{
			vac2++;
		}
		
		else
		{
			vac3++;
		}
		
		cout << iter->getCV()->getnum_vac()<< "\t" << iter->getCV()->getV1name()<< "\t" << iter->getCV()->getV1_date();

		if (iter->getCV()->getnum_vac() >= 2)
		{
			cout << "\t" << iter->getCV()->getV2name()<< "\t" << iter->getCV()->getV2_date();
		}
		
		else
		{
			cout<<"\t\t";
		}	
	
		if(iter->getCV()->getnum_vac() >= 3)
		{
			cout << "\t" << iter->getCV()->getBname()<< "\t" << iter->getCV()->getB_date();
		}
		
		else
		{
			cout << "\t";
		}
		
		cout << endl;
		iter = iter->next;
	}
	
	double per=Citi->getNumRecord();
	double pe=Krecord->getNumRecord();
	int total = 100;
	per=((pe/per )*total);
	
	cout<<"------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Total Vaccinated: " << Krecord->getNumRecord() << " out of " << Citi->getNumRecord() << " citizens: " << Roundoff(per,2) << "%" << endl;
	cout << "Partial vaccinated: " << Roundoff((vac1/pe) * total,2) <<"%" << endl;
	cout << "Fully Vaccinated: " << Roundoff((vac2/pe) * total,2) <<"%" << endl;
	cout << "Fully Vaccinated with Booster: " << Roundoff((vac3/pe) * total,2) << "%" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
//function to print Citizen info
void Menu4(Record *Krecord, Record *citi)
{
	int key;
	cout << "Please enter the search ID: ";
	cin >> key;
	int CV = 0;
	
	Node *iter = Krecord->getHead();
	Node *temp = citi->getHead();

	for(int i=0;i<Krecord->getNumRecord();i++)
	{
		if(iter->getCV()->getc_id() == key)
		{
			break;
		}
		
		iter=iter->next;
	}
	
	cout<<"------------------------------------------------------"<<endl;
	cout<<"Citizen ID: "<<iter->getCV()->getc_id()<<endl;
	cout<<"Name: \t "<<iter->getCV()->getfullname()<<endl;
	cout<<"Gender:  ";
	
	if(iter->getCV()->getgender()=='M')
	{
		cout<<"Male"<<endl;
	}
	
	else
	{
		cout<<"Female"<<endl;
	}
	
	cout<<"Age: \t "<<iter->getCV()->getage()<<endl;
	
	for(int i = 0; i < citi->getNumRecord(); i++)
	{
		if(temp->getCitizen()->getc_id() == iter->getCV()->getc_id())
		{
			cout << "Phone: \t " << temp->getCitizen()->getphone() << endl;
			cout << "Address: " << temp->getCitizen()->getaddress() << endl;
			break;
		}
		
		temp=temp->next;
	} 
	
	cout<<"------------------------------------------------------"<<endl;
	cout<<"Vaccination Detail:"<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<"Number of Vaccines: "<<iter->getCV()->getnum_vac()<<endl;
	
	for(int k=0;k<iter->getCV()->getnum_vac();k++)
	{
		if (k==2)
		{
			cout<<"Booster:\t";
			cout<<iter->getCV()->getBname()<<"\tBooster date: ";
			cout<<iter->getCV()->getB_date()<<endl;
		}
		
		else if(k==1)
		{
			cout<<"Vaccination "<<k+1<<": ";
			cout<<iter->getCV()->getV2name()<<"\tVaccination Date: ";
			cout<<iter->getCV()->getV2_date()<<endl;
		}
		
		else if(k==0)
		{
			cout<<"Vaccination "<<k+1<<": ";
			cout<<iter->getCV()->getV1name()<<"\tVaccination Date: ";
			cout<<iter->getCV()->getV1_date()<<endl;
		}
	}
	
	if(iter->getCV()->getnum_vac()==1)
	{
		cout<<"Vaccinated Status: Partially Vaccinated"<<endl; 
	}
	
	else if(iter->getCV()->getnum_vac()==2)
	{
		cout<<"Vaccinated Status: Fully Vaccinated "<<endl;
	}
	
	else
	{
		cout<<"Vaccinated Status: Fully Vaccinated with Booster"<<endl;
	}
	
	cout<<"------------------------------------------------------"<<endl;
}

//-------------------------------------------------------------------------------------------------------------------------------
//function to print recommendation
void Menu5(Record *Krecord, Record *Citi, Record *Vacc)
{
	int C = 16793183;
	int N = 0;
	Node *iter=Krecord->getHead();
	Node *temp=Citi->getHead();
	Node *vacc=Vacc->getHead();
	
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"C ID\tFull Name\tAge\t#Vac\tVaccination Status\t\t\tRecommendation"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	
	
	//bubbleSortbyage(Krecord);
	for (int i=0;i<Krecord->getNumRecord();i++)
 	{
		if(iter->getCV()->getnum_vac()==1)
		{
			cout<<"Partially Vaccinated\t\t\t"; 
		}
		
		else if(iter->getCV()->getnum_vac()==2)
		{
			cout<<"Fully Vaccinated\t\t\t";
		}
		
		else
		{
			cout<<"Fully Vaccinated with Booster\t\t";
		}
		
		cout<<iter->getCV()->getc_id() << "\t" << iter->getCV()->getfullname()<<"\t"<<iter->getCV()->getage()<<"\t"<<iter->getCV()->getnum_vac()<<"\t";
	}
	
	for (int i=0;i<Krecord->getNumRecord();i++)
 	{		
		for(int j=0;j<Citi->getNumRecord();j++)
 		{
 			if(Vacc==NULL)
			{
				temp = Citi->getHead();
			}
 			
 			if(temp->getCitizen()->getc_id()==iter->getCV()->getc_id())
 			{
 				if(temp->getCitizen()->getage()<=5||temp->getCitizen()->getage()>=60)
 				{
 					if(iter->getCV()->getnum_vac()==1)
 					{
 						int D_left=C-iter->getCV()->getV1_date();
 						for(int k=0;k<Vacc->getNumRecord();k++)
 						{
 							if(iter->getCV()->getV1name()==vacc->getVaccine()->getvaccine_name())
 							{
 								if(D_left<vacc->getVaccine()->getvaccine_minspace())
 								{
 									cout<<D_left<<" number of days left for second shot."<<endl;
								}
								
								else
								{
									cout<<"Ready for second vaccine: Pfizer"<<endl;
								}
							}
							vacc=vacc->next;
						}
					}
					
					else if(iter->getCV()->getnum_vac()==2)
					{
						cout<<"Fully Vaccinated. Booster is not needed."<<endl;
					}
				}
				
				else if(temp->getCitizen()->getage()>=6&&temp->getCitizen()->getage()<=17)
				{
					if(iter->getCV()->getnum_vac()==3)
 					{
						cout<<"Fully Vaccinated with Booster"<<endl;
					}
					else if (iter->getCV()->getnum_vac()==2)
					{
						int D_left=C-iter->getCV()->getV1_date();
 						for(int k=0;k<Vacc->getNumRecord();k++)
 						{
 							if(Vacc==NULL)
							{
								vacc = Vacc->getHead();
							}
							
 							if(iter->getCV()->getV1name()==vacc->getVaccine()->getvaccine_name())
 							{
 								if(D_left<vacc->getVaccine()->getvaccine_minspace()&&D_left<vacc->getVaccine()->getvaccine_minspace())
 								{
 									cout<<D_left<<" number of days left for Booster shot."<<endl;
								}
								
								else if(D_left>vacc->getVaccine()->getvaccine_minspace()&&D_left>vacc->getVaccine()->getvaccine_minspace())
								{
									cout<<"Ready for Booster: Pfizer"<<endl;
								}
							}
							
							vacc=vacc->next;
						}
					}
					
					else
					{
						int D_left=C-iter->getCV()->getV1_date();
 						for(int k=0;k<Vacc->getNumRecord();k++)
 						{
 							if(Vacc==NULL)
							{
								vacc = Vacc->getHead();
							}
							
 							if(iter->getCV()->getV1name()==vacc->getVaccine()->getvaccine_name())
 							{
 								if(D_left<vacc->getVaccine()->getvaccine_minspace())
 								{
 									cout<<D_left<<" number of days left for second shot."<<endl;
								}
								
								else
								{
									cout<<"Ready for second vaccine: Moderna"<<endl;
								}
							}
							vacc=vacc->next;
						}
					}
				}
				
				else if(iter->getCV()->getage()>=18&&iter->getCV()->getage()<=59)
				{
					if(iter->getCV()->getnum_vac()==1)
 					{
 						int D_left=C-iter->getCV()->getV1_date();
 						for(int k=0;k<Vacc->getNumRecord();k++)
 						{
 							if(Vacc==NULL)
							{
								vacc = Vacc->getHead();
							}
							
 							if(iter->getCV()->getV1name()==vacc->getVaccine()->getvaccine_name())
 							{
 								if(D_left<vacc->getVaccine()->getvaccine_minspace())
 								{
 									cout<<D_left<<" number of days left for second shot."<<endl;
								}
								
								else
								{
									cout<<"Ready for second vaccine: AstraZeneca"<<endl;
								}
							}
							vacc=vacc->next;
						}
					}
					
					else if(iter->getCV()->getnum_vac()==2)
					{
						int D_left=C-iter->getCV()->getV1_date();
 						for(int k=0;k<Vacc->getNumRecord();k++)
 						{
 							if(Vacc==NULL)
							{
								vacc = Vacc->getHead();
							}
							
 							if(iter->getCV()->getV1name()==vacc->getVaccine()->getvaccine_name())
 							{
 								if(D_left<vacc->getVaccine()->getvaccine_minspace()&&D_left<vacc->getVaccine()->getvaccine_minspace())
 								{
 									cout<<D_left<<" number of days left for Booster shot."<<endl;
								}
								
								else if(D_left>vacc->getVaccine()->getvaccine_minspace()&&D_left>vacc->getVaccine()->getvaccine_minspace())
								{
									cout<<"Ready for Booster: Pfizer"<<endl;
								}
							}
							vacc=vacc->next;
						}
					}
					
					else
					{
						cout<<"Fully Vaccinated with Booster"<<endl;
					}
				}
			}
			temp=temp->next;
		}
		iter=iter->next;
	}
	
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
//function to delete a node
void Menu6(Record *Krecord, Record *citi, Record *Vacc)
{
	int key;
	cout << "Please enter the search ID: ";
	cin >> key;
	int CV = 0;
	Node *iter = Krecord->getHead();
	Node *temp = citi->getHead();
	bool f = false;
	
	for(int i=0;i<Krecord->getNumRecord();i++)
	{
		if(iter->getCV()->getc_id()==key)
		{
			f=true;
			break;
		}
		
		else
		{
			iter=iter->next;
		}
	}
	
	if(f)
	{	
		cout<<"\n-----------------"<<endl;
		cout<<"Delete Successful"<<endl;
		cout<<"-----------------"<<endl;
	}
	
	else
	{
		cout<<"ID Not Found"<<endl;
	}
}

//-------------------------------------------------------------------------------------------------------------------------------
//function to set derived class 
void setcitizenVaccinated(Record *Krecord, Record *rcitizen, Record *Rvaccinated ,Record *Rvaccine)
{
	Node *C;

	Node *temp = Rvaccinated->head;
	Node *Vacc = Rvaccine->head;
	Node *iter = rcitizen->head;
	
	while(temp!=NULL)
	{
		CitizenVaccinated *citizenvaccinated = new CitizenVaccinated();
		
		for(int j=0;j<rcitizen->getNumRecord();j++)
		{
			if(iter==NULL)
			{
				iter=rcitizen->getHead();
			}
			
			if (iter->getCitizen()->getc_id()==temp->getVaccination()->getc_id())
 			{
 				citizenvaccinated->setc_id(iter->getCitizen()->getc_id());
 				string fullname=iter->getCitizen()->getfname()+" "+iter->getCitizen()->getlname();
 				citizenvaccinated->setfullname(fullname);
 				citizenvaccinated->setage(iter->getCitizen()->getage());
 				citizenvaccinated->setgender(iter->getCitizen()->getgender());
			}
			
			iter=iter->next;
		}
		
		if (temp->getVaccination()->getnum_vac()==1)
		{
			int vac=1;
			citizenvaccinated->setnum_vac(vac);
		}
		
		else if(temp->getVaccination()->getnum_vac()==2)
		{
			int vac=2;
			citizenvaccinated->setnum_vac(vac);
		}
		
		else if (temp->getVaccination()->getnum_vac()==3)
		{
			int vac=3;
			citizenvaccinated->setnum_vac(vac);
		}
		
		for(int k=0;k<Rvaccine->getNumRecord();k++)
		{
			if(Vacc==NULL)
			{
				Vacc = Rvaccine->head;
			}
			
			if(Vacc->getVaccine()->getvaccine_code()==temp->getVaccination()->getV1_code())
			{
				citizenvaccinated->setV1name(Vacc->getVaccine()->getvaccine_name());
			}
			
			Vacc=Vacc->next;
		}
		
		citizenvaccinated->setV1_date(temp->getVaccination()->getV1_date());
		
		for(int k=0;k<Rvaccine->getNumRecord();k++)
		{
			if(Vacc==NULL)
			{
				Vacc = Rvaccine->head;
			}
			
			if(Vacc->getVaccine()->getvaccine_code()==temp->getVaccination()->getV1_code())
			{
				citizenvaccinated->setV2name(Vacc->getVaccine()->getvaccine_name());
			}
			
			Vacc=Vacc->next;
		}
		
		citizenvaccinated->setV2_date(temp->getVaccination()->getV2_date());
		
		for(int k=0;k<Rvaccine->getNumRecord();k++)
		{
			if(Vacc==NULL)
			{
				Vacc = Rvaccine->head;
			}
			
			if(Vacc->getVaccine()->getvaccine_code()==temp->getVaccination()->getV1_code())
			{
				citizenvaccinated->setBname(Vacc->getVaccine()->getvaccine_name());
			}
			
			Vacc=Vacc->next;
		}
		
		citizenvaccinated->setB_date(temp->getVaccination()->getB_date());
		
		Node *anode = new Node();
		anode->setCV(citizenvaccinated);
		
		if (Krecord->head == NULL)
		{
			Krecord->head = anode;
			Krecord->tail = anode;
		}
		
		else
		{
			Krecord->tail->next = anode;
			anode->prev = Krecord->tail;
			Krecord->tail = anode;
		}
			
		Krecord->NumRecord++; 
		temp=temp->next;
	}	
}

//-------------------------------------------------------------------------------------------------------------------------------
//function to read citizens
void read_citizens(Record *Krecord, bool &filecitizen)
{
	char discard[100];
	string c_id;
	string fname;
	string lname;
	string gender;
	string age;
	string phone;
	string address;
    
    //Opening the file
	ifstream infile;
	infile.open("citizens.txt", ios::in);

	if(!infile)
	{
		cout<<"citizens.txt could not be opened";
	}
	else
	{	
		//discards the first line of the input file
		infile.getline(discard, 100, '\n');	
		
		//While loop to read and store from the files
		while(infile >> c_id >> fname >> lname >> gender >> age >> phone >> address)
		{
			Citizen *acitizen = new Citizen();
			int id;
			char gen;
			int ag;
			int pho;
			
			stringstream as;
			as << c_id;  
			as >> id;
			stringstream bs;
			bs << gender;  
			bs >> gen;
 			stringstream cs;
			cs << age;  
			cs >> ag;
 			stringstream ds;
			ds << phone;  
			ds >> pho;
			
			acitizen->setCitizen(id,fname,lname,gen,ag,pho,address);
			Node *anode = new Node();
			anode->setCitizen(acitizen);
			Krecord->AddNewCitizenVaccinated(anode);
			
		}
		//if the file succesfully opens
		filecitizen=true;
	}
	
	//Closing the file
	infile.close();
    
};

//-------------------------------------------------------------------------------------------------------------------------------
//function to read vaccination
void read_vaccination(Record *Krecord, bool &filevaccination)
{
	//Opening the file
	ifstream infile;
	char discard[100];
	string vc_id;
	string num_vac;
	string V1_code;
	string V1_date;
	string V2_code;
	string V2_date;
	string B_code;
	string B_date;
	
	infile.open("vaccination.txt", ios::in);
	
	//Checking if file is open
	if(!infile)
	{
		cout<<"vaccination.txt could not be opened";
	}
	
	else
	{	
		//discards the first line of the input file
		infile.getline(discard, 100, '\n');
		
		//loop to read and store from the files
		while(infile >> vc_id >> num_vac >> V1_code >> V1_date >> V2_code >> V2_date >> B_code >> B_date)
		{
			Vaccination *aVaccination = new Vaccination();
			stringstream ss; 
			int id;
			int inum_vac;
			int iV1_code;
			int iV1_date;
			int iV2_code;
			int iV2_date;
			int iB_code;
			int iB_date;
			
			//Using string stream to convert from string to appropriate data type
			stringstream as;
			as << vc_id;  
			as >> id;
			stringstream bs;
			bs << num_vac;  
			bs >> inum_vac;
			stringstream cs;
			cs << V1_code;  
			cs >> iV1_code;
			stringstream ds;
			ds << V1_date;  
			ds >> iV1_date;
			stringstream es;
			es << V2_code;  
			es >> iV2_code;
			stringstream fs;
			fs << V2_date;  
			fs >> iV2_date;
			stringstream gs;
			gs << B_code;  
			gs >> iB_code;
			stringstream hs;
			hs << B_date;  
			hs >> iB_date;
			
			aVaccination->setVaccination(id, inum_vac, iV1_code, iV1_date, iV2_code, iV2_date, iB_code, iB_date);
			Node *anode = new Node();
			anode->setVaccinated(aVaccination);
			Krecord->AddNewCitizenVaccinated(anode);
		}
		
		//if the file succesfully opens
		filevaccination=true;
	}
	
	//Closing the file
	infile.close();
};

//-------------------------------------------------------------------------------------------------------------------------------
//Void function to read vaccines
void read_vaccines(Record *Krecord, bool &filevaccine)
{
	//Opening the file
	ifstream infile;
	infile.open("vaccines.txt", ios::in);
	
	char discard[100];
	string vaccine_code;
	string vaccine_name;
	string vaccine_minspace;

	//Checking if file is open
	if(!infile)
	{
		cout<<"vaccines.txt could not be opened";
	}
	else
	{
		//discards the first line of the input file
		infile.getline(discard, 100, '\n');	
		
		//While loop to read and store from the files
		while(infile >> vaccine_code >> vaccine_name >> vaccine_minspace)
		{
			Vaccine *aVaccine = new Vaccine();
			
			int ivaccine_code;
			int ivaccine_minspace;
			
			//Using string stream to convert from string to appropriate data type
			stringstream ss;
			ss << vaccine_code;  
			ss >> ivaccine_code;
			stringstream fs;
			fs << vaccine_minspace;  
			fs >> ivaccine_minspace;
			
			aVaccine->setVaccine(ivaccine_code, vaccine_name, ivaccine_minspace);
			Node *anode = new Node();
			anode->setVaccine(aVaccine);
			Krecord->AddNewCitizenVaccinated(anode);
		}
	
		//if the file succesfully opens	
		filevaccine=true;
	}

	//Closing the file	
	infile.close();	
};
