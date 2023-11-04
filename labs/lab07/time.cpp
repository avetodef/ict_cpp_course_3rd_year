//
// Created by Софья on 12.10.2023.
//

#include <iostream>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

Time inputTime() {
    Time t;
    std::cout << "Введите часы: ";
    std::cin >> t.hours;
    std::cout << "Введите минуты: ";
    std::cin >> t.minutes;
    std::cout << "Введите секунды: ";
    std::cin >> t.seconds;
    return t;
}

int timeToSeconds(const Time& t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

Time secondsToTime(int seconds) {
    Time t;
    t.hours = seconds / 3600;
    t.minutes = (seconds % 3600) / 60;
    t.seconds = seconds % 60;
    return t;
}

Time addTimes(const Time& t1, const Time& t2) {
    int totalSeconds = timeToSeconds(t1) + timeToSeconds(t2);
    return secondsToTime(totalSeconds);
}

Time subtractTimes(const Time& t1, const Time& t2) {
    int totalSeconds = timeToSeconds(t1) - timeToSeconds(t2);
    if (totalSeconds < 0) {
        totalSeconds = 0;  // Не допускаем отрицательного времени
    }
    return secondsToTime(totalSeconds);
}

int main() {
    Time time1 = inputTime();
    Time time2 = inputTime();

    Time sum = addTimes(time1, time2);
    Time difference = subtractTimes(time1, time2);

    std::cout << "Сумма времен: " << sum.hours << " часов " << sum.minutes << " минут " << sum.seconds << " секунд." << std::endl;
    std::cout << "Разница времен: " << difference.hours << " часов " << difference.minutes << " минут " << difference.seconds << " секунд." << std::endl;

    return 0;
}