#include <iostream>
#include <math.h>

using namespace std;

// Элементы класса Triangle:
// • Три точки – объекты класса Dot.
// • Конструктор.
// • Методы, позволяющие:
// − вывести длины сторон треугольника;
// − расчитать периметр треугольника;
// − расчитать площадь треугольника
class Triangle
{
private:
    Dot p1, p2, p3;

public:
    Triangle(Dot p1, Dot p2, Dot p3) : p1(p1), p2(p2), p3(p3){};
    // aggreagtion
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        p1 = Dot(x1, y1);
        p2 = Dot(x2, y2);
        p3 = Dot(x3, y3);
    }

    double perimeter()
    {
        return (p1.distanceTo(p2) + p2.distanceTo(p3) + p3.distanceTo(p1));
    }
    double surface(){
        double  p = perimeter()/2;
        double a = p1.distanceTo(p2);
        double b = p2.distanceTo(p2);
        double c = p3.distanceTo(p1);
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
};

class Dot
{
private:
    double x, y;

public:
    Dot() : x(0), y(0){};
    Dot(double x, double y) : x(x), y(x) {}

    double distanceTo(Dot point)
    {
        return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
    }
};