#include"SetFuncPlenty.h"
#include<iostream>

using namespace std;

/// <summary>
/// �������� ������� ���������
/// </summary>
Plenty::Plenty() {			//F1
	plenty = new listok;
	plenty->first = NULL;
}
/// <summary>
/// ���������� ��������� �� ������ ������
/// </summary>
/// <returns></returns>
listok* Plenty:: get() {
	return plenty;
}
/// <summary>
/// ������������� ��������� �� ������ ������
/// </summary>
/// <param name="ptr"></param>
void Plenty::set(listok* ptr) {
	plenty = ptr;
}
/// <summary>
/// ������ ���������?
/// </summary>
/// <returns></returns>
bool Plenty::F2() {
	if (plenty->first == NULL)
		return true;
	return false;
}
/// <summary>
/// �������� �������������� �������� ���������
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
bool Plenty:: F3(int data) {
	if (F2())
		return false;
	Node* buffer = plenty->first;
	while (buffer != NULL)
	{
		if (buffer->value == data)
			return true;
		buffer = buffer->next;
	}
	return false;
}
/// <summary>
/// ���������� ������ ��������
/// </summary>
/// <param name="data"></param>
void Plenty::F4(int data) {	
	Node* buffer = new Node;
	buffer->value = data;
	buffer->next = plenty->first;
	plenty->first = buffer;
}
/// <summary>
/// �������� ���������
/// </summary>
/// <param name="SIZE"></param>
/// <param name="min"></param>
/// <param name="max"></param>
/// <param name="type"></param>
void Plenty:: F5(int SIZE, int min, int max, int type) {
	srand(time(0));
	if (min >= max) {
		return;
	}
	int data;
	if (check_3(min, max, type, SIZE)) {
		while (F6() < SIZE)
		{
			data = min + rand() % (max - 1);
			bool flag = true;
			switch (type)
			{
			case 1:
				if (F3(data) || data % 2 == 0)
					flag = false;
				break;
			case 2:
				if (F3(data) || data % 7 != 0)
					flag = false;
				break;
			default:
				break;
			}
			if(flag)
				F4(data);
		}
	}
	else
		cout << "�� ������� ���������" << endl;
}
/// <summary>
/// �������� ���������
/// </summary>
/// <returns></returns>
int Plenty:: F6() {
	if (F2())
		return 0;
	int count = 0;
	Node* buffer = plenty->first;
	while (buffer != NULL) {
		count++;
		buffer = buffer->next;
	}
	return count;
}
/// <summary>
/// ����� ��������� ���������
/// </summary>
/// <param name="symbol"></param>
void Plenty::F7(string symbol) {
	if (F2())
		cout << "��������� ������" << endl;
	Node* buffer = plenty->first;
	while (buffer != NULL) {
		if (buffer->next == NULL) {
			cout << buffer->value;
			break;
		}
		cout << buffer->value << symbol << " ";
		buffer = buffer->next;
	}
}
/// <summary>
/// �������� ���������
/// </summary>
void Plenty::F8() {
	Node* buffer = plenty->first;
	while (plenty->first != NULL) {
		plenty->first = plenty->first->next;
		delete buffer;
		buffer = plenty->first;
	}
}
/// <summary>
/// ������������ �-�
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool Plenty:: F9(Plenty* ptr) {
	if (F2())
		return true;
	if (ptr->F2())
		return false;
	if (F6() > ptr->F6())
		return false;

	for (Node* A = plenty->first; A != NULL; A = A->next) {
		if (!ptr->F3(A->value))
			return false;
	}
	return true;
}
/// <summary>
/// ��������� ���� ��������
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool Plenty:: F10(Plenty* other) {
	if (F9(other) && other->F9(this))
		return true;
	else
		return false;
}
/// <summary>
/// ����������� ���� ��������
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
Plenty* Plenty:: F11(Plenty* other) {
	Plenty* newPtr = new Plenty;
	for (Node* A = plenty->first; A != NULL; A = A->next) {
		newPtr->F4(A->value);
	}
	for (Node* B = other->get()->first; B != NULL; B = B->next) {
		if (!newPtr->F3(B->value))
			newPtr->F4(B->value);
	}
	return newPtr;
}
/// <summary>
/// ����������� ��������
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
Plenty* Plenty:: F12(Plenty* other) {
	Plenty* newPtr = new Plenty;
	if (F2())
		return NULL;
	if (other->F2())
		return NULL;
	for (Node* A = plenty->first; A != NULL; A = A->next) {
		if (other->F3(A->value))
			newPtr->F4(A->value);
	}
	return newPtr;
}
/// <summary>
/// �������� ��������
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
Plenty* Plenty:: F13(Plenty* other) {
	if (F2())
		return NULL;
	Plenty* newPtr = new Plenty;
	for (Node* A = plenty->first; A != NULL; A = A->next) {
		if (!other->F3(A->value))
			newPtr->F4(A->value);
	}
	return newPtr;
}
Plenty* Plenty::F14(Plenty* other) {
	if (F2())
		return NULL;
	if (other->F2())
		return NULL;

	Plenty* newPtr = new Plenty;
	Plenty* buffer = new Plenty;
	newPtr = F11(other);
	buffer = F12(other);
	newPtr = newPtr->F13(buffer);
	return newPtr;
}
/// <summary>
/// �������� ������
/// </summary>
Plenty::~Plenty() {			//F8
	Node* buffer = plenty->first;
	while (plenty->first != NULL) {
		plenty->first = plenty->first->next;
		delete buffer;
		buffer = plenty->first;
	}
}
bool check_3(int min, int max, int type, int SIZE) {
	int length = max - min;
	int count = 0;
	int* mas = new int[length];
	for (int i = 0; i < length; i++) {
		mas[i] = min;
		min++;
	}
	switch (type)
	{
	case 1:     //��������� �        
		for (int j = 0; j < length; j++) {
			if (mas[j] % 2 != 0)
				count++;
		}
		break;
	case 2:     // ��������� �
		for (int j = 0; j < length; j++) {
			if (mas[j] % 7 == 0)
				count++;
		}
		break;
	default:
		break;
	}
	delete[] mas;
	if (count >= 6) {
		if (count < 9) {
			if (count < SIZE)
				return false;
			return true;
		}
		return true;
	}
	return false;           //�� �������������
}