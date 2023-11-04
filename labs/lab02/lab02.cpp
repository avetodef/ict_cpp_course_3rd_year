//
// Created by Софья on 12.09.2023.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class LabTwo{
public:

    bool superPrime(int n){
        if (n<10 && isPrime(n)) {return true;}// A super prime number is a number that is prime itself
        if (isPrime(n)) {return superPrime(n/10);}// and each time it is diveded by 10 all of those numbers are prime as well
        return false;
    }

    static bool checkSNILS(long long snils){

        long long snilsBackup = snils;
        long long lastDigits[2];

        lastDigits[1] = snils%10;
        lastDigits[0] = (snils/10)%10; //get last two digits in array

        int* lastDigCheck = getFinalDigits(snilsBackup);

        return (checkSNILSSequence(snilsBackup)
        && (lastDigits[0] == lastDigCheck[0]) && (lastDigCheck[1] == lastDigits[1]) ); //check
    }


    vector<int> greedyCoins(int sum){
        int coinsSystem[4] = {1, 2, 5, 10};
        int n = 4; //length of array
        vector <int> coins;
        for (int i = n-1; i >=0; i--){ // from most valuable to less valuable coin
            while (sum >= coinsSystem[i]){
                sum -= coinsSystem[i];
                coins.push_back(coinsSystem[i]);
            }
        }
        return coins;
    }

    void playTargetGame(){
        cout << "Hello there! Lets play target game." << endl<<
        "Firstly, we need to understand which type of game would you like to play."<< endl <<
        " Do you want to shot a certain number of times and try to get best result possible or "
        "try to get a certain amount of points with least shots?" << endl << "If first, type 1. Else type 2" << endl;
        int type; cin >> type;
        cout << "Got you!" << endl << "Generating random center..." << endl;
        if (type == 1) shootingWithKnownAmountOfShots();
        else shootingWithTargetPoints();
    }



private:
    static bool isPrime(int n){
        for (int i = 2; i <= n / 2; i++){
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    static int * convertSNILSToArray(long long s){
        int* snils = new int[9];
        s = s/100;//nah last two digits
        for (int i = 9; i > 0; i--){
            snils[i] = s%10;
            s = s / 10;
        }
        return snils;
    }
    
    static bool checkSNILSSequence(long long s){
       int* snils = convertSNILSToArray(s);
        for (int i = 1 ; i < 8; i++){
            if (snils[i-1] == snils[i] == snils[i+1]) return false;
        }
        return true;
    }
    
    static int* getFinalDigits(long long s){
        int* snils = convertSNILSToArray(s);
        int resultInt = 0;
        int* resArr = new int [2]{0,0};
        for (int i = 1; i < 10; i++){
            resultInt += (snils[i] * (10 - i));
        }
        if (resultInt == 100 || resultInt == 101) return resArr;
        if (resultInt > 101){
            int ost = resultInt % 101;
            if (ost < 100) {
                int* ostArr = new int[2];
                ostArr[1] = ost%10; ostArr[0] = (ost/10)%10;
                return ostArr;
            }
            if (ost == 100) return resArr;
        }

        return resArr;
    }

    pair<int, int> getCenter(){

        int range = 3 - (-3) + 1;
        int x = rand() % range + (-3);
        int y = rand() % range + (-3);
        return pair(x, y);
    }

    int getPoints(pair<int,  int> center, pair<int, int> shot){
        int xDiff = abs(center.first - shot.first);
        int yDiff = abs(center.second - shot.second);

        if (xDiff == yDiff){
            if (xDiff <= 1) return 10;
            if (xDiff <= 2) return 5;
            if (xDiff <= 3) return 1;
            return 0;
        }

        int maxDiff = max(xDiff, yDiff);
        if (maxDiff <= 1) return 10;
        if (maxDiff <= 2) return 5;
        if (maxDiff <= 3) return 1;
        return 0;
    }

    string getStatusForFirstTypeOfGame(int points, int shootings){
        int maxPoints = shootings * 10;
        if (points >= 0.9*maxPoints) return "COOL";
        if (points >= 0.75*maxPoints) return "NORM";
        if (points >= 0.6*maxPoints) return "COULD BE BETTER";
        return "NOOB";
    }

    string getStatusForSecondTypeOfGame(int points, int shots){
        int bestResult = points / 10;
        if (shots <= 0.9 * bestResult) return "COOL";
        if (shots <= 0.75 * bestResult) return "NORM";
        if (shots <= 0.6 * bestResult) return "COULD BE BETTER";
        return "NOOB";
    }

    void printResult(int pointsSum, int shootings, pair<int, int> center){
        string status = getStatusForFirstTypeOfGame(pointsSum, shootings);
        cout << "Center was located at (" << center.first << "," << center.second << ")" << endl;
        cout << "Your result is " << pointsSum << " points "<< "of " << shootings * 10 << endl;
        cout << "Your status is " << status<< endl;
    }

    void shootingWithKnownAmountOfShots(){
        cout << "Enter how many times you want to shot" << endl;
        int shootings; cin >> shootings;
        pair<int, int> center = getCenter();
        cout << "Write down coordinates " << shootings << " times" << endl;
        int x, y;
        int pointsSum = 0;
        for (int i = 0; i < shootings; i ++){
            cin >> x, cin>>y;
            pair<int, int> shot  = pair(int(x), int(y));
            int points = getPoints(center, shot);
            cout << "You got " << points << " points for this shot" << endl;
            pointsSum += points;
            cout << "Total points so far: " << pointsSum << endl;
        }
        string status = getStatusForFirstTypeOfGame(pointsSum, shootings);
        printResult(pointsSum, shootings, center);
    }

    void shootingWithTargetPoints(){
        pair<int, int> center = getCenter();
        cout << "How much points do you want? " << endl;
        int pointsDesired; cin >> pointsDesired;
        int x, y;
        int pointsSum = 0;
        int shootingsCount = 0;
        while (pointsSum < pointsDesired){
            cin >> x, cin>>y;
            pair<int, int> shot  = pair(int(x), int(y));
            int points = getPoints(center, shot);
            cout << "You got " << points << " points for this shot" << endl;
            pointsSum += points;
            cout << "Total points so far: " << pointsSum << endl;
            shootingsCount+= 1;
        }
        cout << "You got " << pointsDesired << " in " << shootingsCount << " shots" << endl;
        cout << "Your status is " << getStatusForSecondTypeOfGame(pointsDesired, shootingsCount) << endl;
    }
};
