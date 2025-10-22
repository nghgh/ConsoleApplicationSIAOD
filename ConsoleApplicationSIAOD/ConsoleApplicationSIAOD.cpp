#include <fstream>
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
    while (Numbers != 0) {
        cout << "Введите число: \n"; cin >> EnteredNumber;
        Numbers--;
        file <<endl<< EnteredNumber;
    }

}

void FindIndexDigit(string filename, int index){
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла";
        return;
    }
    int number;
    int currentIndex = 0;
    while (file >> number) {
        if (currentIndex == index) {
            cout << "Число с номером " << index << ": " << number << endl;
            file.close();
            return;
        }
        currentIndex++;
    }
    cout << "Число с номером" << index << "не найдено в файле\n";
    file.close();
}


void DigitCount(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла";
        return;
    }
    int NumberCount = 0;
    int number;
    while (file >> number) {
        NumberCount++;
    }
    cout << "Чисел в файле: " << NumberCount << endl;
    file.close();
    }
void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        cout << ((num >> i) & 1);
        if (i % 8 == 0 && i != 0) cout << " ";
    }
}
void BitwiseOperations(string inputFile, string outputFile, int n) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in.is_open()) {
        cout << "Ошибка открытия файла";
        return;
    }
    int num;
    cout << "Исходные и полученные числа:\n";
    while (in >> num) {
        cout << "Исходное: " << num << " (двоично: ";
        printBinary(num);
        cout << ")\n";

        // 1.3.6.1: Установить биты 3, 11, 5
        int mask1 = 0x828;
        int result1 = num | mask1;

        cout << "После упр.1: " << result1 << " (двоично: ";
        printBinary(result1);
        cout << ")\n";

        // 1.3.6.2: Обнулить четыре младших бита
        int mask2 = 0xFFFFFFF0;
        int result2 = result1 & mask2;

        cout << "После упр.2: " << result2 << " (двоично: ";
        printBinary(result2);
        cout << ")\n";

        // 1.3.6.3: Умножить на 128
        int result3 = result2 << 7; // 2^7 = 128

        cout << "После упр.3: " << result3 << " (двоично: ";
        printBinary(result3);
        cout << ")\n";

        // 1.3.6.4: Разделить на 128
        int result4 = result3 >> 7;

        cout << "После упр.4: " << result4 << " (двоично: ";
        printBinary(result4);
        cout << ")\n";

        // 1.3.6.5: Установить n-ый бит в 1, используя маску 2 (единица в старшем разряде)
        int mask5 = 1 << (31 - n);
        int result5 = result4 | mask5;

        cout << "После упр.5: " << result5 << " (двоично: ";
        printBinary(result5);
        cout << ")\n\n";

        out << result5 << endl;
    }

    in.close();
    out.close();
    cout << "Результаты записаны в файл: " << outputFile << endl;
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
            cout << "Сколько добавить чисел? \n"; cin >> Numbers;
            AddNumbers(filename, Numbers, EnteredNumber);
            break;

        }
        case 3: {
            int index;
            cout << "Введите индекс числа: ";
            cin >> index;
            FindIndexDigit(filename, index);
            break;
        }
        case 4: {
            DigitCount(filename);
        }
        case 5: {
            string outputFile;
            int n;
            cout << "Введите имя файла для результатов: ";
            cin >> outputFile;
            cout << "Введите номер бита n для операции 1.3.6.5: ";
            cin >> n;
            BitwiseOperations(filename, outputFile, n);
            break;
        }
        }
    }
}
