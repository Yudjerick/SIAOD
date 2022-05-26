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

//добаление символа в конец строки
void AddChar(char* A, char B)
{
    int alen = strlen(A);
    A[alen + 1] = A[alen];
    A[alen] = B;
}

//проверяет одинаковы ли строки
bool Compare(char* A, char* B)
{
    int i = 0;
    while (true)
    {
        if (A[i] != B[i]) {
            return false;
        }
        if (A[i] == '\0') {
            return true;
        }
        i++;
    }
}

//сравнение поиск данного слова в строке
bool CompareWords(char* str, char* flag)
{
    char word[100] = "";
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            if (Compare(word, flag)) {
                cout << word << endl;
                return true;
            }
            word[0] = '\0';
        }
        else
        {
            AddChar(word, str[i]);
        }
    }
    if (Compare(word, flag)) {
        cout << word << endl;
        return true;
    }
    return false;
    word[0] = '\0';
}

//сравнение слов в строках и печать одинаковых слов
void Words(char* str, char* str2)
{
    int wordsPrinted = 0;
    char word[100] = "";
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            if (word[0] == '\0') {
                continue;
            }
            if (CompareWords(str2, word))
            {
                wordsPrinted++;
            }
            word[0] = '\0';
        }
        else
        {
            AddChar(word, str[i]);
        }
    }
    if (CompareWords(str2, word))
    {
        wordsPrinted++;
    }
    word[0] = '\0';
    if (wordsPrinted == 0) {
        cout << "No same words";
    }
}

int main()
{
    char A[100] = "";
    char B[100] = "";

    cin.getline(A, 100);
    cin.getline(B, 100);
    Words(A, B);
}

