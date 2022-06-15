#include <iostream>
#include<time.h>
#include"FuncSet.h";
#include"HeadF.h";
#include"SetFunc.h";
#include"SetFuncPlenty.h";

#define ENDL cout<<endl
#define PRINT(x) cout<<x<<endl
using namespace std;
using Timer = unsigned int;

template<typename T>
void printTable(string name, T first, T second, T third, T fourth) {
    cout<<name << first << "\t" << second << "\t" << third << "\t" << fourth << "\t" << endl;
    for (int i = 0; i < 60; i++)
        cout << "=";
    ENDL;
}

struct Result {
    Timer CreateSet;
    Timer LengthSet;
    Timer PodmnozhA_A;
    Timer PodmnozhB_A;
    Timer EqualityA_A;
    Timer EqualityB_A;
    Timer UnityA_B;
    Timer IntersectionA_B;
    Timer differenceA_B;
    Timer SimDifferenceA_B;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    listokLink* linkA = F1(), 
    *linkB = F1();    // связный список
    Plenty Set_1A, Set_1B;               // Множество "Связный список"
    listP Set_2A, Set_2B;                // Множество "Лист"
    SetP Set_3A, Set_3B;                 // Множество "Сет"
    Timer link_begin = 0, link_end = 0,             // Время link
        Set_1_begin = 0, Set_1_end = 0,             // Время Set_1
        Set_2_begin = 0, Set_2_end = 0,             // Время Set_2
        Set_3_begin = 0, Set_3_end = 0;             // Время Set_3
    int N = -1;
    const int MIN = 1, MAX = 5000;
    Result result_link, result_Set_1, result_Set_2, result_Set_3;
    cout << "Введите длину(>1000): ";
    while (N < 1000) {
        char str[50];
        bool flag = true;
        cin >> str;
        for (int i = 0; i < strlen(str); i++) {
            if (!isdigit(str[i])) {
                cout << "Неправильный тип данных" << endl;
                cout << "Введите длину(>1000): ";
                flag = false;
                break;
            }
        }
        if (flag) {
            N = atoi(str);
            if (N < 1000) {
                cout << "Неправильная длина!" << endl;
                cout << "Введите длину(>1000): ";
            }
        }                  
    }
    system("cls");
    ENDL;
    link_begin = clock();
    linkA = F5(linkA, N, MIN, MAX, 1);
    link_end = clock();
    result_link.CreateSet = link_end - link_begin;

    Set_1_begin = clock();
    Set_1A.F5(N, MIN, MAX, 1);
    Set_1_end = clock();
    result_Set_1.CreateSet = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F5(N, MIN, MAX, 1);
    Set_2_end = clock();
    result_Set_2.CreateSet = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F5(N, MIN, MAX, 1);
    Set_3_end = clock();
    result_Set_3.CreateSet = Set_3_end - Set_3_begin;
    printTable("Название\t\t", "Link", "Plenty", "List", "Set");
    printTable("Создание списка\t\t", result_link.CreateSet, result_Set_1.CreateSet, result_Set_2.CreateSet, result_Set_3.CreateSet);

    link_begin = clock();
    F6(linkA);
    link_end = clock();
    result_link.LengthSet = link_end - link_begin;
    
    Set_1_begin = clock();
    Set_1A.F6();
    Set_1_end = clock();
    result_Set_1.LengthSet = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F6();
    Set_2_end = clock();
    result_Set_2.LengthSet = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F6();
    Set_3_end = clock();
    result_Set_3.LengthSet = Set_3_end - Set_3_begin;
    printTable("Мощность(время)\t\t", result_link.LengthSet, result_Set_1.LengthSet, result_Set_2.LengthSet, result_Set_3.LengthSet);

    linkB = F5(linkB, N, MIN, MAX*2, 2);
    Set_1B.F5(N, MIN, MAX*2, 2);
    Set_2B.F5(N, MIN, MAX*2, 2);
    Set_3B.F5(N, MIN, MAX*2, 2);
    link_begin = clock();
    F9(linkA, linkA);
    link_end = clock();
    result_link.PodmnozhA_A = link_end - link_begin;

    Set_1_begin = clock();
    Set_1A.F9(&Set_1A);
    Set_1_end = clock();
    result_Set_1.PodmnozhA_A = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F9(&Set_2A);
    Set_2_end = clock();
    result_Set_2.PodmnozhA_A = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F9(&Set_3A);
    Set_3_end = clock();
    result_Set_3.PodmnozhA_A = Set_3_end - Set_3_begin;
    printTable("Подмножество А и А\t", result_link.PodmnozhA_A, result_Set_1.PodmnozhA_A, result_Set_2.PodmnozhA_A,
        result_Set_3.PodmnozhA_A);

    link_begin = clock();
    F9(linkA, linkB);
    link_end = clock();
    result_link.PodmnozhB_A = link_end - link_begin;

    Set_1_begin = clock();
    Set_1B.F9(&Set_1A);
    Set_1_end = clock();
    result_Set_1.PodmnozhB_A = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2B.F9(&Set_2A);
    Set_2_end = clock();
    result_Set_2.PodmnozhB_A = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3B.F9(&Set_3A);
    Set_3_end = clock();
    result_Set_3.PodmnozhB_A = Set_3_end - Set_3_begin;
    printTable("Подмножество(B и А)\t", result_link.PodmnozhB_A, result_Set_1.PodmnozhB_A, result_Set_2.PodmnozhB_A,
        result_Set_3.PodmnozhB_A);

    link_begin = clock();
    F10(linkA, linkA);
    link_end = clock();
    result_link.EqualityA_A = link_end - link_begin;

    Set_1_begin = clock();
    Set_1A.F10(&Set_1A);
    Set_1_end = clock();
    result_Set_1.EqualityA_A = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F10(&Set_2A);
    Set_2_end = clock();
    result_Set_2.EqualityA_A = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F10(&Set_3A);
    Set_3_end = clock();
    result_Set_3.EqualityA_A = Set_3_end - Set_3_begin;
    printTable("Равенство А и А\t\t", result_link.EqualityA_A, result_Set_1.EqualityA_A, result_Set_2.EqualityA_A,
        result_Set_3.EqualityA_A);

    link_begin = clock();
    F10(linkA, linkB);
    link_end = clock();
    result_link.EqualityB_A = link_end - link_begin;

    Set_1_begin = clock();
    Set_1A.F10(&Set_1B);
    Set_1_end = clock();
    result_Set_1.EqualityB_A = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F10(&Set_2B);
    Set_2_end = clock();
    result_Set_2.EqualityB_A = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F10(&Set_3B);
    Set_3_end = clock();
    result_Set_3.EqualityB_A = Set_3_end - Set_3_begin;
    printTable("Равенство B и А\t\t", result_link.EqualityB_A, result_Set_1.EqualityB_A, result_Set_2.EqualityB_A,
        result_Set_3.EqualityB_A);

    link_begin = clock();
    F11(linkA, linkB);
    link_end = clock();
    result_link.UnityA_B = link_end - link_begin;

    Set_1_begin = clock();
    Set_1A.F11(&Set_1B);
    Set_1_end = clock();
    result_Set_1.UnityA_B = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F11(&Set_2B);
    Set_2_end = clock();
    result_Set_2.UnityA_B = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F11(&Set_3B);
    Set_3_end = clock();
    result_Set_3.UnityA_B = Set_3_end - Set_3_begin;
    printTable("Объединение А и В\t", result_link.UnityA_B, result_Set_1.UnityA_B, result_Set_2.UnityA_B, result_Set_3.UnityA_B);

    link_begin = clock();
    F12(linkA, linkB);
    link_end = clock();
    result_link.IntersectionA_B = link_end - link_begin;

    Set_1_begin = clock();
    Set_1A.F12(&Set_1B);
    Set_1_end = clock();
    result_Set_1.IntersectionA_B = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F12(&Set_2B);
    Set_2_end = clock();
    result_Set_2.IntersectionA_B = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F12(&Set_3B);
    Set_3_end = clock();
    result_Set_3.IntersectionA_B = Set_3_end - Set_3_begin;
    printTable("Пересечение А и В\t", result_link.IntersectionA_B, result_Set_1.IntersectionA_B, result_Set_2.IntersectionA_B,
        result_Set_3.IntersectionA_B);

    link_begin = clock();
    F13(linkA, linkB);
    link_end = clock();
    result_link.differenceA_B = link_end - link_begin;

    Set_1_begin = clock();
    Set_1A.F13(&Set_1B);
    Set_1_end = clock();
    result_Set_1.differenceA_B = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F13(&Set_2B);
    Set_2_end = clock();
    result_Set_2.differenceA_B = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F13(&Set_3B);
    Set_3_end = clock();
    result_Set_3.differenceA_B = Set_3_end - Set_3_begin;
    printTable("Разность А и В\t\t", result_link.differenceA_B, result_Set_1.differenceA_B, result_Set_2.differenceA_B,
        result_Set_3.differenceA_B);

    link_begin = clock();
    F14(linkA, linkB);
    link_end = clock();
    result_link.SimDifferenceA_B = link_end - link_begin;

    Set_1_begin = clock();
    Set_1A.F14(&Set_1B);
    Set_1_end = clock();
    result_Set_1.SimDifferenceA_B = Set_1_end - Set_1_begin;

    Set_2_begin = clock();
    Set_2A.F14(&Set_2B);
    Set_2_end = clock();
    result_Set_2.SimDifferenceA_B = Set_2_end - Set_2_begin;

    Set_3_begin = clock();
    Set_3A.F14(&Set_3B);
    Set_3_end = clock();
    result_Set_3.SimDifferenceA_B = Set_3_end - Set_3_begin;
    printTable("Сим. разность А и В\t", result_link.SimDifferenceA_B, result_Set_1.SimDifferenceA_B, result_Set_2.SimDifferenceA_B,
        result_Set_3.SimDifferenceA_B);
}
