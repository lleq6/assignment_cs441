#include <iostream>
#include <algorithm>

using namespace std;

void DisplayArray(int, int[]);
void FindIndexInArray(int, int[]);

int main()
{
    int Array[]
    {
        1, 2, 92, 80, 79, 20, 11, -4, 0, 6, 25, 37, 8, 24, -1, -3, 7
    };
    int N = sizeof(Array) / sizeof(Array[0]);
    DisplayArray(N, Array);
    sort(Array, Array + N);
    DisplayArray(N, Array);
    cout << endl;
    cout << ">> Recursion" << endl;
    cout << endl;
    int k = 0;
    FindIndexInArray(k, Array);
    return EXIT_SUCCESS;
}

void DisplayArray(int N, int Array[])
{
    cout << endl;
    for (int k = 0; k < N; ++k)
    {
        printf_s("%4d", k);
    }
    cout << endl;
    for (int k = 0; k < N; ++k)
    {
        printf_s("%4d", Array[k]);
    }
    cout << endl;
}

void FindIndexInArray(int k, int Array[])
{
    if (Array[k] > k)
    {
        return;
    }
    else if (Array[k] == k)
    {
        printf_s("Array[%d] = %d\n", k, Array[k]);
    }
    FindIndexInArray(k + 1, Array);
}