// Daniel Buckley X00109141

#include "dirent.h"
#include "hashing.h"
#include <iostream>
#include "FileReader.h"
#include <fstream>
#include <string>
using namespace std;

// CA 1 C++ Plagiarism Detecter
// Daniel Buckley X00109141

int main() {
	/* filepath holds the directory in which we want to open to use files
	* start() - located in dirent.cpp to show files in a directory
	* findFiles() - located in filereader.cpp
	*/
	string filepath = "";
	filepath = start();
	fillFiles(filepath); 

	system("pause");
	return(0);
}
