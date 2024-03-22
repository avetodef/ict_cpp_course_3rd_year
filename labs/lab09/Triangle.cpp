// Задание 1. Безопасная реализация класса Triangle

#include <iostream>
#include "CorruptedTriangleException.cpp"
#include <math.h>

using namespace std;

// Требуется разработать класс Triangle, представляющий треугольник, который
// задается тремя сторонами.
class Triangle
{
private:
    double a, b, c;

    // Реализовать генерацию исключительной ситуации при попытке задать стороны
    // недопустимой длины – если хотя бы одна из сторон имеет длину большую, чем
    // сумма двух других сторон.
    bool validateTriangle()
    {
        if (a + b <= c || a + c <= b || b + c <= a)
        {
            throw CorruptedTriangleException();
            return false;
        }

        if (a <= 0 || b <= 0 || c <= 0)
        {
            throw CorruptedTriangleException();
            return false;
        }
        return true;
    }

public:
    Triangle(double a, double b, double c)
    {
        a = a;
        b = b;
        c = c;
    }

    Triangle() {}

    // Для класса определить функцию, вычисляющую площадь треугольника по трем
    // сторонам (см. практическое занятие 1).
    double calculateArea()
    {
        cout << "enter triangle edges" << endl;
        double n1, n2, n3;

        cin >> n1;
        cin >> n2;
        cin >> n3;
        bool val;
        try
        {
            val = validateTriangle();
        }
        catch (CorruptedTriangleException e)
        {
            e.printMessage();
        }
        if (val)
        {
            double p = (a + b + c) / 2;
            // S = √p (p - a) (p - b) (p - c).
            return sqrt(p * (p - a) * (p - b) * (p - c));
        }
        return -1;
    }
};

int m()
{
    Triangle t;

    cout << t.calculateArea() << endl;
}