// Solver_MNA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"

using namespace std;


int main()
{
	ifstream in("circuit.txt");
	string line;

	if(!in) {
		cerr<<"circuit.txt could not be opened for reading\n"<<endl;
		exit(1);
	}

	while(getline(in, line)) {
		
		cout << line << endl;
	}
	getch();
	return 0;
}

