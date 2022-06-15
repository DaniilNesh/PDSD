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
listokLink* F1() {
    listokLink* ptr = new listokLink;
    ptr->first = NULL;
    return ptr;
}
/// <summary>
/// пустое множество?
/// </summary>
/// <param name="ptr"></param>
/// <returns></returns>
bool F2(listokLink* ptr) {
    if (ptr->first == NULL)
        return true;
    return false;
}
/// <summary>
/// проверка принадлежности элемента множеству
/// </summary>
/// <param name="data"></param>
/// <param name="ptr"></param>
/// <returns></returns>
bool F3(int data, listokLink* ptr) {
    if (F2(ptr))
        return false;
    NodeLink* buffer = ptr->first;
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
listokLink* F4(int data, listokLink* ptr) {
    NodeLink* buffer = new NodeLink;
    buffer->value = data;
    buffer->next = ptr->first;

    ptr->first = buffer;
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
listokLink* F5(listokLink* ptr, int SIZE, int min, int max, int type) {
    srand(time(0));
    if (min >= max) {
        return ptr;
    }
    int data;
    if (check_1_2(min, max, type, SIZE)) {
        //if (SIZE >= 6 && SIZE <= 9) {
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
                if(flag)
                    ptr = F4(data, ptr);
            }
       // }
        //else
           // cout << "Неправильная длина" << endl;
        
    }else
        cout << "Не хватает элементов" << endl;
    
    return ptr;
}
/// <summary>
/// Мощность множества
/// </summary>
/// <param name="ptr"></param>
/// <returns></returns>
int F6(listokLink* ptr) {
    if (F2(ptr))
        return 0;
    int count = 0;
    NodeLink* buffer = ptr->first;
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
void F7(listokLink* ptr, string symbol) {
    if (F2(ptr))
        cout << "Множество пустое" << endl;
    NodeLink* buffer = ptr->first;
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
listokLink* F8(listokLink* ptr) {
    NodeLink* buffer = ptr->first;
    while (ptr->first != NULL) {
        ptr->first = ptr->first->next;
        delete buffer;
        buffer = ptr->first;
    }
    return ptr;
}
/// <summary>
/// Подмножество А-В
/// </summary>
/// <param name="ptrA">Указатель на первое множество</param>
/// <param name="ptrB">Указатель на второе множество</param>
/// <returns></returns>
bool F9(listokLink* ptrA, listokLink* ptrB ) {
    if (F2(ptrA))
        return true;
    if (F2(ptrB))
        return false;
    if (F6(ptrA) > F6(ptrB))
        return false;

    for (NodeLink* A = ptrA->first; A != NULL; A = A->next) {
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
bool F10(listokLink* ptrA, listokLink* ptrB) {
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
listokLink* F11(listokLink* ptrA, listokLink* ptrB) {
    listokLink* newPtr = F1();
    for (NodeLink* A = ptrA->first; A != NULL; A = A->next) {
        F4(A->value, newPtr);
    }
    for (NodeLink* B = ptrB->first; B != NULL; B = B->next) {
        if (!F3(B->value, newPtr))
            F4(B->value, newPtr);
    }
    return newPtr;
}
/// <summary>
/// Пересечение множеств
/// </summary>
/// <param name="ptrA"></param>
/// <param name="ptrB"></param>
/// <returns></returns>
listokLink* F12(listokLink* ptrA, listokLink* ptrB) {
    if (F2(ptrA))
        return NULL;
    if (F2(ptrB))
        return NULL;
    listokLink* newPtr = F1();
    for (NodeLink* A = ptrA->first; A != NULL; A = A->next) {
        if (F3(A->value, ptrB)) 
            F4(A->value, newPtr);
    }
    return newPtr;
}
/// <summary>
/// Разность множеств
/// </summary>
/// <param name="ptrA"></param>
/// <param name="ptrB"></param>
/// <returns></returns>
listokLink* F13(listokLink* ptrA, listokLink* ptrB) {
    if (F2(ptrA))
        return NULL;
    listokLink* newPtr = F1();
    for (NodeLink* A = ptrA->first; A != NULL; A = A->next) {
        if (!F3(A->value, ptrB))
            F4(A->value, newPtr);
    }
    return newPtr;
}
/// <summary>
/// Симмистричная разность
/// </summary>
/// <param name="ptrA"></param>
/// <param name="ptrB"></param>
/// <returns></returns>
listokLink* F14(listokLink* ptrA, listokLink* ptrB) {
    if (F2(ptrA))
        return NULL;
    if (F2(ptrB))
        return NULL;
    
    listokLink* newPtr = F1();
    listokLink* buffer = F1();
    newPtr = F11(ptrA, ptrB);
    buffer = F12(ptrA, ptrB);
    newPtr = F13(newPtr, buffer);
    return newPtr;
}

bool check_1_2(int min, int max, int type, int SIZE) {
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