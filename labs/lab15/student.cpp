#include <iostream>
#include <string>
#include <map>

using namespace std;

// Требуется написать программу, которая позволит присваивать оценки
// студентам, указывая только имя студента.
// Для организации данных используйте контейнер map
// к связанной паре: имя студента – ключ, оценка (тип char) - значение.


void printMap(map<string, char> map)
{
    for (auto &elem : map)
    {
        cout << elem.first << " " << elem.second << "\n";
    }
}

int main()
{
    map<string, char> grades;
    grades["Pupkin"] = 'A';
    grades["Bebrik"] = 'B';

    string student;
    char grade;
    cout << "Enter students surname " << endl;
    cin >> student;
    cout << "Enter students grade " << endl;
    cin >> grade;

    if (grades.find(student) != grades.end())
    {
        cout << "You graded " << student << " a grade of " << grade << endl;
        ;
        grades[student] = grade;
    }
    else
    {
        cout << "New student " << student << " wih grade " << grade << " was added" << endl;
        grades.insert(make_pair(student, grade));
    }
    printMap(grades);

    return 0;
}
