//
// Created by Софья on 12.10.2023.
//
#include "iostream"
#include "string"
#include "../lab05/lab05.cpp"
#include <fstream>

//Задание 1. Запись текста в файл
//Требуется написать программу для записи небольшого стихотворения с
//клавиатуры в текстовый файл.
//Задание 2. Сохранение данных в текстовый файл
//        В решении упражнения 2 занятия 5 создайте текстовый файл и запишите в него
//        два массива: исходный и отсортированный.
using namespace std;

class Lab06{
public:
    Lab05 l5;
    void writePoemToFile(){
        string fname;
        cout << "enter filename" << endl;
        cin >> fname;

        ofstream outFile;
        outFile.open(fname);
        if(!outFile){
            cerr << "error " << endl;
        }

        string poem;
        string line;
        cin.ignore();
        while (getline(cin, line) && !line.empty()) {
            outFile << line << endl;
        }
        outFile.close();
        cout <<"done yassss" << endl;
    }

    void sortArrayAndWriteToFile(){
        string filename;
        cout << "enter filename" <<endl;
        cin >> filename;

        ofstream outFile;
        outFile.open(filename);
        if(!outFile){
            cerr << "error " << endl;
        }

        int n;
        cout << "enter length of array" <<endl;
        int *arr = new int[n];

        int* sorted = l5.sortArray(n,arr);
        for(int i = 0; i <n; i++){
            outFile<<arr[i]<<" ";
        }
        outFile<<endl;
        for(int i = 0; i <n; i++){
            outFile<<sorted[i]<<" ";
        }


    }
private:

};