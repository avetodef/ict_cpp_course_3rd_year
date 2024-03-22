// Требуется реализовать шаблонную функцию Print, которая выводит в поток
// std::cout элементы переданного контейнера через указанную качестве параметра
// строку-разделитель.
// Первый аргумент функции — контейнер. Требуется гарантировать, что по этому
// контейнеру можно проитерироваться с помощью стандартного цикла range-based
// for, и что элементы контейнера можно вывести в поток std::cout с помощью
// стандартного оператора <<.
// Второй аргумент функции — строка-разделитель, которую надо печатать между
// элементами. В конце необходим перевод строки \n.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename Container>

void print(const Container &container, const string &delimiter)
{
    for (const auto i : container)
    {
        cout << i;
        if (i != container.back())
        {
            cout << delimiter;
        }
    }
    cout << endl;
}

int main()
{
    vector<int> data = {1, 2, 3};
    print(data, ", ");
}