#include <iostream>
#include <vector>
using namespace std;

void Normalize(vector<vector<float>> &arr, int n)
{
	for (int i = n; i < arr.size(); i++)
	{
		float k = arr[i][n];
		for (int j = n; j < arr[i].size(); j++)
		{
			arr[i][j] = arr[i][j]/k;
		}
	}
}

void Substract(vector<vector<float>>& arr, int b, int a)
{
	
	for (int j = 0; j < arr[a].size(); j++)
	{
		arr[a][j] -= arr[b][j];
	}
	
}

void Trianglize(vector<vector<float>> &arr)
{
	for (int i = 0; i < arr.size(); i++) 
	{
		Normalize(arr, i);
		for (int j = i + 1; j < arr.size(); j++)
		{
			Substract(arr, i, j);
		}
	}
}

void GetX(vector<vector<float>> &arr) 
{
	vector < float > x;
	for (int i = arr.size() - 1; i >= 0; i--) 
	{
		// calculate sum to minus
		x.push_back(arr[i][arr[i].size() - 1]);
	}
}


void InputMatrix(vector<vector<float>> &arr, int n, int m)
{
	cout << "Enter matrix elements separated by space" << endl;
	for (int i = 0; i < n; i++)
	{
		vector<float> nStr;
		arr.push_back(nStr);
		for (int j = 0; j < m; j++)
		{
			float el;
			cin >> el;
			arr[i].push_back(el);
		}
	}
}

void InputMatrixRand(vector<vector<float>> &arr)
{
	srand(time(0));
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			arr[i][j] = rand()%100;
		}
	}
}

void PrintMatrix(vector<vector<float>> arr)
{
	cout << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<float>> arr;
	InputMatrix(arr, 3, 4);
	cout << "Matrix:";
	PrintMatrix(arr);
	Trianglize(arr);
	cout << "Tian:";
	PrintMatrix(arr);
}

