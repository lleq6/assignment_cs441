#include <iostream>

using namespace std;

int GCD(int, int);

int main()
{
    int A, B;
    cout << "Enter a number of A : ";
    cin >> A;
    if (cin.fail())
    {
        cout << "Please enter only numbers." << endl;
        return 0;
    }
    cout << "Enter a number of B : ";
    cin >> B;
    if (cin.fail())
    {
        cout << "Please enter only numbers." << endl;
        return 0;
    }
    std::cout << "GCD of " << A << ", " << B << " = " << GCD(A, B);
    return 0;
}

int GCD(int A, int B)
{
    while (B > 0)
    {
        int Mod = A % B;
        A = B;
        B = Mod;
    }
    return A;
}