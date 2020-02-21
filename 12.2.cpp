//nick venuto
//2/18/2020
//This program uses an fstream object to write data to a file, closes the file, then reopens the file and appends more data.

//This program also Checks a files existence before opening it.  

//This program also opens a file with the file stream object definition statement and shows how to test for errors after opening a file with this technique.
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream dataFile;

	cout << "Opening file...\n";
	dataFile.open("demofile.txt", ios::out); //Open for output
	cout << "Now writing data to the file.\n";
	dataFile << "Jones\n"; //Write line 1
	dataFile << "Smith\n"; //Write line 2
	dataFile << " \n"; //Add Space to differentiate from first file built in 12.1
	
	
	//Close the file
	cout << "Now Closing the File.\n";
	dataFile.close();
	
	cout << "Opening the file again...\n";
	//Open the file in append mode
	dataFile.open("demofile.txt", ios::out | ios::app); 
	cout << "Writing more data to the file.\n";
	dataFile << "Willis\n"; //Write line 3
	dataFile << "Davis\n"; //Write line 4
	//Close the file
	cout << "Now closing the file.\n"; 
	dataFile.close(); 

	cout << "Done."; 

	//Opening a file with the file stream object definition statement
	fstream dataFile2("names.txt",  ios::out); 
	ifstream inputFile("info.txt"); 
	ofstream outputFile("addressess.txt"); 
	ofstream dataFile3("customers.txt", ios::out | ios::app); 
	cout << "\n"; 
	if (!dataFile2)
		cout << "Error opening names.txt\n";
	if (!inputFile)
		cout << "Error opening info.txt\n"; 
	if (!outputFile)
		cout << "Error opening addresses.txt\n"; 
	if (!dataFile3)
		cout << "Error opening customers.txt\n"; 


	//Testing for errors after the file is opened

	ifstream inputFile2("SalesData.txt"); 
	if (!inputFile2)
		cout << "Error opening SalesData.txt\n"; 

	return 0;

}