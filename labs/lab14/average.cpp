#include <iostream>

using namespace std;

template <class T>
// Напишите шаблон функции, возвращающей среднее арифметическое всех элементов массива.
// Аргументами функции должны быть имя и размер массива (типа int).
float average(T arr[], int size)
{
    float avg = 0;

    for (int i = 0; i < size; i++)
    {
        avg += arr[i];
    }

    return avg / size;
}

// В функции main() проверьте работу с массивами типа int, long, double и char.
int main()
{
    int intArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    long longArray[10] = {1000000001L, 1000000002L, 1000000003L, 1000000004L, 1000000005L, 1000000006L, 1000000007L, 1000000008L, 1000000009L, 1000000010L};
    double doubleArray[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    char charArray[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    cout << average(intArray, 10) << endl;
    cout << average(longArray, 10) << endl;
    cout << average(doubleArray, 10) << endl;
    cout << average(charArray, 10) << endl;

    return 0;
}