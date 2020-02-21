//nick venuto
//February 19, 2020
//This program demonstrates the put member function.
#include<iostream>
#include<fstream>
using namespace std; 

int main()
{
	char ch; //to hold a character

	//Open the file for output
	fstream dataFile("sentence.txt", ios::out); 

	cout << "Type a sentence and be sure to end it with a period.\n"; 

	//Get a sentence from the user one character at a time and write each character to the file
	cin.get(ch); 
	while (ch != '.')
	{
		dataFile.put(ch); 
		cin.get(ch); 
	}
	dataFile.put(ch); //Write the period
	//Close the file
	dataFile.close(); 
	return 0; 


}