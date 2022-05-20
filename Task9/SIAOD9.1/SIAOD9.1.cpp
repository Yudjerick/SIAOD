#include <iostream>
#include <vector>
using namespace std;

struct CityInfo
{
    int key;
    string name;
};

CityInfo LinearSearch(vector<CityInfo> arr,int key)
{
    for (int i = 0; i < arr.size(); i++) 
    {
        if (arr[i].key == key) {
            return arr[i];
        }
    }
}

struct HashTable
{
    CityInfo h[1000];

    void Add(CityInfo ci)
    {

    }
};

int main()
{
    vector<CityInfo> arr = { {495,"Moscow"},{300,"NewYork"},{245,"London"} };
    cout << LinearSearch(arr,495).name;
}