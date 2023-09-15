//
// Created by Софья on 12.09.2023.
// A super prime number is a number that is prime itself
// and each time it is diveded by 10 all of those numbers are prime as well
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define SNILS_LENGTH 9

class LabTwo{
public:

    bool superPrime(int n){
        if (n<10 && isPrime(n)) {return true;}
        if (isPrime(n)) {return superPrime(n/10);}
        return false;
    }

    bool checkSNILS(int snils){
        int snilsBackup = snils;
        int lastDigits[2];
        lastDigits[1] = snils/10; lastDigits[0] = snils/10;
        cout << lastDigits << endl;
        return (checkSNILSSequence(snilsBackup)
        && (lastDigits == getFinalDigits(snilsBackup)));
    }


    vector<int> greedyCoins(int sum){
        int coinsSystem[4] = {1, 2, 5, 10};
        vector<int> coinsVector;
        vector<int> error = {-1};

        for (int & i : coinsSystem){
            while (sum >= i){
                sum -= i;
                coinsVector.push_back(i);
            }
        }
        if (sum == 0) return coinsVector;
        return error;
    }

    void targetShooting(int shootings){
        pair<int, int> center = getCenter();
        cout << "Write down coordinates " << shootings << " times" << endl;
        int x, y;
        int pointsSum = 0;
        for (int i = 0; i < shootings; i ++){
            cin >> x, cin>>y;
            pair<int, int> shot  = pair(int(x), int(y));
            pointsSum += getPoints(center,shot);
        }
        string status = getStatus(pointsSum, shootings);
        cout << "Your result is " << pointsSum << " points"<<endl;
        cout << "Your status is " << status<< endl;
    }


private:
    static bool isPrime(int n){
        for (int i = 2; i <= n / 2; i++){
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    static int * convertSNILSToArray(int s){
        int snils[9];
        s/100;//nah last two digits

        for (int i = 9; i > 0; i--){
            snils[i] = s%10;
        }
        return snils;
    }
    
    static bool checkSNILSSequence(int s){

       int* snils = convertSNILSToArray(s);

        for (int i = 1 ; i < SNILS_LENGTH; i++){
            if (snils[i-1] == snils[i] == snils[i+1]) return false;
        }
        return true;
    }
    
    static int* getFinalDigits(int s){
        int* snils = convertSNILSToArray(s);
        int resultInt = 0;
        int resArr[2] = {0,0};
        for (int i = 0; i < SNILS_LENGTH; i++){
            resultInt += (snils[i] * i);
        }

        if (resultInt == 100 || resultInt == 101) return resArr;
        if (resultInt > 101){
            int ost = resultInt / 101;
            if (ost < 100) {
                int ostArr[2];
                ostArr[1] = ost/10; ostArr[0] = ost;
                return ostArr;
            }
            if (ost == 100) return resArr;
        }

        return resArr;
    }

    pair<int, int> getCenter(){
        int x = rand() % 3 -3; //????????
        int y = rand() % 3 -3;
        return pair(x, y);
    }

    int getPoints(pair<int,  int> center, pair<int, int> shot){
        int xDiff = center.first - shot.first;
        int yDiff = center.second - shot.second;

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

    string getStatus(int points, int shootings){
        int maxPoints = shootings * 10;
        if (points >= 0.9*maxPoints) return "COOL";
        if (points >= 0.75*maxPoints) return "NORM";
        if (points >= 0.6*maxPoints) return "COULD BE BETTER";
        return "NOOB";
    }
};
