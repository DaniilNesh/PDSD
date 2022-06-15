#include"SetFunc.h"
using namespace std;
#define PL listP::
using iter = list<int>::iterator;

listP::listP() { }

list<int>* PL get() {
    return &plenty;
}
/// <summary>
/// пустое множество?
/// </summary>
/// <returns></returns>
bool PL F2() {
	if (plenty.empty())
		return true;
	return false;
}
/// <summary>
/// проверка принадлежности элемента множеству
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
bool PL F3(int data) {
	for (iter i = plenty.begin(); i != plenty.end(); i++) {
		if (*i == data)
			return true;
	}
	return false;
}
/// <summary>
/// Добавление нового элемента
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
void PL F4(int data) {
    plenty.push_front(data);
}
/// <summary>
/// Создание множества
/// </summary>
/// <param name="SIZE"></param>
/// <param name="min"></param>
/// <param name="max"></param>
/// <param name="type"></param>
/// <returns></returns>
void PL F5(int SIZE, int min, int max, int type) {
    srand(time(0));
    if (min >= max) {
        return;
    }
    int data;
    if (check_4(min, max, type, SIZE)) {
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
            if (flag)
                F4(data);
        }
    }
    else {
        cout << "Не хватает элементов" << endl;
    }
}
/// <summary>
/// Мощность множества
/// </summary>
/// <returns></returns>
int PL F6() {
    return plenty.size();
}
/// <summary>
/// Вывод элементов множества
/// </summary>
/// <param name="symbol"></param>
/// <returns></returns>
void PL F7(string symbol) {
    if (F2()) {
        cout << "Множество пустое" << endl;
        return;
    }
    iter end = plenty.end();
    end--;
    for (iter i = plenty.begin(); i != plenty.end(); i++) {
        if (i == end) {
            cout << *i;
            break;
        }
        cout << *i << symbol << " ";            
    }
}
/// Удаление списка
void PL F8() {
    plenty.clear();
}
/// Подмножество А-В
bool PL F9(listP* ptr) {
    if (F2())
        return true;
    if (ptr->F2())
        return false;
    if (F6() > ptr->F6())
        return false;

    for (iter i = plenty.begin(); i != plenty.end(); i++) {
        if (!ptr->F3(*i))
            return false;
    }
    return true;
}
/// Равенство двух множеств
bool PL F10(listP* ptr) {
    return (F9(ptr) && ptr->F9(this));
}
/// <summary>
/// Объединение двух множеств
/// </summary>
/// <param name="ptrA"></param>
/// <returns></returns>
listP* PL F11(listP* ptr) {
    listP* newPtr = new listP();
    for (iter i = plenty.begin(); i != plenty.end(); i++) {
        newPtr->F4(*i);
    }
    for (iter j = ptr->get()->begin(); j != ptr->get()->end(); j++) {
        if (!newPtr->F3(*j))
            newPtr->F4(*j);
    }
    return newPtr;
}
/// Пересечение множеств
listP* PL F12(listP* ptr) {
    if (F2())
        return NULL;
    if (ptr->F2())
        return NULL;
    listP* newPtr = new listP();
    for (iter i = plenty.begin(); i != plenty.end(); i++) {
        if (ptr->F3(*i))
            newPtr->F4(*i);
    }
    return newPtr;
}
/// Разность множеств
listP* PL F13(listP* ptr) {
    if (F2())
        return NULL;
    listP* newPtr = new listP();
    for (iter i = plenty.begin(); i != plenty.end(); i++) {
        if (!ptr->F3(*i))
            newPtr->F4(*i);
    }
    return newPtr;
}
/// Симмистричная разность
listP* PL F14(listP* ptr) {
    if (F2())
        return NULL;
    if (ptr->F2())
        return NULL;

    listP* newPtr = new listP();
    listP* buffer = new listP();
    newPtr = F11(ptr);
    buffer = F12(ptr);
    newPtr = newPtr->F13(buffer);
    return newPtr;
}
PL ~listP() {
	plenty.clear();
}

bool check_4(int min, int max, int type, int SIZE) {
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
        for (int j = 0; j < length; j++) {
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