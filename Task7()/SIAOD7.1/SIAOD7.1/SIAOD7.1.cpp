#include <iostream>
#include <stack>
using namespace std;

int Priority(char c) {
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	if (c == '^')
		return 3;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string original = "(a+b^b)^c";
	cout << "original: " << original;
	string result = "";
	stack<char> st;
	int i;
	for (i = 0; i < original.length(); i++) 
	{
		if (original[i] == '(') {
			st.push(original[i]);
			cout << i << ") открывающую скобку в стек" << endl;
		}
		else if (original[i] == ')')
		{
			cout << i << ") Все операции до скобки из стэка" << endl;
			while (st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (isalpha(original[i])) 
		{
			result += original[i];
			cout << i << ") Операнд "<< original[i] <<" в result" << endl;
		}
		else 
		{
			if (st.empty() || Priority(st.top()) < Priority(original[i])) 
			{
				st.push(original[i]);
				cout << i << ") Операцию " << original[i] << " в стэк" << endl;
			}
			else 
			{
				result += st.top();
				cout << i << ") Операцию " << st.top() << " из стэка" << endl;
				st.pop();
				st.push(original[i]);
				cout << i << ") Операцию " << original[i] << " в стэк" << endl;
			}
		}
	}
	cout << i << ") Все операции до скобки из стэка" << endl;
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	cout << result;
}