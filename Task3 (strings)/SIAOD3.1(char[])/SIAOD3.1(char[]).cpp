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


//разобраться с этим
char** AddWord(char** arr, int &size, char* word)
{
    arr = new char* [size + 1];
    arr[size] = word;
    return arr;
}

bool Compare(char* A, char* B) 
{
    int i = 0;
    while (true)
    {
        
        
    }
}

//Не работаект с вектором, может использовать просто двумерный массив???????
void Words(char* str)
{
    char word[100] = "";
    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] == ' ') 
        {
            cout << word << endl;
            word[0] = '\0';
        }
        else
        {
            AddChar(word, str[i]);
        }
    }
    cout << word << endl;
    word[0] = '\0';
}

int main()
{
    char A[100] = "aaaa bbbb cccc";
    char B[100] = "eeeee dddddd";

    Words(A);

    //cin.getline(A, 100);
    //cin.getline(B, 100);

    
    //Unit(A, B);
    //cout << A << endl;
    //AddChar(A, 'X');
    //cout << A;

    /*char fir[1] = "";
    char** arr = new char*[1];
    arr[0] = fir;
    
    int size = 0;
    arr = AddWord(arr, size, A);
    arr = AddWord(arr, size, A);
    arr = AddWord(arr, size, B);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << size;*/
}

