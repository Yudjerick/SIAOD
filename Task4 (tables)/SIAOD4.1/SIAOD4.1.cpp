#include <iostream>
#include <iomanip>
#include <sstream>
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

string DateToS(Date &d) {
    string r = "";
    if (d.day < 10) {
        r += "0";
    }
    r += to_string(d.day);
    r += ".";
    if (d.month < 10) {
        r += "0";
    }
    r += to_string(d.month);
    return r;
}

string TimeToS(Time &t) {
    string r = "";
    if (t.hour < 10) {
        r += "0";
    }
    r += to_string(t.hour);
    r += ":";
    if (t.minute < 10) {
        r += "0";
    }
    r += to_string(t.minute);
    return r;
}



void Print(Table tab)
{
	cout << setw(20) << left << "theatre";
	cout << setw(30) << left << "film";
	cout << setw(15) << left << "date";
	cout << setw(15) << left << "time";
	cout << setw(15) << left << "price"<< endl;
    for (int i = 0; i < tab.n; i++) {
        cout << setw(20) << left << tab.strings[i].theatre;
        cout << setw(30) << left << tab.strings[i].film;
        cout << setw(15) << left << DateToS(tab.strings[i].date);
        cout << setw(15) << left << TimeToS(tab.strings[i].time);
        cout << setw(15) << left << tab.strings[i].price << endl;
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

void AddMovie(Movie m, Table &t) 
{
    for (int i = 0; i < t.n; i++) 
    {
        if (t.strings[i].theatre == m.theatre)
        {
            for (int j = t.n; j > i; j--) 
            {
                t.strings[j] = t.strings[j - 1];
            }
            t.strings[i] = m;
            t.n++;
            return;
        }
    }
    t.strings[t.n] = m;
    t.n++;
}


int main()
{
    Date apr5 = { 5,4 };
    Time noon = { 12,0 };
    Movie pirates = { "formula","Pirates", apr5, noon, 400 };
    Movie alladin = { "formula","Alladin", apr5, noon, 300 };
    Movie backToF = { "retro", "BackToTheFuture", {1,5}, {17,40} ,250 };
	Table afisha;
    afisha.n = 0;
    AddMovie(backToF, afisha);
    AddMovie(pirates, afisha);
    AddMovie(alladin, afisha);
    //AddMovie(MakeMovie(), afisha);
	Print(afisha);
}
