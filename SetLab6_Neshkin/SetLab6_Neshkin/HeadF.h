#pragma once
#include<string>
#include<iostream>

using namespace std;

struct NodeLink
{
    int value;
    NodeLink* next;
};

struct listokLink {
    NodeLink* first;
    //Node* last;
};

listokLink* F1();

bool F2(listokLink* ptr);

bool F3(int data, listokLink* ptr);

listokLink* F4(int data, listokLink* ptr);

listokLink* F5(listokLink* ptr, int SIZE, int min, int max, int type);

int F6(listokLink* ptr);

void F7(listokLink* ptr, string symbol);

listokLink* F8(listokLink* ptr);

bool F9(listokLink* ptrA, listokLink* ptrB);

bool F10(listokLink* ptrA, listokLink* ptrB);

listokLink* F11(listokLink* ptrA, listokLink* ptrB);

listokLink* F12(listokLink* ptrA, listokLink* ptrB);

listokLink* F13(listokLink* ptrA, listokLink* ptrB);

listokLink* F14(listokLink* ptrA, listokLink* ptrB);

bool check_1_2(int min, int max, int type, int SIZE);
