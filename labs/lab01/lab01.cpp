//
// Created by Sofia on 12.09.2023.
//

using namespace std;
#include <iostream>

class LabOne{
public:
    int polygonArea(){
        double area = 0.0;
        cout<<"Write down coordinates of polygon"<<endl;
        int j = n-1;
        for (int i = 0; i < n; i++){
            cin>> X[i] >> Y[i];
        }
        for(int i = 0; i < n; i++){
            area += (X[j] + X[i]) * (Y[j] - Y[i]);
            j = i;
        }
        return abs(area/2.0);
    }

private:
    int n = 5; //polygon size
    double X[5];
    double Y[5];
};
