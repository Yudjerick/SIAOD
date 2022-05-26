#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

int MoorSearch(string ori,string sub)
{

	int* table = MakeTable(sub);
	char last = sub[sub.length() - 1];
	int step = 6;
	for (int i = sub.length() - 1; i < ori.length(); i += step) {
		if (ori[i] == last) {
			if (Compare(ori, i, sub))
				return i-sub.length()+1;
		}
		step = table[ori[i]];
	}
	return -1;
}

void Replace(string &ori, string old,string nstr) {
	ori.replace(MoorSearch(ori, old), old.length(), nstr);
}

string GetStringToReplace(string ori, int idx) {
	string r = "";
	while (ori[idx] != ';') {
		r += ori[idx];
		idx++;
	}
	return r;
}

string GetVarName(string ori, int idx) {
	string s = GetStringToReplace(ori,idx);
	int start = MoorSearch(s, " ");
	int end = MoorSearch(s, "=");
	if (end == -1) {
		end = s.length();
	}
	string r = "";
	for (int i = start + 1; i < end; i++) {
		r += s[i];
	}
	return r;
}

void ReplaceVars(string& ori) {
	vector<string> vars = { "char", "int", "long", "short", "double", "float", "string", "bool" };
	for (int i = 0; i < vars.size(); i++) 
	{
		string toFind = vars[i] + " ";
		while (MoorSearch(ori, toFind) != -1) {
			string toReplace = GetStringToReplace(ori, MoorSearch(ori, toFind));
			string varName = GetVarName(ori, MoorSearch(ori, toFind));
			Replace(ori, toReplace, vars[i] + "* " + varName + "= NULL");
		}
	}
}


int main()
{
	string data = "char symbol = 'j'; int a = 1; cin >> a; int b; cin >> b; cout << a + b; float number;";
	cout << data << endl << endl;
	ReplaceVars(data);
	cout << data << endl;
}
