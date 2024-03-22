// Указание. Создайте структуру
// StudentGrade с двумя элементами:
// имя студента (std::string) и оценка (char).

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct StudentGrade
{
    string name;
    char grade;
};

vector<StudentGrade> addStudent(string &name, char grade, vector<StudentGrade> studentsVector)
{
    studentsVector.push_back(StudentGrade{name, grade});
    return studentsVector;
}
void printStudents(vector<StudentGrade> students)
{
    for (const auto &s : students)
    {
        cout << s.name << " " << s.grade << endl;
    }
}

int main()
{
    vector<StudentGrade> students;

    cout << "Enter student name" << endl;
    string name;
    char grade;
    cin >> name;
    cout << "Enter grade: " << endl;
    cin >> grade;

    students = addStudent(name, grade, students);
    printStudents(students);
}