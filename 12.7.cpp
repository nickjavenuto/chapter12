//nick venuto
//February 19, 2020
//This program demonstrates how the >> operator should not be used to read data that contain whitespace characters from a file
#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

int main()
{
	string input; //To hold file input
	fstream nameFile; //File stream object
	

	//Open the file in input mode.
	nameFile.open("murphy.txt", ios::out); 
	nameFile << "Jayne Murphy\n"; 
	nameFile << "47 Jones Circle\n"; 
	nameFile << "Almond, NC  28702\n"; 
	nameFile.close(); 
	nameFile.open("murphy.txt", ios::in); 

	//If the file was successfully opened, continue
	if (nameFile)
	{
		//Read the file contents
		while (nameFile >> input)
		{
			cout << input; 
		}
		nameFile.close(); 
	}
	else
	{
		cout << "ERROR: Cannont open file. \n";
	}
	return 0; 
}