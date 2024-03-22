#include <iostream>
#include <math.h>

using namespace std;

// Разработайте класс Point с двумя полями вещественного типа – x и y и
// конструктором с параметрами, а также с функцией расчета расстояния до центра
// координат.
class Point
{
public:
    Point(double x, double y) : x(x), y(y){};

    // Реализуйте для класса Point перегрузку операторов передать в поток вывода
    // (<<) и сравнения (<)

    // Перегрузка оператора вывода в поток
    friend ostream &operator<<(ostream &os, const Point &p)
    {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }

    bool operator<(const Point &p1)
    {
        Point p2 = p1;
        return (distanceToZero() < p2.distanceToZero());
    }

    double distanceToZero()
    {
        return sqrt(x * x + y * y);
    }

private:
    int x, y;
};

int main()
{
    Point p = Point(1, 2);
    cout << p;
    return 0;
}