#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(int);

int main()
{
    int X, Y;
    cout << "Enter a number of X : ";
    cin >> X;
    cout << "Enter a number of Y : ";
    cin >> Y;
    if (Y < X)
    {
        cout << "Try again, Please enter a number of Y greater than X" << endl;
        return 0;
    }
    vector<int> PrimeNumbers;
    for (int i = X; i < Y; ++i)
    {
        if (isPrime(i))
        {
            PrimeNumbers.push_back(i);
        }
    }
    if (PrimeNumbers.size() > 0)
    {
        cout << "จำนวนเฉพาะในช่วงของเลข " << X << " และ " << Y << " คือ ";
        for (int i = 0; i < PrimeNumbers.size(); ++i)
        {
            cout << PrimeNumbers[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "ไม่มีจำนวนเฉพาะในช่วงของเลข " << X << " และ " << Y << endl;
    }
    return 0;
}

bool isPrime(int Number)
{
    if (Number <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(Number); i++)
    {
        if (Number % i == 0)
        {
            return false;
        }
    }
    return true;
}
