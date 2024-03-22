#include <iostream>
#include "lab12/teacher.h"
#include "lab12/student.h"
#include <vector>

using namespace std;


// Требуется реализовать полиморфный вызов методов производных классов
// системы, описанной в упражнениях предыдущего практического занятия.
int m()
{
    int choice;

    cout << "would you like to know information about student or teacher (0/1)?" << endl;
    cin >> choice;

    if (choice == 0)
    {
        student *vasya = new student("Pupkin", "Vasya", "Vasilievich", vector<int>{3, 3, 3, 3});
        cout << vasya->get_full_name() << vasya->description() << endl;
        return 0;
    }
    if (choice == 1)
    {
        teacher *olga = new teacher("Tverskih", "Olga", "Ilinichna", 40);
        cout << olga->get_full_name() << olga->description() << endl;
        return 0;
    }

    cout << "no such option" << endl;
    return -1;
}