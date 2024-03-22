#include <iostream>
#include <string>
using namespace std;

class CorruptedTriangleException
{
public:
    CorruptedTriangleException() : message("Such triangle does not exist") {}
    void printMessage() const { cout << message << endl; }

private:
    string message;
};