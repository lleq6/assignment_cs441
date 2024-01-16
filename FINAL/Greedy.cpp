#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

class Customer
{
public:
	int Index, WaitingTime;
};

void SortTime(int N, Customer Customers[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - i - 1; ++j)
		{
			if (Customers[j].WaitingTime > Customers[j + 1].WaitingTime)
			{
				Customer Temp = Customers[j];
				Customers[j] = Customers[j + 1];
				Customers[j + 1] = Temp;
			}
		}
	}
}

void DisplayCustomerTime(int N, Customer Customers[])
{
	for (int i = 0; i < N; ++i)
	{
		cout << " # Index (" << (Customers[i].Index + 1) << ")";
		cout << " : Waiting Time (" << Customers[i].WaitingTime << ")" << endl;
	}
}

int GetTotalTime(int N, Customer Customers[])
{
	int CurrentTime = 0;
	int TotalTime = 0;
	for (int i = 0; i < N; ++i)
	{
		CurrentTime += Customers[i].WaitingTime;
		TotalTime += CurrentTime;
	}
	return TotalTime;
}

string floatToStr(float Value)
{
	stringstream ss;
	ss << fixed << setprecision(2) << Value;
	return ss.str();
}

int main()
{
	int N;
	cout << "Enter number of N : ";
	cin >> N;
	if (!cin.fail())
	{
		Customer *Customers = new Customer[N];
		cout << "Enter number of Time (" << N << ") : ";
		for (int i = 0; i < N; ++i)
		{
			Customer customer;
			customer.Index = i;
			cin >> customer.WaitingTime;
			if (cin.fail())
			{
				cout << "Enter number only!" << endl;
				break;
			}
			Customers[i] = customer;
		}
		cout << "First Customer Time : " << endl;
		DisplayCustomerTime(N, Customers);
		SortTime(N, Customers);
		cout << "Sort Customer Time : " << endl;
		DisplayCustomerTime(N, Customers);
		cout << "Total Time : ";
		int TotalTime = GetTotalTime(N, Customers);
		cout << TotalTime << endl;
		float AverageTime = (float)TotalTime / (float)N;
		cout << "Average Total Time : ";
		cout << floatToStr(AverageTime) << endl;
	}
	else
	{
		cout << "Enter number only!" << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}