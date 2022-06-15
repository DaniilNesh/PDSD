#pragma once
#include<string>

struct Node
{
	int value;
	Node* next;
};

class Plenty {
private:
	Node* plenty;
public:
	Plenty();

	Node* get();

	void set(Node* ptr);

	bool F2();

	bool F3(int data);

	void F4(int data);

	void F5(int SIZE, int min, int max, int type);

	int F6();

	void F7(std::string symbol);

	void F8();

	bool F9(Plenty* other);

	bool F10(Plenty* other);

	Plenty* F11(Plenty* other);

	Plenty* F12(Plenty* other);

	Plenty* F13(Plenty* other);

	Plenty* F14(Plenty* other);

	~Plenty();
};
bool check(int min, int max, int type, int SIZE);