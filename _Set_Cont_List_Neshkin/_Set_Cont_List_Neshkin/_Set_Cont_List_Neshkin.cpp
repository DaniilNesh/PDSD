#include <iostream>
#include"SetFunc.h"
#define ENTER cout<<endl;

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int SIZE_A = rand() % 4 + 6;
	int SIZE_B = rand() % 4 + 6;
	int min = rand() % 10;
	int  max = rand() % 60 + 100;
	listP A, B;
	cout << "Вызвана функция F5 для множеств А и В" << endl;
	A.F5(SIZE_A, min, max, 1);
	B.F5(SIZE_B, min, max, 2);
	cout << "A: ";
	A.F7(",");
	ENTER
	cout << "B: ";
	B.F7(",");
	ENTER
	cout << "Мощность множества А: " << A.F6() << endl;
	cout << "Мощность множества B: " << B.F6() << endl;
	cout << "Вызвана функция F9(A,B): " << A.F9(&B) << endl;
	cout << "Вызвана функция F9(A,A): " << A.F9(&A) << endl;
	cout << "Вызвана функция F10(A,B): " << A.F10(&B) << endl;
	cout << "Вызвана функция F10(A,A): " << A.F10(&A) << endl;
	cout << "Вызвана функция F11" << endl;
	listP* ptr;
	ptr = A.F11(&B);
	ptr->F7(",");
	ptr->F8();
	ENTER
	cout << "Вызвана функция F12" << endl;
	ptr = A.F12(&B);
	ptr->F7(",");
	ptr->F8();
	ENTER
	cout << "Вызвана функция F13(A,B)" << endl;
	ptr = A.F13(&B);
	ptr->F7(",");
	ptr->F8();
	ENTER
	cout << "Вызвана функция F13(B,A)" << endl;
	ptr = A.F13(&B);
	ptr->F7(",");
	ptr->F8();
	ENTER
	cout << "Вызвана функция F14" << endl;
	ptr = A.F14(&B);
	ptr->F7(",");
	A.F8();
	B.F8();
	ptr->F8();
	delete ptr;
	ENTER
}

