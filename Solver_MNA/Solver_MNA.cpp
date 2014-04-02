// Solver_MNA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"
//#include <regex>

using namespace std;

struct node {
	char type;
	int Na, Nb;
	int value;
};


int main()
{
	int i=1;
	int j=1;
	int flag=0;
	//	int val;
//	node *vertex = new node();
	node vertex[50];
	ifstream in("circuit.txt");
	string line;

	if(!in) {
		cerr<<"circuit.txt could not be opened for reading\n"<<endl;
		exit(1);
	}
	
	while(getline(in, line)) {
		cout << line << endl;
//		tr1::regex cond("g");
//		val = regex_search(line.begin(), line.end(), cond);
//		cout << "Return Value = " << val << endl;

		/*tr1::cmatch res;
		tr1::regex rx("[rlgc]*/
		vertex[i].type = line[0];
		cout << vertex[i].type << endl;
		while(line[j]!=0)
		{
			if (line[j]==' '){
				flag=1;
				j++;}
			if (flag){
				node[i].
			j++;
		}

		 	
		
		i++;
		}
//	for (int j=1; j++; j<i)
//		cout << vertex[j].type;
	
	

	getch();
	return 0;
}

