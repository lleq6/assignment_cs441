#include <iostream>

using namespace std;

void SortNumberArrays(int, int[]);
int CountMajority(int, int[], int);
int FindMajority(int[], int, int);
void HasMajority(int, int[]);

void SortNumberArrays(int N, int NumberArr[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - i - 1; ++j)
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

int CountMajority(int N, int Arrays[], int Number)
{
	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Arrays[i] == Number)
		{
			Count++;
		}
	}
	return Count;
}

int FindMajority(int Arrays[], int Left, int Right)
{
	if (Left == Right)
	{
		return Arrays[Left];
	}
	int Middle = (Left + Right) / 2;
	int LeftMajority = FindMajority(Arrays, Left, Middle);
	int RightMajority = FindMajority(Arrays, Middle + 1, Right);
	if (LeftMajority == RightMajority)
	{
		return LeftMajority;
	}
	int N = Right - Left + 1;
	int LeftCount = CountMajority(N, Arrays, LeftMajority);
	int RightCount = CountMajority(N, Arrays, RightMajority);
	if (LeftCount > N / 2)
	{
		return LeftMajority;
	}
	if (RightCount > N / 2)
	{
		return RightMajority;
	}
	return -1;
}

void HasMajority(int N, int Arrays[])
{
	int Majority = FindMajority(Arrays, 0, N - 1);
	if (Majority != -1)
	{
		cout << "Majority is " << Majority << endl;
	}
	else
	{
		cout << "No Majority" << endl;
	}
}

int main()
{
	int Arrays[]
	{ 
		2, 3, 2, 3, 4, 
		5, 3, 3, 2, 2, 
		2, 2, 1, 1, 2, 
		2, 2, 2, 3, 3, 
		3, 2, 2, 3, 2 
	};
	int N = sizeof(Arrays) / sizeof(int);
	SortNumberArrays(N, Arrays);
	cout << "Sort Number Arrays : ";
	for (int i = 0; i < N; ++i)
	{
		cout << Arrays[i] << " ";
	}
	cout << endl;
	HasMajority(N, Arrays);
	return EXIT_SUCCESS;
}