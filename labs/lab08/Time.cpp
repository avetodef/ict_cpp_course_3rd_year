#include <iostream>
#include "TimeException.cpp"
using namespace std;

// Задание 1. Класс Time

// Создайте класс с именем Time, содержащий три поля типа int, предназначенные
// для хранения часов, минут и секунд.
class Time
{
private:
    int hours;
    int minutes;
    int seconds;

    // В конструктор с параметрами добавьте реализацию приведения больших
    // неправильных значений параметров к правильным значениям, например, если
    // клиент захочет создать время с параметром минут равным 70, то конструктор
    // должен преобразовать это значение к правильному виду: количество часов и
    // минут.

    void normalizeTime()
    {
        while (seconds >= 60)
        {
            seconds -= 60;
            minutes++;
        }
        while (minutes >= 60)
        {
            minutes -= 60;
            hours++;
        }
    }

    void validateTime()
    {
        if (hours < 0 || minutes < 0 || minutes > 60 || seconds < 0 || seconds > 60)
            throw TimeException();
    }

public:
    // Один из конструкторов класса должен инициализировать поля нулевыми
    // значениями, а другой конструктор — заданным набором значений.
    Time() : hours(0), minutes(0), seconds(0)
    {
    }
    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
        normalizeTime();
        validateTime();
    }

    // Создайте метод класса, который будет выводить значения полей на экран в
    // формате 11:59:59, и метод, складывающий значения двух объектов типа Time,
    // передаваемых в качестве аргументов.

    // Где это возможно и оправдано, сделайте методы константными.
    void printTime() const
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    Time addTimes(Time t1, Time t2) const
    {
        Time result = Time(t1.hours + t2.hours, t1.minutes + t2.minutes, t1.seconds + t2.seconds);
        result.normalizeTime();
        return result;
    }

    // LAB 10
    //     Требуется реализовать в классе Time (добавить в ранее созданный класс)
    // перегрузку следующий операций:
    // • сложение объектов Time,
    Time operator+(const Time &t2) const
    {
        Time result = Time(hours + t2.hours, minutes + t2.minutes, seconds + t2.seconds);
        result.normalizeTime();
        return result;
    }
    // • вычитание объектов Time,
    Time operator-(const Time &t2) const
    {
        Time result = Time(hours - t2.hours, minutes - t2.minutes, seconds - t2.seconds);
        result.normalizeTime();
        result.validateTime();
        return result;
    }
    // • сложение объекта Time и переменной вещественного типа,

    // • сложение переменной вещественного типа и объект Time,

    // • сравнение двух объектов Time.
    bool operator==(const Time &t2) const
    {
        return (hours == t2.hours && minutes == t2.minutes && seconds == t2.seconds);
    }

    bool operator>(const Time &t2) const
    {
        if (hours > t2.hours)
            return true;
        if (hours == t2.hours)
        {
            if (minutes > t2.minutes)
                return true;
            if (seconds > t2.seconds)
                return true;
            return false;
        }
        return false;
    }

    bool operator<(const Time &t2) const
    {
        if (hours < t2.hours)
            return true;
        if (hours == t2.hours)
        {
            if (minutes < t2.minutes)
                return true;
            if (seconds < t2.seconds)
                return true;
            return false;
        }
        return false;
    }
};

// В функции main() следует создать два инициализированных объекта (подумайте,
// должны ли они быть константными) и один неинициализированный объект. Затем
// сложите два инициализированных значения, а результат присвойте третьему
// объекту и выведите его значение на экран.
int main()
{
    Time time1;
    Time time2;
    try
    {
        time1 = Time(2, 50, 30);
        time2 = Time(3, 50, 60);

        Time timeNull = Time();

        Time sumOfTimes = time1.addTimes(time1, time2);
        cout << "usual method ";
        sumOfTimes.printTime();

        // В функции main() создайте требуемые объекты и проверьте работу
        // перегруженных операций.

        Time timeAddOp = time1 + time2;
        cout << "add operator ";
        timeAddOp.printTime();
    }
    catch (TimeException e)
    {
        e.printMessage();
        return -1;
    }
    try
    {
        Time timeSubOp = time1 - time2;
        cout << "sub operator ";
        timeSubOp.printTime();
    }
    catch (TimeException e)
    {
        cout << "Time 1 is less than time 2!" << endl;
    }

    bool equals = time1 == time2;
    cout << "time 1 == time 2? " << equals << endl;

    bool t1Biggert2 = time1 > time2;
    cout << "time 1 bigger than time 2? " << t1Biggert2 << endl;

    bool t1Lesst2 = time1 < time2;
    cout << "time 1 less than time 2? " << t1Lesst2 << endl;

    return 0;
}