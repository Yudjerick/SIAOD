#include <iostream>
#include<malloc.h>
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

int* Insert(int* arr, int pos, int element)
{
	n++;
	int* arr2 = new int[n];
	for (int i = 0; i < n - 1; i++) 
	{
		arr2[i] = arr[i];
	}
	delete[] arr;
	for (int i = n - 1; i > pos; i--)
	{
		arr2[i] = arr2[i - 1];
	}
	arr2[pos] = element;
	return arr2;
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

int* Erase(int* arr, int pos) 
{
	for (int i = pos; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	int* arr2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr[i];
	}
	delete[] arr;
	return arr2;
}


int* Delete3(int* arr)
{
	for (int i = 0; i < n; i++)
	{
		while (Devided3(arr[i]))
		{
			if (i >= n)
			{
				return arr;
			}
			arr = Erase(arr, i);
		}
	}
	return arr;
}


int main()
{
	cout << "Enter number of elements: ";
	cin >> n;
	int* arr = new int[n];

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
		arr = Insert(arr, idx + 1, el);
	}

	arr = Delete3(arr);
	PrintArr(arr);
	free(arr);
}