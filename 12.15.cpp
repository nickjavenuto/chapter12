//nick venuto
//Feb. 19, 2020
//This program uses a structure variable to store a record to a file.
#include<iostream>
#include<fstream>
using namespace std; 

//Array sizes
const int nameSize = 51, addrSize = 51, phoneSize = 14; 

//Declare a structure for the record
struct Info
{
	char name[nameSize]; 
	int age; 
	char address1[addrSize]; 
	char address2[addrSize]; 
	char phone[phoneSize]; 
};

int main()
{
	Info person; //To hold info about a person
	char again; //To hold Y or N

	//Open a file for binary output
	fstream people("people.dat", ios::out | ios::binary); 

	do
	{
		//Get data about a person
		cout << "Enter the following data about a person:\n"; 
		cout << "Name: "; 
		cin.getline(person.name, nameSize); 
		cout << "Age: "; 
		cin >> person.age; 
		cin.ignore(); //skip over remaining new line
		cout << "Address line 1: ";
		cin.getline(person.address1, addrSize); 
		cout << "Address line 2: "; 
		cin.getline(person.address2, addrSize); 
		cout << "Phone: "; 
		cin.getline(person.phone, phoneSize); 

		//Write the contents of the person structure to the file
		people.write(reinterpret_cast<char*>(&person), sizeof(person)); 

		//Determine rather the user wants to write another record
		cout << "Do you want another record? Y or N"; 
		cin >> again; 
		cin.ignore(); 
	} while (again == 'Y' || again == 'y'); 

	//Close the file
	people.close(); 
	return 0; 
}