#include <iostream>
#include <vector>
#include "human.h"
#include "student.h"
#include "teacher.h"

int m()
{
    // Оценкистудента
    std::vector<int> scores;
    // Добавление оценок студента в вектор
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    student *stud = new student("Petrov", "Ivan", "Alexeevich", scores);
    std::cout << stud->get_full_name() << std::endl;
    std::cout << "avg : " << stud->get_average_score() << std::endl;

    unsigned int teacher_work_time = 40;
    teacher *tch = new teacher("Sergeev", "Dmitriy", "Sergeevich",
                               teacher_work_time);
    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Work time: " << tch->get_work_time() << std::endl;

    return 0;
}
