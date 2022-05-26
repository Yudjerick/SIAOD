#include <iostream>
#include <vector>
#include<string>
using namespace std;

bool canDevide(int a)
{
	int x = a;
	if (x == 0)
	{
		return false;
	}
	while (x != 0)
	{
		int d = x % 10;
		if (d == 0 || a % d != 0)
		{
			return false;
		}
		x /= 10;
	}
	return true;
}

void Input(vector<int>& arr)
{
	arr = {};
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "element " << i << ": ";
		int a;
		cin >> a;
		arr.push_back(a);
	}
}

int FindIndex(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (canDevide(arr[i]))
		{
			return i;
		}
	}
	return -1;
}

void Insert(vector<int>& arr, int pos, int n)
{
	if (pos == arr.size())
	{
		arr.push_back(n);
	}
	else
	{
		arr.insert(arr.begin() + pos, n);
	}
}

void PrintArr(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}

bool Devided3(int x)
{
	if (x % 3 == 0)
	{
		return true;
	}
	return false;
}

void Delete3(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		while (Devided3(arr[i]))
		{
			arr.erase(arr.begin() + i);
			if (i >= arr.size())
			{
				return;
			}
			
		}
	}
}

int main()
{
	vector<int> arr;
	Input(arr);

	int idx = FindIndex(arr);
	
	if (idx == -1)
	{
		cout << "No elements found";
		return 0;
	}
	else
	{
		cout << "Enter element to insert: ";
		int el;
		cin >> el;
		Insert(arr, idx + 1, el);
	}

	Delete3(arr);
	PrintArr(arr);

}