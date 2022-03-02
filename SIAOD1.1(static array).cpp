#include <iostream>
#include<string>
using namespace std;
int n;

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

void Input(int arr[])
{

	cout << "Enter number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "element " << i << ": ";
		int a;
		cin >> a;
		arr[i] = a;
	}
}

int FindIndex(int arr[])
{
	for (int i = 0; i < n; i++)
	{
		if (canDevide(arr[i]))
		{
			return i;
		}
	}
	return -1;
}

void Insert(int arr[], int pos, int element)
{

	for (int i = n; i > pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = element;
	n++;

}

void PrintArr(int arr[])
{
	for (int i = 0; i < n; i++)
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

void Erase(int arr[], int index)
{
	if (index == n - 1)
	{
		arr[n - 1] = 0;
		n--;
		return;
	}
	for (int i = index; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = 0;
	n--;
}

void Delete3(int arr[])
{
	for (int i = 0; i < n; i++)
	{
		while (Devided3(arr[i]))
		{
			if (i >= n)
			{
				return;
			}
			Erase(arr, i);
		}
	}
}


int main()
{
	int arr[100] = { 0 };
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