#include <iostream>
#include <ctime>
using namespace std;

const int Rows = 100;
const int Cols = 100;

void InputMatrix(char arr[][Cols], int n, int m)
{
	cout << "Enter matrix elements (x , 0 , _ ) separated by space" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void InputMatrixRand(char arr[][Cols], int n, int m)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char el;
			int z = (int)rand() % 3;
			switch(z)
			{
			case 0:
				el = '0';
				break;
			case 1:
				el = 'x';
				break;
			default:
				el = '_';
			}
			arr[i][j] = el;
		}
	}
}

void PrintMatrix(char arr[][Cols], int n, int m)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

bool Won(char arr[][Cols], int n, int m)
{

	if (n < 5 && m < 5)
	{
		return false;
	}

	for (int i = 0; i < n; i++)
	{
		int horizontal = 0;
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'x')
			{
				horizontal++;
				if (horizontal == 5)
				{
					return true;
				}
			}
			else
			{
				horizontal = 0;
			}
		}
	}

	for (int j = 0; j < m; j++)
	{
		int vertical = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][j] == 'x')
			{
				vertical++;
				if (vertical == 5)
				{
					return true;
				}
			}
			else
			{
				vertical = 0;
			}
		}
	}

	for (int i = 0; i < max(n, m) * 2; i++)
	{
		int diagonal = 0;
		for (int j = 0; j <= i; j++)
		{
			if (i - j < n && j < m)
			{
				if (arr[i - j][j] == 'x')
				{
					diagonal++;
					if (diagonal == 5) {
						return true;
					}
				}
				else
				{
					diagonal = 0;
				}
			}
		}
	}

	for (int i = 0; i < max(n, m) * 2; i++)
	{
		int diagonal = 0;
		cout << endl;
		for (int j = 0; j <= i; j++)
		{
			if (i - j < n && j < m)
			{
				if (arr[i - j][m - j - 1] == 'x')
				{
					diagonal++;
					if (diagonal == 5) {
						return true;
					}
				}
				else
				{
					diagonal = 0;
				}
			}
		}
	}


	return false;
}

int main()
{
	int n, m, t;
	cout << "Enter number of strings: ";
	cin >> n;
	cout << "Enter number of columns: ";
	cin >> m;
	char arr[Rows][Cols];
	cout << "Choose input type (1 - hand input, 0 - random input)";
	cin >> t;
	t == 1 ? InputMatrix(arr, n, m) : InputMatrixRand(arr, n, m);
	cout << "Your matrix:";
	PrintMatrix(arr, n , m);
	if (Won(arr, n, m))
		cout << "Team X won";
	else
		cout << "Team X did not win";
}


