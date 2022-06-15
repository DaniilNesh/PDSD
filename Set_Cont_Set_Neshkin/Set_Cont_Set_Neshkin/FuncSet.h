#pragma once
#include<iostream>
#include<set>
#include<string>

using namespace std;

class SetP
{
private:
	set<int> plenty;
public:
	SetP();
	/// <summary>
	/// ������
	/// </summary>
	/// <returns>��������� �� ���������</returns>
	set<int>* get();
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
	bool F9(SetP* ptr);
	/// <summary>
	/// ��������� ���� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	bool F10(SetP* ptr);
	/// <summary>
	/// ����������� ���� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	SetP* F11(SetP* ptr);
	/// <summary>
	/// ����������� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	SetP* F12(SetP* ptr);
	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	SetP* F13(SetP* ptr);
	/// <summary>
	/// ������������� ��������
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	SetP* F14(SetP* ptr);
	~SetP();
};

bool check(int min, int max, int type, int SIZE);