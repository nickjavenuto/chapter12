//nick venuto
//Feb.18.2020
//This program uses setprecision and fixed manipulators to format file output

#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std; 

int main()
{
	fstream dataFile;
	double num = 17.816392; 

	dataFile.open("numfile.txt", ios::out); //Open in output mode
	
	dataFile << fixed; //Format for fixed-point notation
	dataFile << num << endl; //Write the number
	
	dataFile << setprecision(4); //Format for 4 decimal places
	dataFile << num << endl; //Write the number

	dataFile << setprecision(3); //Format for 3 decimal places
	dataFile << num << endl; 

	cout << "Done\n"; 
	dataFile.close(); //Close the file
	
	//This program writes three rows of numbers to a file
	const int ROWS = 3; 
	const int COLS = 3; 
	int nums[ROWS][COLS] = { 2897, 5, 837, 34, 7, 1623, 390, 3456, 12 }; 
	fstream outFile("table.txt", ios::out); 


	//Write the three rows of numbers with each number in a field of 8 character spaces
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			outFile << setw(8) << nums[row][col]; 
		}
		outFile << endl; 
	}
	outFile.close(); 
	cout << "Done.\n"; 

	
	return 0; 
}