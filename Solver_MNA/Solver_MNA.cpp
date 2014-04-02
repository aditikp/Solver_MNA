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
		flag=0;
		vertex[i].Na=0;
		vertex[i].Nb=0;
		vertex[i].value=0;
		while(j<line.length())
		{
			if (line[j]==' ')
				flag++;
			else{
			if (flag==1)
				vertex[i].Na=vertex[i].Na*10+line[j]-48;
			else if (flag==2)
				vertex[i].Nb=vertex[i].Nb*10+line[j]-48;
			else if (flag==3)
				vertex[i].value=vertex[i].value*10+line[j]-48;
			}
			j++;
		}
		j=0;

		 	
		
		i++;
		}

	int length=i;
	for (int p=1; p<length; p++)
		cout << vertex[p].type << ' ' << vertex[p].Na <<' ' << vertex[p].Nb <<' ' << vertex[p].value << endl;
	
	int size=0;
	for (int p=1; p<length; p++){
		size=max(size,vertex[p].Na);
		size=max(size,vertex[p].Nb);
	}
	size++;
	cout << size <<endl;
	int** A = new int*[size];
	for(int p = 0; p < size; p++)
		A[p] = new int[size];
	for (int p=1; p<size;p++)
		for (int q=1; q<size; q++)
			A[p][q]=0;

	for (int p=1;p<length;p++)
		if (vertex[p].type='g')
			if (vertex[p].Nb=0)
				A[vertex[p].Na][vertex[p].Na]=A[vertex[p].Na][vertex[p].Na]+vertex[p].value;
			else if (vertex[p].Na=0)
				A[vertex[p].Nb][vertex[p].Nb]=A[vertex[p].Nb][vertex[p].Nb]+vertex[p].value;

	for (int p=1; p<size;p++){
		for (int q=1; q<size; q++)
			cout << A[p][q] << ' ';
		cout << endl;
	}

	getch();
	return 0;
}

