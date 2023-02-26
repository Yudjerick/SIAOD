#include <iostream>
#include <vector>
using namespace std;

//Task 9 of SIAOD
struct CityInfo
{
    int key;
    string name;
};

CityInfo LinearSearch(vector<CityInfo> arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].key == key) {
            return arr[i];
        }
    }
}

int Hash(int ori) {
    return ori % 100;
}

struct HashTable
{
    vector<CityInfo> h[100];

    void Add(CityInfo ci)
    {
        h[Hash(ci.key)].push_back(ci);
    }

    void HashArr(vector<CityInfo> arr) {
        for (int i = 0; i < arr.size(); i++)
        {
            Add(arr[i]);
        }
    }

    CityInfo Search(int key) {
        return LinearSearch(h[Hash(key)], key);
    }
};

vector<CityInfo> MoscowArr(int n) {
    vector<CityInfo> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back({ 495,"Moscow" });
    }
    return arr;
}

int main()
{
    vector<CityInfo> arr = MoscowArr(100000);
    arr[50000] = { 555,"NewYork" };
    HashTable table;
    table.HashArr(arr);
    int st = clock();
    cout << table.Search(555).name << endl;
    int ft = clock();
    cout << "HashTable Searching: " << ft - st << endl;
    st = clock();
    cout  << LinearSearch(arr, 555).name << endl;
    ft = clock();
    cout << "Linear Searching: "<< ft - st << endl;
}
