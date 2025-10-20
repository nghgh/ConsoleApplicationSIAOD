﻿#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void WatchFile(string filename, string line) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ошибка открытия файла \n";
    }
    cout << "В файле: \n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void CreateFile(string filename)
{
    ofstream file(filename);
    if (file.is_open()) {
        cout << "файл " << filename << " успешно создан \n";
    }

    else {
        cout << "файл не создан\n";
    }
    file << "43\n12\n21\n56\n92\n12";

    file.close();

}

void AddNumbers(string filename, int Numbers, int EnteredNumber) {

    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла! \n";
        return;
    }
    cout << "Сколько добавить чисел? \n"; cin >> Numbers;
    while (Numbers != 0) {
        cout << "Введите число: \n"; cin >> EnteredNumber;
        Numbers--;
        file << EnteredNumber << endl;
    }

}

void FindIndexDigit(){

}


void DigitCount() {

}


int main()
{
    setlocale(LC_ALL, "Russian");
    string filename;
    cout << "старт программы\n";
    cout << "Введите имя файла: "; cin >> filename;
    CreateFile(filename);
    while (true) {
        string line;
        int EnteredNumber = 0;
        int Numbers = 0;
        int choice;
        cout << "Пункт меню: \n1. Посмотреть содержимое \n2. Добавить числа \n3. Найти число по индексу \n4. Количество чисел \n5. Выполнить побитовые операции и сохранить результат \nВвод пользователя: "; cin >> choice;


        switch (choice) {
        case 1: {
            WatchFile(filename, line);
            break;
        }
        case 2: {
            AddNumbers(filename, Numbers, EnteredNumber);
            break;

        }
        case 3: {

        }
        case 4: {

        }

        }
    }
}
