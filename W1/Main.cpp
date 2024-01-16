#include <iostream>
#include <string>
#include <vector>

using namespace std;

void SortNumbersArr(int, int[]);
void SearchMajority(int, int[]);

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
        SearchMajority(Count, NumbersArr);
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

void SearchMajority(int Count, int NumberArr[])
{
    int* MajorityArr = new int[Count];
    for (int i = 0; i < Count; ++i)
    {
        int Total = 0;
        for (int j = 0; j < Count; ++j)
        {
            if (NumberArr[i] == NumberArr[j])
            {
                Total++;
                MajorityArr[i] = Total;
            }
        }
    }
    int Maximum = MajorityArr[0];
    for (int i = 1; i < Count; ++i)
    {
        if (MajorityArr[i] > Maximum && MajorityArr[i] > 0)
        {
            Maximum = MajorityArr[i];
        }
    }
    vector<int> Majorities;
    string NumbersMajorities = "";
    for (int i = 0; i < Count; ++i)
    {
        if (MajorityArr[i] > 0 && MajorityArr[i] == Maximum)
        {
            if (find(Majorities.begin(), Majorities.end(), NumberArr[i]) == Majorities.end())
            {
                NumbersMajorities += to_string(NumberArr[i]) + ", ";
                Majorities.push_back(NumberArr[i]);
            }
        }
    }
    NumbersMajorities.pop_back();
    NumbersMajorities.pop_back();
    if (Maximum > 1)
    {
        cout << "�յ�������ҡ���� " << NumbersMajorities << " �繨ӹǹ " << Maximum << " ��Ǩҡ�����ŷ����� " << Count << " ���" << endl;
    }
    else
    {
        cout << "�ش�����Ź������յ�������ҡ" << endl;
    }
}