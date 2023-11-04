//
// Created by Софья on 05.10.2023.
//

#include <iostream>
using namespace std;

class Lab05{
public:
    int sumOfNegatives(int n, int *arr){
        int s = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] <0) s+=arr[i];
        }
        return s;
    }
    int sumOfPositives(int n, int *arr){
        int s = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] > 0) s+=arr[i];
        }
        return s;
    }
    int sumOfOddIndexes(int n, int *arr){
        int s = 0;
        for (int i = 0; i < n; i++){
            if (i%2 == 1) s+=arr[i];
        }
        return s;
    }
    int sumOfEvenIndexes(int n, int *arr){
        int s = 0;
        for (int i = 0; i < n; i++){
            if (i%2 == 0) s+=arr[i];
        }
        return s;
    }
    void maxminElement(int n, int* arr){
        int max = -1;
        int indxMax = -1;
        for (int i = 0; i < n; i++){
            if (arr[i] > max){
                max = arr[i];
                indxMax = i;
            }
        }
        int min = max;
        int indxMin = -1;
        for (int i = 0; i < n; i++){
            if (arr[i] < min){
                min = arr[i];
                indxMin = i;
            }
        }
        cout << "max element is " << max << " id is " << indxMax << endl;
        cout << "min element is " << min << " id is " << indxMin << endl;
    }

    int* sortArray(int N, int* a){
        int min = 0;
        int buf = 0;
        for (int i = 0; i < N; i++){
            min = i;
            for (int j = i + 1; j < N; j++)
                min = ( a[j] < a[min] ) ? j : min;
            if (i != min){
                buf = a[i];
                a[i] = a[min];
                a[min] = buf;
            }
        }
        for (int i = 0; i < N; i++)
            cout << a[i] << '\t';
    }

    int* maxVect(int kc, const int a[], const int b[]) {
        int* result = new int[kc];
        for (int i = 0; i < kc; i++) {
            result[i] = (a[i] > b[i]) ? a[i] : b[i];
        }
        return result;
    }

    void searchTransposition(pair<int* , int> pair1){
        cout << "enter key" << endl;
        int key;
        cin>>key;
        int* arr = pair1.first;
        int n = pair1.second;
        int temp = 0;
        for (int i = 0; i < n; i ++){
            if (arr[i] == key && i != 0){
                temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                cout << "key is found at index " << i-1 << endl;
            }
        }
    }




private:
    pair<int*, int> arrayInput(){
        cout << "enter number of elements" << endl;
        int n;
        cin >> n;
        int* arr = new int[n];
        cout << "enter elements" << endl;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        pair <int*, int> perroier = pair(arr, n);
        return perroier;
    }
};