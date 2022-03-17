#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool InStr(string A, vector<string> arr) 
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == A) 
        {
            return true;
        }
    }
    return false;
}

string CutStr(string A, int step)
{
    string r = "";
    for (int i = step + 1; i < size(A); i++)
    {
        r += A[i];
    }
    return r;
}

string PopWord(string &A)
{
    string word = "";
    int cor = 0;
    for (int i = 0; i < size(A); i++) {
        if (A[i] == ' ') 
        {
            if (word == "")
            {
                cor++;
                continue;
            }
            A = CutStr(A, size(word) + cor);
            return word;
        }
        word += A[i];
    }
    A = CutStr(A, size(word) + cor);
    return word;
}

vector<string> FindSame(string A, string B) 
{
    vector<string> r;
    string a = A;
    while (a.length() > 0)
    {
        string word = PopWord(a);
        string b = B;
        while (b.length() > 0)
        {
            string wordB = PopWord(b);
            if (wordB == word) {
                //cout << word << endl;

                if (!InStr(word, r))
                {
                    r.push_back(word);
                }
            }
        }
    }
    return r;
}



int main()
{
    string A = "This is e first phrase";
    string B = "And it is second not first n This";

    getline(cin, A);
    getline(cin, B);
    
    vector<string> sameWords;
    sameWords = FindSame(A,B);
    if (sameWords.size() > 0) {
        for (int i = 0; i < sameWords.size(); i++)
        {
            cout << sameWords[i] << endl;
        }
    }
    else 
    {
        cout << "No same words";
    }

}
