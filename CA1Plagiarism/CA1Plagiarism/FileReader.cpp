// Daniel Buckley X00109141

#include "FileReader.h"
#include "Hashing.h"
#include "dirent.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/* This method is used to append the filepath with the file 
*/
/***************************************************************************************
*	 Function: getline()
*    Copied Completely - Not changed
*    Date: <28/10/2015>
*    
*    Availability: http://stackoverflow.com/questions/8171264/is-there-a-getlineistream-string-delim-that-appends-to-string
*
***************************************************************************************/
istream & getline(istream &in, string & str, char delim)
{
	char buf[1024];
	in.getline(buf, 1024, delim);
	str.append(buf, in.gcount());
	return in;
}

void fillFiles(string filepath) {
	string myFile1;
	string myFile2;
	string myFile3;
	string myFile4;
	if (filepath != ".") {
		myFile1 = filepath;
		myFile2 = filepath;
		myFile3 = filepath;
		myFile4 = filepath;
	}
	cout << "\n\nPlease enter file 1 \n";
	getline(cin, myFile1,'\n');
	cout << "Please enter file 2 \n";
	getline(cin, myFile2,'\n');
	cout << "Please enter file 3 \n";
	getline(cin, myFile3,'\n');
	cout << "Please enter file 4 \n";
	getline(cin, myFile4,'\n');

	byCharacters(myFile1, filepath);
	byCharacters(myFile2, filepath);
	byCharacters(myFile3, filepath);
	byCharacters(myFile4, filepath);

	/* Now we are going to compare every file to every other file*/
	compareTwoFiles(myFile1, myFile2);
	compareTwoFiles(myFile1, myFile3);
	compareTwoFiles(myFile1, myFile4);

	compareTwoFiles(myFile2, myFile3);
	compareTwoFiles(myFile2, myFile4);

	compareTwoFiles(myFile3, myFile4);

	char choice;
	cout << "\nWould you like to compare more files?\n";
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		string filepaths = "";
		filepath = start();
		fillFiles(filepaths);
	}
	else {
		std::cout << "\n\n\n**********End Of Plagiarism Detecter***********";
		std::cout << "\n*\t\t\t\t\t\t*";
		std::cout << "\n*\t\t\t\t\t\t*";
		std::cout << "\n*\t Daniel Buckley X00109141\t\t*";
		std::cout << "\n*\t\t\t\t\t\t*";
		std::cout << "\n*\t\t\t\t\t\t*";
		std::cout << "\n*\t\t\t\t\t\t*";
		std::cout << "\n*\t\t\t\t\t\t*";
		std::cout << "\n*\t\t\t\t\t\t*";
		std::cout << "\n*************************************************\n";
		system("pause");
		exit(1);
	}

}
void byCharacters(string stringFile1, string filepath) {
	ifstream myFile1(stringFile1);
	int ifs = 0, fors = 0, whiles = 0;
	char letters1;
	vector <char> line1;

	if (myFile1.is_open()) {
		while (myFile1.get(letters1)) {
			if (letters1 != ' ') {
				line1.push_back(letters1);
			}
		}
		for (unsigned int i = 0; i < line1.size(); i++) {
			if ((line1[i] == 'i') && (line1[i + 1] == 'f') && (line1[i + 2] == '(')) {
				ifs++;
			}
			else if ((line1[i] == 'f') && (line1[i + 1] == 'o') && (line1[i + 2] == 'r') && (line1[i + 3] == '(')) {
				fors++;
			}
			else if ((line1[i] == 'w') && (line1[i + 1] == 'h') && (line1[i + 2] == 'i') && (line1[i + 3] == 'l') && (line1[i + 4] == 'e') && (line1[i + 5] == '(')) {
				whiles++;
			}
		}
		cout << "\n ******************************" << stringFile1 << "****************************** \n";
		cout << "Characters: " << line1.size() << "\n";
		cout << "If Statements: " << ifs << "\n";
		cout << "For Statements: " << fors << "\n";
		cout << "While Statements: " << whiles << "\n";
		cout << "\n ******************************End Of " << stringFile1 << "****************************** \n";

		myFile1.close();
	}
	else {
		cout << "File not found!\n";
		fillFiles(filepath);
	}
}

/* This method compares every single word in a file
* with every single word of another file for 2 files
* leaving out some reserved words in C++
*/
void compareTwoFiles(string file1, string file2) {
	ifstream myFile1(file1);
	ifstream myFile2(file2);

	// Two Vectors to hold words and compare
	vector <string> line1;
	vector<string> line2;
	vector<string> wordsInCommon;
	string w1;
	string w2;
	string stringToHash1, stringToHash2;

	ofstream outputFile;
	outputFile.open("output.txt", ios::out | ios::app);


	if (myFile1.is_open() && myFile2.is_open()) {
		while (myFile1 >> w1) {
			if (!(w1 == "{" || w1 == "}" || w1 == "<<" || w1 == ">>"
				|| w1 == "=" || w1 == "==" || w1 == "if" || w1 == "else"
				|| w1 == "for" || w1 == "while" || w1 == "#include" || w1 == "int"
				|| w1 == "double" || w1 == "string" || w1 == "char" || w1 == "/*" || w1 == "*/")) {
				line1.push_back(w1);
				stringToHash1 += w1;
			}
		}
		while (myFile2 >> w2) {
			if (!(w2 == "{" || w2 == "}" || w2 == "<<" || w2 == ">>"
				|| w2 == "=" || w2 == "==" || w2 == "if" || w2 == "else"
				|| w2 == "for" || w2 == "while" || w2 == "#include" || w2 == "int"
				|| w2 == "double" || w2 == "string" || w2 == "char" || w2 == "/*" || w2 == "*/")) {
				line2.push_back(w2);
				stringToHash2 += w2;
			}
		}
		cout << "\n******************Comparing " << file1 << " to " << file2 << "******************\n";
		if (line1.size() >= line2.size()) {
			for (unsigned int i = 0; i < line1.size(); i++) {
				for (unsigned j = 0; j < line2.size(); j++) {
					if (line1[i] == line2[j]) {
						wordsInCommon.push_back(line2[j]);
						i++;
					}
				}
			}
		}
		else if (line2.size() > line1.size()) {
			for (unsigned int i = 0; i < line2.size(); i++) {
				for (unsigned j = 0; j < line1.size(); j++) {
					if (line2[i] == line1[j]) {
						wordsInCommon.push_back(line1[j]);
						i++;
					}
				}
			}
		}

		cout << "\nCommon words are now being placed in a file within the working directory.\nThis file is named as 'output.txt'.\n";

		// Now we print the common words in files
		if (outputFile.is_open()) {
			outputFile << "\n******************Comparing " << file1 << " to " << file2 << "******************\n\n";
			for (unsigned int i = 0; i < wordsInCommon.size(); i++) {
				outputFile << wordsInCommon[i] << "\n";
			}
			outputFile << "\n ********************End of Comparison******************** \n";
			outputFile.close();
		}

		cout << "\n\nWords in " << file1 << ": " << line1.size() << "\n";
		cout << "Words in " << file2 << ": " << line2.size() << "\n";
		cout << "Similar Words: " << wordsInCommon.size() << "\n\n";

		// Now we compareHashes
		compareHashes(stringToHash1, file1, stringToHash2, file2);
		cout << "\n ********************End of Comparison******************** \n";
	}

}

// This method compares hashes of files
void compareHashes(string file1Hash, string fileName1, string file2Hash, string fileName2) {
	cout << "Comparing the hash of " << fileName1 << " with " << fileName2 << "! \n";
	if (BPHash(file1Hash) == BPHash(file2Hash)) {
		cout << "\n\n*****************These files 100% identical!*****************\n";
	}
	else {
		cout << "Files are different!\n";
	}
}