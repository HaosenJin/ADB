// Crack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class CExample {
private:
	int a;
public:
	CExample(int b)
	{
		a = b;
	}
	void Set(int b)
	{
		a = b;
	}
	void Show()
	{
		cout << a << endl;
	}
};

void reverse_string(char* str){
	if (str != NULL){
		int i = 0;
		int j = 0;
		while (str[i] != '\0'){
			i++;
		}
		char* result = new char[i];
		i--;
		while (i >= 0){
			result[j++] = str[i--];
		}
		cout << result << endl;
	}
}

void printLast10Lines(char* filename){
	const int K = 10;
	ifstream file(filename);
	string L[K];
	int size = 0;
	while (file.good()){
		getline(file, L[size%K]);
	}
}

void change(CExample A)
{
	A.Set(101);
	A.Show();
}

int _tmain(int argc, _TCHAR* argv[])
{
	CExample A(100);
	CExample B = A;
	B.Show();
	change(A);
	A.Show();
	return 0;
}



