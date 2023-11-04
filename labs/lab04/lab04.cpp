//
// Created by Софья on 04.10.2023.
//

using namespace std;
#include <math.h>
#include <iostream>

class LabFour{

public:
    int solveQuadraticEquation(){
        double a, b, c, x1, x2;
        cout << "enter a, b, c" << endl;
        cin >> a >> b >> c;
        int result = myRoot(a, b, c, x1,x2);
        if (result == 1)
            cout << "x1 = " << x1 << " x2= " << x2 << endl;
        if (result == 0)
            cout << "x1 = x2 = " << x1 << endl;
        if (result == -1)
            cout << "no roots" << endl;
        return result;
    }

    bool input(int a, int b){
        return (a>0 && b>0);
    }

private:

    int myRoot(double a, double b, double c, double &x1, double &x2){
        double d =b*b - 4*a*c;
        if (d < 0) return -1;
        x1 = (-b + d) / 2*a;
        x2 = (-b -d) / 2*a;
        if (x1 == x2) return 0;
        return 1;
    }

};