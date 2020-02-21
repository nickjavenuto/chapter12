//nick venuto
//February 19th, 2020
//This program uses the getline function to read a line of data from the file.
#include <iostream>
#include<fstream>
#include<string>
using namespace std; 

int main()
{
	string input; //to hold a file input
	fstream nameFile; //File Stream object

	//Open the file in input mode
	nameFile.open("murphy.txt", ios::in); 

	//If the file was successfully opened, continue
	if (nameFile)
	{
		//Read an item from the file.
		getline(nameFile, input); 

		//While the last read operation was successful, continue
		while (nameFile)
		{
			//Display the last item read.
			cout << input << endl; 
			//Read the next item
			getline(nameFile, input);
		}

		//Close the file
		nameFile.close();
	}
	else
	{
		cout << "ERROR: Cannot open file.\n"; 
	}
	return 0; 
}