#include <iostream>
#include <string>
#include<cmath>
using namespace std;

struct Node
{
    string info;
    Node* next;

    Node(string i) {
        info = i;
        next = nullptr;
    }
};

struct Stack
{
    Node* top;
    int size;

    Stack() {
        top = nullptr;
        size = 0;
    }

    void Push(string info) //вставка нового элемента в начало списка
    {
        Node* newEl = new Node(info);
        newEl->next = top;
        top = newEl;
        size++;
    }

    string Top()
    {
        return top->info;
    }

    string Pop()
    {
        Node* toDelete = top;
        string r = top->info;
        top = top->next;
        delete toDelete;
        size--;
        return r;
    }

    void Print() //вывод списка
    {
        Node* list = top;
        while (list)
        {
            cout << list->info;
            list = list->next;
        }
    }
};

string opResult(string as, char op, string bs) {
    int a = stoi(as);
    int b = stoi(bs);
    if (op == '+')
        return to_string(a + b);
    if (op == '-')
        return to_string(a - b);
    if (op == '*')
        return to_string(a * b);
    if (op == '/')
        return to_string(a / b);
    if (op == '^')
        return to_string(pow(a,b));
}

int CalculatePostfix(string p) {
    string co = "";
    Stack w1;
    for (int i = 0; i < p.length(); i++) {
        if (isdigit(p[i]))

            co += p[i];
        if (p[i] == ' ' && co != "") {
            w1.Push(co);
            co = "";
        }
        if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/' || p[i] == '^')
        {
            string a = w1.Pop();
            string b = w1.Pop();
            w1.Push(opResult(b, p[i], a));
        }

    }
    return stoi(w1.Top());
}

int main()
{
    cout << CalculatePostfix("6 2 2 ^ + 3 ^");
}
