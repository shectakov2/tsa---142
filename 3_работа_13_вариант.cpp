#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
double getValue();

/**
 * @brief - Проверяет корректность шага табулирования (должен быть положительным).
 * @param step - Значение шага для проверки.
 */
void checkStep(const double step);

/**
 * @brief - Вычисляет значение функции y = 3x -14 + e^x - e^(-x).
 * @param x - Аргумент функции.
 * @return - Рассчитанное значение y.
 */
double getY(const double x);

/**
 * @brief - Проверяет, принадлежит ли x области определения функции.
 * @param x - Значение аргумента для проверки.
 * @return - Возвращает true или false.
 */
bool isDomain(const double x);

/**
 *@brief - Точка входа в программу 
 *@return - возвращает 0, если программа выполнена корректно
 */
int main() 
{
    cout << "Enter xn: ";
    double xstart = getValue();
    cout << "Enter xk: ";
    double xend = getValue();
    cout << "Enter step: ";
    double step = getValue();
    
    checkStep(step);
    
    for (double x = xstart; x < xend + step; x += step) 
    {
        cout << "x = " << x;
        if (isDomain(x)) 
        {
            cout << " y = " << getY(x) << endl;
        } else 
        {
            cout << " no solution" << endl;
        }
    }
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

void checkStep(const double step) 
{
    if (step <= 0) 
    {
        cout << "Error: step must be positive" << endl;
        abort();
    }
}

double getY(const double x) 
{
    return 3 * x - 14 + exp(x) - exp(-x);
}

bool isDomain(const double x) 
{
    return true;
}
