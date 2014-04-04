// Solver_MNA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"
#include <regex>

using namespace std;

struct node {
	char type;			//stores element type
	int Na, Nb;			// Nodes between which element is connected
	float value;			// Value of element
};


int main()
{
	int i=0;
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

		tr1::cmatch res;
		//tr1::regex rx("([rlgc]d)s+(d)s+(d)s+(d)");
		tr1::regex rx("([rlgc][0-9]+) +([0-9]+) +([0-9])+ +([0-9]+.?[0-9]*)");
		if(regex_search(line.c_str(), res, rx)) {
			cout << "Match" <<endl;
		}
		cout << "Values: " << res[1] <<" "<< res[2] << " " << res[3] << " " << res[4] << endl; 

		vertex[i].type = line[0];
		cout << "Type of element: " << vertex[i].type << endl;
		vertex[i].Na = stoi(res[2]);
		cout << "Node A: " << vertex[i].Na << endl;
		vertex[i].Nb = stoi(res[3]);
		cout<< "Node B: " << vertex[i].Nb << endl;
		vertex[i].value = stof(res[4]);
		cout << "Value: "<< vertex[i].value << endl;
		i++;
	}


	int length=i;
	int size=0;
	for (int p=1; p<length; p++){
		size=max(size,vertex[p].Na);
		size=max(size,vertex[p].Nb);
	}
	//size++;
	cout <<"No. of nodes=" << size <<endl;

	int** A = new int*[size];
	for(int p = 0; p < size; p++)
		A[p] = new int[size];
	for (int p=0; p<size;p++)
		for (int q=0; q<size; q++)
			A[p][q]=0;

	/*for (int p=0;p<length;p++){
		if (vertex[p].type='g') {
			if (vertex[p].Nb==0) {
				A[vertex[p].Na-1][vertex[p].Na-1]=A[vertex[p].Na-1][vertex[p].Na-1]+vertex[p].value;
				cout << "Vertex value:" << A[vertex[p].Na-1][vertex[p].Na-1] << endl;
			}
			else if (vertex[p].Na=0)
				A[vertex[p].Nb][vertex[p].Nb]=A[vertex[p].Nb][vertex[p].Nb]+vertex[p].value;
			else {
				A[vertex[p].Na][vertex[p].Na]=A[vertex[p].Na][vertex[p].Na]+vertex[p].value;
				A[vertex[p].Na][vertex[p].Nb]=A[vertex[p].Na][vertex[p].Nb]-vertex[p].value;
				A[vertex[p].Nb][vertex[p].Na]=A[vertex[p].Nb][vertex[p].Na]-vertex[p].value;
				A[vertex[p].Nb][vertex[p].Nb]=A[vertex[p].Nb][vertex[p].Nb]+vertex[p].value;
			}
	}
	}*/

	for (int p=0; p<size;p++){
		for (int q=0; q<size; q++)
			cout << A[p][q] << ' ';
		cout << endl;
	}

	getch();
	return 0;
}

