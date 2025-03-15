#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
double getValue();

/**
 * @brief Проверяет корректность длины окружности
 * @param length - длина окружности
 */
void checkParameters(const double length);

/**
 * @brief Рассчитывает площадь круга по длине окружности
 * @param length - длина окружности
 * @return Площадь круга
 */
double calculateArea(const double length);

int main()
{
    cout << "Enter circumference length: ";
    double length = getValue();
    checkParameters(length);
    cout << "Circle area is " << calculateArea(length) << endl;

    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Incorrect value" << endl;
        abort();
    }
    return value;
}

void checkParameters(const double length)
{
    if (length < 0)
    {
        cout << "Length can't be negative" << endl;
        abort();
    }
}

double calculateArea(const double length)
{
    const double pi = 3.1415;
    return (length * length) / (4 * pi);
}