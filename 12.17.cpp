//nick venuto
//Feb. 20, 2020
//This program demonstrates the seekg function

#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

int main()
{
	char ch; //To hold a character
	string input; //to hold file data for printing

	//Create a text file with letters 
	fstream file("letters.txt", ios::out); 
	file << "abcdefghijklmnopqrstuvwxyz"; 
	file.close(); 

	//Open a file for input
	file.open("letters.txt", ios::in); 


	//Move to byte 5 from the beginning of the file and read the character there
	file.seekg(5L, ios::beg); 
	file.get(ch); 
	cout << "Byte 5 from beginning: " << ch << endl; 

	//Move to the 10th byte from the end of the file and read the character there
	file.seekg(-10L, ios::end); 
	file.get(ch); 
	cout << "The 10th byte from the end is: " << ch << endl; 
	
	//Move to byte 3 from the current position
	file.seekg(3L, ios::cur); 
	file.get(ch); 
	cout << "Byte 3 from the current: " << ch << endl; 

	file.close(); 
	return 0; 

}