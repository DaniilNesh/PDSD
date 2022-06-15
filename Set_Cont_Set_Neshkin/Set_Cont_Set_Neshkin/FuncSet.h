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
	/// Геттер
	/// </summary>
	/// <returns>Указатель на множество</returns>
	set<int>* get();
	/// <summary>
	/// пустое множество?
	/// </summary>
	/// <returns></returns>
	bool F2();
	/// <summary>
	/// проверка принадлежности элемента множеству
	/// </summary>
	/// <param name="data"></param>
	/// <returns></returns>
	bool F3(int data);
	/// <summary>
	/// Добавление нового элемента
	/// </summary>
	/// <param name="data"></param>
	void F4(int data);
	/// <summary>
	/// Создание множества
	/// </summary>
	/// <param name="SIZE"></param>
	/// <param name="min"></param>
	/// <param name="max"></param>
	/// <param name="type"></param>
	void F5(int SIZE, int min, int max, int type);
	/// <summary>
	/// Мощность множества
	/// </summary>
	/// <returns></returns>
	int F6();
	/// <summary>
	/// Вывод элементов множества
	/// </summary>
	/// <param name="symbol"></param>
	void F7(string symbol);
	/// <summary>
	/// Удаление списка
	/// </summary>
	void F8();
	/// <summary>
	/// Подмножество А-В
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	bool F9(SetP* ptr);
	/// <summary>
	/// Равенство двух множеств
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	bool F10(SetP* ptr);
	/// <summary>
	/// Объединение двух множеств
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	SetP* F11(SetP* ptr);
	/// <summary>
	/// Пересечение множеств
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	SetP* F12(SetP* ptr);
	/// <summary>
	/// Разность множеств
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	SetP* F13(SetP* ptr);
	/// <summary>
	/// Симмистричная разность
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	SetP* F14(SetP* ptr);
	~SetP();
};

bool check(int min, int max, int type, int SIZE);