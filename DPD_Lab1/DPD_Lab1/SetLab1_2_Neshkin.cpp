#include"HeadF.h"
#include<iostream>
#include<ctime>
#include<string>
#include<typeinfo>

using namespace std;

struct NodeLink;
struct listokLink;

/// <summary>
/// создание пустого множества
/// </summary>
/// <returns></returns>
NodeLink* F1() {
    NodeLink* ptr = new NodeLink;
    ptr->next = NULL;
    return ptr;
}
/// <summary>
/// пустое множество?
/// </summary>
/// <param name="ptr"></param>
/// <returns></returns>
bool F2(NodeLink* ptr) {
    if (ptr->next == NULL && ptr->value<0)
        return true;
    return false;
}
/// <summary>
/// проверка принадлежности элемента множеству
/// </summary>
/// <param name="data"></param>
/// <param name="ptr"></param>
/// <returns></returns>
bool F3(int data, NodeLink* ptr) {
    if (F2(ptr))
        return false;
    NodeLink* buffer = ptr;
    while (buffer != NULL)
    {
        if (buffer->value == data)
            return true;
        buffer = buffer->next;
    }
    return false;
}
/// <summary>
/// Добавление нового элемента
/// </summary>
/// <param name="data"></param>
/// <param name="ptr"></param>
/// <param name="type"></param>
/// <returns></returns>
NodeLink* F4(int data, NodeLink* ptr) {
    if (ptr->value < 0) {
        ptr->value = data;
        return ptr;
    }        
    NodeLink* buffer = new NodeLink;
    buffer->value = data;
    buffer->next = ptr;

    ptr = buffer;
    return ptr;
}
/// <summary>
/// Создание множества
/// </summary>
/// <param name="ptr">- Указатель на множество</param>
/// <param name="SIZE">- Длина</param>
/// <param name="min">- Минимальное значение</param>
/// <param name="max">- Максимальное значение</param>
/// <returns></returns>
NodeLink* F5(NodeLink* ptr, int SIZE, int min, int max, int type) {
    srand(time(0));
    if (min >= max) {
        return ptr;
    }
    int data;
    
    if (check(min, max, type, SIZE)) {
        if (SIZE >= 6 && SIZE <= 9) {
            while (F6(ptr) < SIZE)
            {
                data = min + rand() % (max - 1);
                bool flag = true;
                switch (type)
                {
                case 1:
                    if (F3(data, ptr) || data % 2 == 0)
                        flag = false;
                    break;
                case 2:
                    if (F3(data, ptr) || data % 7 != 0)
                        flag = false;
                    break;
                default:
                    break;
                }
                if (flag) {
                    ptr = F4(data, ptr);
                }
                    
            }
        }
        else
            cout << "Неправильная длина" << endl;
        
    }else
        cout << "Не хватает элементов" << endl;
    
    return ptr;
}
/// <summary>
/// Мощность множества
/// </summary>
/// <param name="ptr"></param>
/// <returns></returns>
int F6(NodeLink* ptr) {
    if (F2(ptr))
        return 0;
    int count = 0;
    NodeLink* buffer = ptr;
    while (buffer != NULL) {
        count++;
        buffer = buffer->next;
    }
    return count;
}
/// <summary>
/// Вывод элементов множества
/// </summary>
/// <param name="ptr">Множество для вывода</param>
/// <param name="symbol">Символ разделения</param>
void F7(NodeLink* ptr, string symbol) {
    if (F2(ptr)) {
        cout << "Множество пустое" << endl;
        return;
    }        
    NodeLink* buffer = ptr;
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
/// Удаление списка
/// </summary>
/// <param name="ptr"></param>
/// <returns></returns>
NodeLink* F8(NodeLink* ptr) {
    NodeLink* buffer = ptr;
    while (ptr != NULL) {
        ptr = ptr->next;
        delete buffer;
        buffer = ptr;
    }
    return ptr;
}
/// <summary>
/// Подмножество А-В
/// </summary>
/// <param name="ptrA">Указатель на первое множество</param>
/// <param name="ptrB">Указатель на второе множество</param>
/// <returns></returns>
bool F9(NodeLink* ptrA, NodeLink* ptrB ) {
    if (F2(ptrA))
        return true;
    if (F2(ptrB))
        return false;
    if (F6(ptrA) > F6(ptrB))
        return false;

    for (NodeLink* A = ptrA; A != NULL; A = A->next) {
        if (!F3(A->value, ptrB)) {
            return false;
        }
    }
    return true;
}
/// <summary>
/// Равенство двух множеств
/// </summary>
/// <param name="ptrA">Указатель на первое множество</param>
/// <param name="ptrB">Указатель на второе множество</param>
/// <returns></returns>
bool F10(NodeLink* ptrA, NodeLink* ptrB) {
    if (F9(ptrA, ptrB) && F9(ptrB, ptrA))
        return true;
    else
        return false;
}
/// <summary>
/// Объединение двух множеств
/// </summary>
/// <param name="ptrA"></param>
/// <param name="ptrB"></param>
/// <returns></returns>
NodeLink* F11(NodeLink* ptrA, NodeLink* ptrB) {
    NodeLink* newPtr = F1();
    for (NodeLink* A = ptrA; A != NULL; A = A->next) {
        newPtr = F4(A->value, newPtr);
    }
    for (NodeLink* B = ptrB; B != NULL; B = B->next) {
        if (!F3(B->value, newPtr))
            newPtr = F4(B->value, newPtr);
    }
    return newPtr;
}
/// <summary>
/// Пересечение множеств
/// </summary>
/// <param name="ptrA"></param>
/// <param name="ptrB"></param>
/// <returns></returns>
NodeLink* F12(NodeLink* ptrA, NodeLink* ptrB) {
    if (F2(ptrA))
        return NULL;
    if (F2(ptrB))
        return NULL;
    NodeLink* newPtr = F1();
    for (NodeLink* A = ptrA; A != NULL; A = A->next) {
        if (F3(A->value, ptrB)) 
           newPtr = F4(A->value, newPtr);
    }
    return newPtr;
}
/// <summary>
/// Разность множеств
/// </summary>
/// <param name="ptrA"></param>
/// <param name="ptrB"></param>
/// <returns></returns>
NodeLink* F13(NodeLink* ptrA, NodeLink* ptrB) {
    if (F2(ptrA))
        return NULL;
    NodeLink* newPtr = F1();
    for (NodeLink* A = ptrA; A != NULL; A = A->next) {
        if (!F3(A->value, ptrB))
            newPtr = F4(A->value, newPtr);
    }
    return newPtr;
}
/// <summary>
/// Симмистричная разность
/// </summary>
/// <param name="ptrA"></param>
/// <param name="ptrB"></param>
/// <returns></returns>
NodeLink* F14(NodeLink* ptrA, NodeLink* ptrB) {
    if (F2(ptrA))
        return NULL;
    if (F2(ptrB))
        return NULL;
    
    NodeLink* newPtr = F1();
    NodeLink* buffer = F1();
    newPtr = F11(ptrA, ptrB);
    buffer = F12(ptrA, ptrB);
    newPtr = F13(newPtr, buffer);
    return newPtr;
}

bool check(int min, int max, int type, int SIZE) {
    int length = max - min;
    int count = 0;
    int* mas = new int[length];
    for (int i = 0; i < length; i++) {
        mas[i] = min;
        min++;
    }
    switch (type)
    {
    case 1:     //множество А        
        for (int j = 0; j < length;j++) {
            if (mas[j] % 2 != 0)
                count++;
        }
        break;
    case 2:     // множество В
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
    return false;           //не соответствует
}