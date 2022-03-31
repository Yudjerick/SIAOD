#include <iostream>
//#include "MovieTable.h"
#include <iomanip>
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
    Movie strings[100];
    int max;
    int n;
};

string DateToS(Date d) {
    string r = "";
    if (d.day < 10) {
        r += "0";
    }
    r += d.day;
    r += ".";
    if (d.month < 10) {
        r += "0";
    }
    r += d.month;
    return r;
}

string TimeToS(Time t) {
    string r = "";
    if (t.hour < 10) {
        r += "0";
    }
    r += t.hour;
    r += ":";
    if (t.minute < 10) {
        r += "0";
    }
    r += t.minute < 10;
    return r;
}



void Print(Table tab)
{
	cout << setw(15) << left << "theater";
	cout << setw(15) << left << "film";
	cout << setw(15) << left << "date";
	cout << setw(15) << left << "time";
	cout << setw(15) << left << "price"<< endl;
    cout << tab.n;
    for (int i = 0; i < tab.n; i++) {
        cout << setw(15) << left << tab.strings[i].theatre;
        cout << setw(15) << left << tab.strings[i].film;
        cout << setw(15) << left << DateToS(tab.strings[i].date);
        cout << setw(15) << left << TimeToS(tab.strings[i].time);
        cout << setw(15) << left << tab.strings[i].price;
    }

}

Movie MakeMovie() {
    cout << "enter theatre name, film name, day, month, hour, minute, price of ticket of movie session: ";
    string theatre, film;
    int day, month, hour, minute;

    float price;
    cin >> theatre >> film >> day >> month >> hour >> minute >> price;
    Movie m;
    m.theatre = theatre;
    m.film = film;
    m.date.day = day;
    m.date.month = month;
    m.time.hour = hour;
    m.time.minute = minute;
    m.price = price;
    return m;
}

void AddMovie(Movie m, Table t) {
    t.strings[t.n] = m;
    t.n = t.n+1;
}

int main()
{
	Table afisha;
    afisha.n = 0;
    AddMovie(MakeMovie(),afisha);
	Print(afisha);
}
