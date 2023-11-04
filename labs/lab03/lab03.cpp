//
// Created by Софья on 01.10.2023.
//
using namespace std;

#include <iostream>
#include "../lab02/lab02.cpp"
#include <math.h>

class Lab03 {
public:
    bool validateSnils(){
        string snils;
        cout << "input snils sequence" << endl;
        getline(cin, snils);
        if (!validateUserInputSNILS(snils)){
            cout << "Snils invalid";
            return false;
        }
        return lab02.checkSNILS(convertInputToLongLong(snils));
    }

    double getCubicRootBasic(){
        int n;
        cout << "input number" << endl;
        cin >> n;
        return pow(n, 1.0/3);
    }

    float getCubicRootIteration(){
        float y, y1;
        float n;
        cout << "input number";
        cin >> n;
        y=n;
        do {
            y1=y;
            y=0.5*(y+ 3 * n / (2 * y * y + n / y));
        }
        while (abs(y-y1)>1/100000);
        return y;
    }

    float calculateTriangleSurface(){ //S = √3/4*а
        float a;
        cout << "insert side" << endl;
        cin >> a;
        return sqrt(0.75)*a;
    }
    float calculateTriangleSurface(float a, float b, float c){ //S= sqrt(p(p-a)(p-b)(p-c))
        float p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    float sumOfSeries(float n){
        if (n <= 0) {
            cout << "must be grater than 0" << endl;
            return -1;
        }
        if (n == 1) return 5;
        if (n > 1) return sumOfSeries(n-1)+5*n;
    }

    long long convertToBinary(long long n){
        if (n <= 0) return n;
        return (n % 2 + 10* convertToBinary(n/2));
    }

private:
    LabTwo lab02;
    static bool validateUserInputSNILS(string snils) {
        for (char c: snils) {
            if (!(isdigit(c) || c == ' ' || c == '-')) {
                return false;
            }
        }
        return true;
    }

    static long long convertInputToLongLong(string snils){
    string res;
    for (char c : snils){
        if (c != ' ' && c != '-'){
            res +=c;
        }
    }
    return stoll(res);
}
};