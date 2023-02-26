#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Task 10 part 1 od SIAOD

int Offset(string sub, char c)
{
	for (int i = sub.length() - 2; i >= 0; i--)
	{
		if (c == sub[i]) {
			return sub.length() - 1 - i;
		}
	}
	return sub.length();
}

int* MakeTable(string sub)
{
	int* table = new int[256];
	for (int i = 0; i < 256; i++) {
		table[i] = Offset(sub, (char)i);
	}
	return table;
}

bool Compare(string ori, int idx, string sub)
{
	int start = idx - sub.length() + 1;
	for (int i = 0; i < sub.length(); i++) {
		if (ori[i + start] != sub[i])
			return false;
	}
	return true;
}

int MoorSearch(string ori, string sub)
{

	int* table = MakeTable(sub);
	char last = sub[sub.length() - 1];
	int step = 6;
	for (int i = sub.length() - 1; i < ori.length(); i += step) {
		if (ori[i] == last) {
			if (Compare(ori, i, sub))
				return i - sub.length() + 1;
		}
		step = table[ori[i]];
	}
	return -1;
}

void Replace(string& ori, string old, string nstr) {
	ori.replace(MoorSearch(ori, old), old.length(), nstr);
}

string Modify(string ori) 
{
	for (int i = 0; i < ori.length(); i++) 
	{
		if (ori[i] == 'У' || ori[i] == 'К' || ori[i] == 'Е' || ori[i] == 'Н' || ori[i] == 'Х'
			|| ori[i] == 'В' || ori[i] == 'А' || ori[i] == 'Р' || ori[i] == 'О'
			|| ori[i] == 'С' || ori[i] == 'М' || ori[i] == 'Т') 
		{
			ori[i] = 'У';
		}
		if ((int)ori[i] > 48 && (int)ori[i] < 58)
		{
			ori[i] = '1';
		}
	}
	return ori;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string data = ": БМВ Х3 В123АУ777 черн. Е83 2.0d";
	int search3 = MoorSearch(Modify(data), "У111УУ111");
	if (search3 != -1) 
	{
		for (int i = search3; i < search3 + 9; i++)
		{
			cout << data[i];
		}
		return;
	}
	int search2 = MoorSearch(Modify(data), "У111УУ11");
	if (search2 != -1)
	{
		for (int i = search2; i < search2 + 8; i++)
		{
			cout << data[i];
		}
	}
}
