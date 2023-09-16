#include <iostream>
#include <vector>
#include "lab01/lab01.cpp"
#include "lab02/lab02.cpp"

int main() {
    cout<< "Lab One" <<endl;
    LabOne labOne;
    double area = labOne.polygonArea();
    cout << "Area of polygon is " << area << endl;


    LabTwo labTwo;
    int n;
    cout << "Lab Two. Exercise one" <<endl<< "Enter number to check if it is super prime" << endl;
    cin >> n;
    bool isSuperPrime = labTwo.superPrime(n);
    if (isSuperPrime) cout << n << " is a super prime number" << endl;
    else cout << n << " is not a super prime number" << endl;

    cout << "Exercise two" << endl<< "Enter your SNILS" << endl;
    long long snils;
    cin >> snils;
    bool snilsRes = LabTwo::checkSNILS(snils);
    if (snilsRes) cout << "Your SNILS is valid" << endl;
    else cout << "Your SNILS is invalid" << endl;

    cout << "Exercise three" << endl<< "Enter desired coin value" << endl;
    int coins;
    cin >> coins;
    vector<int> result = labTwo.greedyCoins(coins);
    cout << "Sequence of coins needed: ";
    for (int i : result) cout << i << " ";
    cout << endl;

    cout << "Exercise three" <<endl ;
    labTwo.playTargetGame();

    return 0;
}
