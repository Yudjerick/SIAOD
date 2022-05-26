#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void InsertionSort(vector<int>& a) 
{
    int buff = 0;
    int i, j;

    for (i = 1; i < a.size(); i++)
    {
        buff = a[i];
        for (j = i - 1; j >= 0 && a[j] > buff; j--)
        {
            a[j + 1] = a[j];
        }

        a[j + 1] = buff;
    }
}

void BucketSort(vector<int>& a) {
    int n = a.size();
    int ma = a[0];
    int mi = a[0];
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] < ma) {
            flag = false;
        }
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    if (flag) {
        return;
    }
    float range = ma - mi;
    vector<vector<int>> buckets;
    vector<int> empty;
    for (int i = 0; i < n; i++) {
        buckets.push_back(empty);
    }
    for (int i = 0; i < n; i++) {
        int index = floor(n * (a[i] - mi) / (range+1));
        buckets[index].push_back(a[i]);
        
    }
    for (int i = 0; i < n; i++) {
        if (buckets[i].size() > 1) {
            BucketSort(buckets[i]);
        }
    }
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            answer.push_back(buckets[i][j]);
        }
    }
    a = answer;
}

vector<int> Merge(vector<int> b, vector<int> c) 
{
    vector<int> ans;
    while (b.size() > 0 && c.size() > 0) {
        if (b[0] > c[0]) {
            ans.push_back(c[0]);
            c.erase(c.begin());
        }
        else {
            ans.push_back(b[0]);
            b.erase(b.begin());
        }
    }
    for (int i = 0; i < b.size(); i++) {
        ans.push_back(b[i]);
    }
    for (int i = 0; i < c.size(); i++) {
        ans.push_back(c[i]);
    }
    return ans;
}

void NaturalMergeSort(vector<int>& a) {

    while(true)
    {
        vector<int> b, c;
        bool bSelected = true;
        for (int i = 0; i < a.size(); i++) {
            if (bSelected) {
                if (b.empty() || a[i] >= b.back())
                    b.push_back(a[i]);
                else {
                    c.push_back(a[i]);
                    bSelected = !bSelected;
                }
            }
            else
            {
                if (c.empty() || a[i] >= c.back())
                    c.push_back(a[i]);
                else {
                    b.push_back(a[i]);
                    bSelected = !bSelected;
                }
            }
        }
        a = Merge(b, c);
        bool flag = true;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] < a[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag)
            return;
    }
}

int SortingTime(vector<int>& a) 
{
    unsigned int start_time = clock();
    BucketSort(a);
    unsigned int end_time = clock();
    return end_time - start_time;
}

void ArrInput(vector<int>& a, int n) 
{
    int inf;
    for (int i = 0; i < n; i++) {
        cin >> inf;
        a.push_back(inf);
    }
}

void ArrRandom(vector<int>& a, int n) 
{
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int inf = rand()%100;
        a.push_back(inf);
    }
}

int main()
{
    vector<int> a;
    ArrRandom(a, 1000);
    vector<int> b = a;
    vector<int> c = a;

    unsigned int start_time = clock();
    InsertionSort(a);
    unsigned int end_time = clock();
    int insertT =  end_time - start_time;
    cout << "InsertionSort: "<< insertT << endl;

    start_time = clock();
    InsertionSort(b);
    end_time = clock();
    int bucketT = end_time - start_time;
    cout << "BucketSort: "<< bucketT << endl;

    start_time = clock();
    NaturalMergeSort(c);
    end_time = clock();
    int nmT = end_time - start_time;
    cout << "NaturalMergeSort: "<< nmT << endl;  
}