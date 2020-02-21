//nick venuto
//February 19, 2020
//This program demonstrates reading from one file and writing to a second file
#include<iostream>
#include<fstream>
#include<string>
#include<cctype>//Needed for the toupper function
using namespace std; 

int main()
{
	string fileName; //To hold the file name
	char ch; //to hold a character
	ifstream inFile; //input file

	//open a file for output
	ofstream outFile("out.txt"); 

	//Get the input file name
	cout << "Enter a file name: "; 
	cin >> fileName; 

	//Open the file for input
	inFile.open(fileName); 

	//if the input file opened successfully, continue.
	if (inFile)
	{
		//read a char from file 1
		inFile.get(ch);

		//While the last read operation was successful, continue
		while (inFile)
		{
			//Write the uppercase char to file 2
			outFile.put(toupper(ch));
			//Read another char from file 1
			inFile.get(ch);
		}
		//Close the two files
		inFile.close();
		outFile.close();
		cout << "File conversion done.\n";
	}
	else
		cout << "Cannot open " << fileName << endl; 
	return 0; 

}