#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SortNumbersArr(int, int[]);
int SearchMaximum2nd(int, int[]);

int main()
{
    int Count;
    cout << "��͡�ӹǹ�����ŷ���ͧ������㹪ش������ : ";
    cin >> Count;
    if (!cin.fail())
    {
        int* NumbersArr = new int[Count];
        cout << "��͡�����ŵ���ӹǹ������ (" << Count << ") : ";
        for (int i = 0; i < Count; ++i)
        {
            cin >> NumbersArr[i];
            if (cin.fail())
            {
                cout << "��͡�������繵���Ţ��ҹ��!" << endl;
                break;
            }
        }
        SortNumbersArr(Count, NumbersArr);
        int Maximum2nd = SearchMaximum2nd(Count, NumbersArr);
        if (Maximum2nd != 0)
        {
            cout << "��Ƿ���դ���ҡ�ش�ѹ�Ѻ��� 2 ���� " << Maximum2nd << endl;
        }
        else
        {
            cout << "����դ���ҡ�ش�ѹ�Ѻ��� 2" << endl;
        }
        delete[] NumbersArr;
    }
    else
    {
        cout << "��͡�ӹǹ�������繵���Ţ��ҹ��!";
    }
    return 0;
}

void SortNumbersArr(int Count, int NumberArr[])
{
    for (int i = 0; i < Count; ++i)
    {
        for (int j = 0; j < Count - i - 1; ++j)
        {
            if (NumberArr[j] > NumberArr[j + 1])
            {
                int Temp = NumberArr[j];
                NumberArr[j] = NumberArr[j + 1];
                NumberArr[j + 1] = Temp;
            }
        }
    }
}

int SearchMaximum2nd(int Count, int NumberArr[])
{
    int Maximum1st = NumberArr[0];
    for (int i = 1; i < Count; ++i)
    {
        if (NumberArr[i] > Maximum1st && NumberArr[i] > 0)
        {
            Maximum1st = NumberArr[i];
        }
    }
    int Maximum2nd = NumberArr[0];
    for (int i = 1; i < Count; ++i)
    {
        if (NumberArr[i] > Maximum2nd && NumberArr[i] > 0 && NumberArr[i] < Maximum1st)
        {
            Maximum2nd = NumberArr[i];
        }
    }
    if (Maximum1st == Maximum2nd)
    {
        return 0;
    }
    return Maximum2nd;
}