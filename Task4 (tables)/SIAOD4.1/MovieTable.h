#pragma once
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
    Movie strings[100];
    int max;
    int n;
};