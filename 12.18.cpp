//nick venuto
//February 20th, 2020
//This program randomly reads a record of data from a file
#include<iostream>
#include<fstream>
using namespace std; 



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

//Function Prototypes
long byteNum(int recNum);
void showRec(Info record);

int main()
{
	Info person; //To hold info about a person
	fstream people; //File stream object

	//Open the file for input in Binary mode
	people.open("people.dat", ios::in | ios::binary); 

	//Test for errors
	if (!people)
	{
		cout << "Error opening file. Program aborting.\n"; 
		return 0; 
	}

	//Read and display record 1(second record)
	cout << "Here is record 1: \n"; 
	people.seekg(byteNum(1), ios::beg); 
	people.read(reinterpret_cast<char*>(&person), sizeof(person));
	showRec(person); 

	//Read and display record 0 (first record)
	cout << "\nHere is record 0\n"; 
	people.seekg(byteNum(0), ios::beg); 
	people.read(reinterpret_cast<char*>(&person), sizeof(person)); 
	showRec(person); 

	//Close the file
	people.close(); 
	return 0; 

}

long byteNum(int recNum)
{
	return sizeof(Info) * recNum;
}

void showRec(Info record)
{
	cout << "Name: "; 
	cout << record.name << endl; 
	cout << "Age: " << record.age << endl; 
	cout << "Address Line 1: " << record.address1 << endl; 
	cout << "Address Line 2: " << record.address2 << endl; 
	cout << "Phone: " << record.phone << endl; 
}