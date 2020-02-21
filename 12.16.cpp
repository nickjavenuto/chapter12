//nick venuto
//February 19, 2020
//This program uses a structure cariable to read a record from a file
#include<iostream>
#include<fstream>
using namespace std; 

const int nameSize = 51, addSize = 51, phoneSize = 14; 

//Declare a structure for the record
struct Info
{
	char name[nameSize]; 
	int age; 
	char address1[addSize]; 
	char address2[addSize]; 
	char phone[phoneSize]; 
};

int main()
{
	Info person; //To hold info about a person
	char again; //Y or N
	fstream people; 

	//Open the file for input in binary form
	people.open("people.dat", ios::in | ios::binary);
	//Test for errors
	if (!people)
	{
		cout << "Error opening file. Program aborted.\n"; 
		return 0; 
	}
	cout << "Here are the people in the file: \n\n"; 
	//Read the first record from the file
	people.read(reinterpret_cast<char*>(&person), sizeof(person)); 

	//While not at the end of the file, display the records
	while (!people.eof())
	{
		//Display the record
		cout << "Name: "; 
		cout << person.name << endl; 
		cout << "Age: "; 
		cout << person.age << endl; 
		cout << "Address line 1: "; 
		cout << person.address1 << endl; 
		cout << "Address line 2: "; 
		cout << person.address2 << endl; 
		cout << "Phone: "; 
		cout << person.phone << endl; 
	
		//Wait for the user to press the Enter key
		cout << "\nPress the Enter key to see the next record.\n"; 
		cin.get(again); 

		//Read the next record from the file
		people.read(reinterpret_cast<char*>(&person), sizeof(person)); 
	}
	cout << "That's all the data in the file\n"; 
	people.close(); 
	return 0; 
}