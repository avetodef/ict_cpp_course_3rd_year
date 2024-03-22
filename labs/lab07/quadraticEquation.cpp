//
// Created by Софья on 13.10.2023.
//
#include "iostream"
#include "tuple"
using namespace std;

// --------------------WITH STRUCT-------------------
struct Solution{
    double x1, x2;
};

struct Solution myRoot(double a, double b, double c, double &x1, double &x2){
    double d =b*b - 4*a*c;
    if (d < 0) return Solution{NULL, NULL};
    x1 = (-b + d) / 2*a;
    x2 = (-b -d) / 2*a;
    return Solution{x1, x2};
}

struct Solution solveEquation(){
    double a, b, c, x1, x2;
    cout << "enter a, b, c" << endl;
    cin >> a >> b >> c;
    return myRoot(a, b, c, x1, x2);
}

//int main(){
//    struct Solution solution = solveEquation();
//    if (solution.x1 == NULL) cout<< "no real roots";
//    cout <<"roots are " << solution.x1 << " " << solution.x2;
//    return 0;
//}

//--------------------WITH TUPLE---------------------

tuple<double, double> tupleRoot(double a, double b, double c, double &x1, double &x2){
    double d =b*b - 4*a*c;
    if (d < 0) return make_tuple(NULL, NULL);
    x1 = (-b + d) / 2*a;
    x2 = (-b -d) / 2*a;
    return make_tuple(x1, x2);
}

tuple<double, double> solveTupleEquation(){
    double a, b, c, x1, x2;
    cout << "enter a, b, c" << endl;
    cin >> a >> b >> c;
    return tupleRoot(a, b, c, x1, x2);
}

//int main(){
//    tuple<double, double> tuplesol = solveTupleEquation();
//    if (get<0>(tuplesol) == NULL) cout<< "no real roots";
//    cout <<"roots are " << get<0>(tuplesol) << " " << get<1>(tuplesol);
//    return 0;
//}