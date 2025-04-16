#include <iostream>
using namespace std;

/**
 * @brief Считывает целое значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
int getValue();

/**
 * @brief Получает и проверяет размер массива
 * @return Размер массива
 */
size_t getSize();

/**
 * @brief Проверяет корректность размера массива
 * @param n Проверяемое значение размера
 * @return Завершает программу при n <= 0
 */
void checkN(const int n);

/**
 * @brief Заполняет массив значениями
 * @param arr Указатель на массив
 * @param n Размер массива
 * 
 */
void fillArray(int* arr, const int n);

/**
 * @brief Находит максимальный отрицательный элемент массива
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Максимальное отрицательное значение или -11 если таких элементов нет
 */
void printArray(int* arr, const int n);

/**
 * @brief Заменяет второй элемент массива на максимальный отрицательный
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Выводит предупреждение если массив слишком мал или нет отрицательных элементов
 */
int findMaxNegative(int* arr, int n);

/**
 * @brief Заменяет второй элемент массива на максимальный отрицательный
 * @param arr Указатель на массив
 * @param n Размер массива
 * @return Выводит предупреждение если массив слишком мал или нет отрицательных элементов
 */
void replaceSecondWithMaxNegative(int* arr, int n);

/**
 * @brief Считает количество положительных элементов, не превышающих A
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param A Верхняя граница значений
 * @return Количество элементов удовлетворяющих условию
 */
int countPositiveLessThanA(int* arr, int n, int A);

/**
 * @brief Ищет первую пару соседних элементов с суммой меньше заданного числа
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param number Целевая сумма для сравнения
 * @return Индекс первого элемента пары или -1 если пара не найдена
 */
int findFirstPairSumLessThan(int* arr, int n, int number);

/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main() 
{
    size_t n = getSize();
    int* arr = new int[n];
    fillArray(arr, n);
    cout << "Original array: ";
    printArray(arr, n);

    replaceSecondWithMaxNegative(arr, n);
    cout << "Array after replacing second element with max negative: ";
    printArray(arr, n);

    cout << "Enter A for task 2: ";
    int A = getValue();
    int count = countPositiveLessThanA(arr, n, A);
    cout << "Number of positive elements <= A: " << count << endl;

    cout << "Enter number for task 3: ";
    int num = getValue();
    int pairIndex = findFirstPairSumLessThan(arr, n, num);
    if (pairIndex == -1) 
    {
        cout << "No such pair found." << endl;
    } else 
    {
        cout << "First pair index: " << pairIndex << endl;
    }

    delete[] arr;
    return 0;
}

int getValue() 
{
    int value;
    cin >> value;
    if (cin.fail()) 
    {
        cout << "Invalid input. Aborting." << endl;
        abort();
    }
    return value;
}

size_t getSize() 
{
    cout << "Enter n: ";
    int n = getValue();
    checkN(n);
    return (size_t)(n);
}

void checkN(const int n) 
{
    if (n <= 0) 
    {
        cout << "Invalid size. Aborting." << endl;
        abort();
    }
}

void fillArray(int* arr, const int n) 
{
    cout << "Choose input method (1 - random, 2 - manual): ";
    int choice = getValue();
    if (choice == 1) 
    {
        srand(time(0));
        for (size_t i = 0; i < n; i++) 
        {
            int min = -10;
            int max = 10;
            arr[i] = min + rand() % (max - min + 1);
        }
    } 
    else 
    {
        for (size_t i = 0; i < n; i++) 
        {
            while (true) 
            {
                cout << "Enter arr[" << i + 1 << "] (-10 to 10): ";
                int value = getValue();
                
                if (value >= -10 && value <= 10) 
                {
                    arr[i] = value;
                    break;
                }
                cout << "Error! Value must be between -10 and 10. Try again.";
            }
        }
    }
}

void printArray(int* arr, const int n) 
{
    for (size_t i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMaxNegative(int* arr, int n) 
{
    int maxNeg = -11;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < 0 && arr[i] > maxNeg) 
        {
            maxNeg = arr[i];
        }
    }
    return maxNeg;
}

void replaceSecondWithMaxNegative(int* arr, int n) 
{
    if (n < 2) 
    {
        cout << "Array too small to replace second element." << endl;
        return;
    }
    int maxNeg = findMaxNegative(arr, n);
    if (maxNeg == -11) 
    {
        cout << "No negative elements. Second element unchanged." << endl;
    } 
    else 
    {
        arr[1] = maxNeg;
    }
}

int countPositiveLessThanA(int* arr, int n, int A) 
{
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > 0 && arr[i] <= A)
         {
            count++;
        }
    }
    return count;
}

int findFirstPairSumLessThan(int* arr, int n, int number) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        if (arr[i] + arr[i + 1] < number) 
        {
            return i;
        }
    }
    return -1;
}