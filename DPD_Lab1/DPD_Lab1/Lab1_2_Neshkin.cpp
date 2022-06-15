#include <iostream>
#include<list>
#include<ctime>
#include<string>
#include"HeadF.h"
using namespace std;
#define ENTER cout<<endl

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	NodeLink* A, * B;
	A = F1();
	B = F1();
	int SIZE_A = rand() % 4 + 6;
	int SIZE_B = rand() % 4 + 6;
	int min = rand() % 10;
	int  max = rand() % 60 + 100;
	A = F5(A, SIZE_A, min, max, 1);
	B = F5(B, SIZE_B, min, max, 2);
	cout << "A: ";
	F7(A, ",");
	
	ENTER;
	cout << "B: ";
	F7(B, ",");
	ENTER;
	cout << "F9(A,B): " << F9(A, B) << endl;
	cout << "F9(A,A): " << F9(A, A) << endl;
	cout << "Вызвана функция F10(A,B): " << F10(A, B) << endl;
	cout <<"Вызвана функция F10(A,A): " << F10(A, A) << endl;
	NodeLink* ptr = F1();
	cout << "Вызвана функция   F11: " << endl;
	ptr = F11(A, B);
	F7(ptr, ",");
	ENTER;
	ptr = F8(ptr);
	cout << "Вызвана функция   F12: " << endl;
	ptr = F12(A, B);
	F7(ptr, ",");
	ENTER;
	ptr = F8(ptr);
	cout << "Вызвана функция   F13(A,B): " << endl;
	ptr = F13(A, B);
	F7(ptr, ",");
	ENTER;
	cout << "Вызвана функция   F13(B,A): " << endl;
	ptr = F13(B,A);
	F7(ptr, ",");
	ENTER;
	ptr = F8(ptr);
	cout << "Вызвана функция   F14: " << endl;
	ptr = F14(A, B);
	F7(ptr, ",");
	ENTER;
	
}

