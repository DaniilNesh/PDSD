#pragma once
#include<string>
#include<iostream>

using namespace std;

struct NodeLink
{
    int value;
    NodeLink* next;
};

NodeLink* F1();

bool F2(NodeLink* ptr);

bool F3(int data, NodeLink* ptr);

NodeLink* F4(int data, NodeLink* ptr);

NodeLink* F5(NodeLink* ptr, int SIZE, int min, int max, int type);

int F6(NodeLink* ptr);

void F7(NodeLink* ptr, string symbol);

NodeLink* F8(NodeLink* ptr);

bool F9(NodeLink* ptrA, NodeLink* ptrB);

bool F10(NodeLink* ptrA, NodeLink* ptrB);

NodeLink* F11(NodeLink* ptrA, NodeLink* ptrB);

NodeLink* F12(NodeLink* ptrA, NodeLink* ptrB);

NodeLink* F13(NodeLink* ptrA, NodeLink* ptrB);

NodeLink* F14(NodeLink* ptrA, NodeLink* ptrB);

bool check(int min, int max, int type, int SIZE);
