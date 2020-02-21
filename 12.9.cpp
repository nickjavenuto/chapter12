//nick venuto
//February 19, 2020
//This file demonstrates the getline function with a specified delimiter
#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

int main()
{
	string input; //to hold file input

	//Create file to be read
	fstream dataFile("names2.txt", ios::out); 
	dataFile << "Jayne Murphy$47 Jones Circle$Almond, NC 28702\n$Bobbie Smith$217 Halifax Drive$Canton, NC 28716\n$Bill Hammet$PO Box 121$Springfield, NC 28357\n$"; 
	dataFile.close(); 

	//Reopen the file for input
	dataFile.open("names2.txt", ios::in); 

	//If the file was successfully opened, continue.
	if (dataFile)
	{
		//Read item using $ as a delimiter.
		getline(dataFile, input, '$');

		//While the last read operation was successful, continue
		while (dataFile)
		{
			//Display the last item read
			cout << input << endl;
			//Read an item using $ as the delimiter
			getline(dataFile, input, '$');
		}
		//Close the file
		dataFile.close(); 

	}
	else
	{
		cout << "ERROR: Cannot open the file.\n"; 
	}
	return 0; 
}