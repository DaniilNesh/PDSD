#pragma once
#include<list>
#include<iostream>
#include<string>
using namespace std;
class listP {
private:
	list<int> plenty;
public:
	listP();
	/// <summary>
	/// ������
	/// </summary>
	/// <returns></returns>
	list<int>* get();
	/// <summary>
	/// ������ ���������?
	/// </summary>
	/// <returns></returns>
	bool F2();
	/// <summary>
	/// �������� �������������� �������� ���������
	/// </summary>
	/// <param name="data"></param>
	/// <returns></returns>
	bool F3(int data);
	/// <summary>
	/// ���������� ������ ��������
	/// </summary>
	/// <param name="data"></param>
	void F4(int data);
	/// <summary>
	/// �������� ���������
	/// </summary>
	/// <param name="SIZE"></param>
	/// <param name="min"></param>
	/// <param name="max"></param>
	/// <param name="type"></param>
	void F5(int SIZE, int min, int max, int type);
	/// <summary>
	/// �������� ���������
	/// </summary>
	/// <returns></returns>
	int F6();
	/// <summary>
	/// ����� ��������� ���������
	/// </summary>
	/// <param name="symbol"></param>
	void F7(string symbol);
	/// <summary>
	/// �������� ������
	/// </summary>
	void F8();
	/// <summary>
	/// ������������ �-�
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	bool F9(listP* ptr);
	/// <summary>
	/// ��������� ���� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	bool F10(listP* ptr);
	/// <summary>
	/// ����������� ���� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	listP* F11(listP* ptr);
	/// <summary>
	/// ����������� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	listP* F12(listP* ptr);
	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	listP* F13(listP* ptr);
	/// <summary>
	/// ������������� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	listP* F14(listP* ptr);
	~listP();
};
bool check(int min, int max, int type, int SIZE);