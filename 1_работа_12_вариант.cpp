#include <iostream>
#include <cmath>
using namespace std;

/**
 *@brief - Функция для вычисления A по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z
 *@return - возвращает рассчитанное значение
 */
double getA(const double x, const double y, const double z);

/**
 *@brief - Функция для вычисления B по заданному уравнению 
 *@param x - значение переменной x
 *@param y - значение переменной y
 *@param z - значение переменной z
 *@return - возвращает рассчитанное значение
 */
double getB(const double x, const double y, const double z);

/**
 *@brief - Точка входа в программу 
 *@return - возвращает 0, если программа выполнена корректно
 */
int main()
{
    const double x = 0.61;
    const double y = 0.9;
    const double z = 0.3;
    
    cout << "a = " << getA(x, y, z) << endl;
    cout << "b = " << getB(x, y, z) << endl;

    return 0;
}

double getA(const double x, const double y, const double z)
{
    return (pow(z, 2*x) + pow(y, -x) * cos(z + y) * x) / (x + 1);
}

double getB(const double x, const double y, const double z)
{
    return sqrt(pow(x, 2) + y) - pow(y, 2) * pow(sin((x + z) / x), 3);
}