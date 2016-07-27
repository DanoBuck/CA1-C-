// Daniel Buckley X00109141

#include "dirent.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/***************************************************************************************
*
*    Copied Completely - changed slightly
*    Date: <28/10/2015>
*
*    Availability: http://www.dreamincode.net/forums/topic/59943-accessing-directories-in-cc-part-i/
*
***************************************************************************************/
string start() {
	std::cout << "**********Start Of Plagiarism Detecter***********";
	std::cout << "\n*\t\t\t\t\t\t*";
	std::cout << "\n*\t\t\t\t\t\t*";
	std::cout << "\n*\t Daniel Buckley X00109141\t\t*";
	std::cout << "\n*\t\t\t\t\t\t*";
	std::cout << "\n*\t\t\t\t\t\t*";
	std::cout << "\n*\t\t\t\t\t\t*";
	std::cout << "\n*\t\t\t\t\t\t*";
	std::cout << "\n*\t\t\t\t\t\t*";
	std::cout << "\n*************************************************\n";
	string s= "";
	cout << "\n\nPlease enter directory in the format C:\\Users\\Daniel...........\\:\n";
	getline(cin, s);

	DIR *pdir = NULL;
	pdir = opendir(s.c_str()); // "." will refer to the current directory 
	struct dirent *pent = NULL; // pointer to a directory

	while (pdir == NULL) // if pdir wasn't initialised correctly 
	{
		cout << "\nPlease enter directory in the format C:\\Users\\Daniel...........\\:\n";
		getline(cin, s);
		pdir = opendir(s.c_str());
	}

	cout << "\n**************Files in directory: \n\n";
	while (pent = readdir(pdir)) // while there is still something in the directory to list 
	{
		while (pent == NULL) // if pent has not been initialised correctly 
		{ // print an error message, and exit the program 
			std::cout << "Directory does not exist!";
			pdir = opendir(s.c_str()); // "." will refer to the current directory 
		}
		// otherwise, it was initialised correctly. let's print it on the console: 
		std::cout << "\t\t" << pent->d_name << "\n";
	}

	closedir(pdir);
	return s;
}
