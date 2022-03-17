#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void Unit(char* A, char* B) 
{
    int alen = strlen(A);
    int blen = strlen(B);
    for (int i = alen; i < alen + blen + 1; i++) 
    {
        A[i] = B[i - alen];
    }
}

void AddChar(char* A, char B)
{
    int alen = strlen(A);
    A[alen + 1] = A[alen];
    A[alen] = B;
}

//Не работаект с вектором, может использовать просто двумерный массив???????
vector<char*> Words(char* str)
{
    vector<char*> arr;
    char word[100] = "";
    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] == ' ') 
        {
            cout << word << endl;
            word[0] = '\0';
            //arr.push_back(word);
        }
        else
        {
            AddChar(word, str[i]);
        }
    }
    cout << word << endl;
    word[0] = '\0';
    //arr.push_back(word);
    return arr;
}

int main()
{
    char A[100] = "";
    char B[100] = "";

    cin.getline(A, 100);
    cin.getline(B, 100);

    //Unit(A, B);
    //cout << A << endl;
    //AddChar(A, 'X');
    //cout << A;

    vector<char*> arr = Words(A);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
}

