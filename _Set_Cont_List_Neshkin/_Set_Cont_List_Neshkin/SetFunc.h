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
	/// Геттер
	/// </summary>
	/// <returns></returns>
	list<int>* get();
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
	bool F9(listP* ptr);
	/// <summary>
	/// Равенство двух множеств
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	bool F10(listP* ptr);
	/// <summary>
	/// Объединение двух множеств
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	listP* F11(listP* ptr);
	/// <summary>
	/// Пересечение множеств
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	listP* F12(listP* ptr);
	/// <summary>
	/// Разность множеств
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	listP* F13(listP* ptr);
	/// <summary>
	/// Симмистричная разность
	/// </summary>
	/// <param name="ptr"></param>
	/// <returns></returns>
	listP* F14(listP* ptr);
	~listP();
};
bool check(int min, int max, int type, int SIZE);