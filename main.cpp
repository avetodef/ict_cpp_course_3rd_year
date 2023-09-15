#include <iostream>
#include <vector>
#include "lab01/lab01.cpp"
#include "lab02/lab02.cpp"

int main() {
//    cout<< "Lab One" <<endl;
//    LabOne labOne;
//    double area = labOne.polygonArea();
//    cout << "Area of polygon is " << area << endl;
//
//    cout << "Lab Two. Exercise one" <<endl;
    LabTwo labTwo;
//    int n;
//    cout << "Enter number to check if it is super prime" << endl;
//    cin >> n;
//    bool isSuperPrime = labTwo.superPrime(n);
//    if (isSuperPrime) cout << n << " is a super prime number" << endl;
//    else cout << n << " is not a super prime number" << endl;

    cout << "Exercise two" << endl;
    cout << "Enter your SNILS" << endl;
    int snils;
    cin >> snils;
    bool snilsRes = labTwo.checkSNILS(snils);
    if (snilsRes) cout << "Your SNILS is valid" << endl;
    else cout << "Your SNILS is invalid" << endl;

    cout << "Exercise three" << endl;
    cout << "Enter desired coin value" << endl;
    int coins;
    cin >> coins;
    vector<int> result = labTwo.greedyCoins(coins);
    cout << "Sequence of coins needed: ";
    for (int i : result) cout << i << " ";
    cout << endl;

    cout << "Exercise three" <<endl << "Generating random center..." << endl << "Now enter how many times you want to shot" << endl;
    int shootings;
    cin >> shootings;
    labTwo.targetShooting(shootings);

    return 0;
}
