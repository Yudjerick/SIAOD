#ifndef __MovieTable__
#define __MovieTable__
using namespace std;

struct Date
{
    int day;
    int month;
};

struct Time
{
    int hour;
    int minute;
};

struct Movie
{
    string theatre;
    string film;
    Date date;
    Time time;
    float price;
};

struct Table
{
    Movie* strings = nullptr;
    int n;
};
#endif