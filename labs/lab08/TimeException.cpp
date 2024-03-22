// Задание 2. Безопасная реализация класса Time
// Добавьте в класс Time класс, реализующий возможность реагировать на
// исключительные ситуации, возникающие, например, при создании
// «неправильных» объектов, проведении операций с объектами класса и т.д.
#include <iostream>
#include <string>
using namespace std;

class TimeException : public exception
{
public:
    TimeException() : message("Such time cannot exist") {}
    void printMessage() const { cout << message << endl; }

private:
    string message;
};