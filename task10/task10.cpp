#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

// Определение типа TTime
struct TTime {
    int hours;
    int minutes;
};

// Функция для проверки корректности времени
bool isValidTime(const TTime& t) {
    return (t.hours >= 0 && t.hours < 24 && t.minutes >= 0 && t.minutes < 60);
}

// Процедура, которая уменьшает время на один час
void PrevHour(TTime& t) {
    if (isValidTime(t)) {
        t.hours--;
        if (t.hours < 0) {
            t.hours = 23;
        }
    }
}

// Функция для вывода времени
void printTime(const TTime& t) {
    cout << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << endl;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Пять заданных моментов времени
    vector<TTime> times = {
        {10, 30},
        {0, 45},
        {23, 59},
        {12, 0},
        {5, 15}
    };

    // Применение процедуры PrevHour к каждому времени
    for (TTime& time : times) {
        cout << "Исходное время: ";
        printTime(time);
        PrevHour(time);
        cout << "После уменьшения на 1 час: ";
        printTime(time);
        cout << endl;
    }

    return 0;
}
