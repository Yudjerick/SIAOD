//вариант 22
#include <iostream>
using namespace std;

struct Node
{
    char info;
    Node* next;

    Node(char i) {
        info = i;
        next = nullptr;
    }
};

void PushForward(Node*& list, char info) //вставка нового элемента в начало списка
{
    Node* newEl = new Node(info);
    newEl->next = list;
    list = newEl;
}

void PrintList(Node* list) //вывод списка
{
    while (list)
    {
        cout << list->info;
        list = list->next;
    }
}

bool IsPalindrom(Node* first, Node* end = nullptr) 
{
    Node* last = first;
   
    while (last->next != end)
        last = last->next;

    if (first->next == last || first == last)
        return true;

    return last->info == first->info && IsPalindrom(first->next, last);
}

int main()
{
    //тестирование

    Node* A = new Node('R');
    PushForward(A, 'A');
    PushForward(A, 'C');
    PushForward(A, 'E');
    PushForward(A, 'C');
    PushForward(A, 'A');
    PushForward(A, 'R');
    PrintList(A);
    cout << " " << IsPalindrom(A) << endl;

    Node* B = new Node('A');
    PushForward(B, 'B');
    PushForward(B, 'B');
    PushForward(B, 'A');
    PrintList(B);
    cout << " " << IsPalindrom(B) << endl;

    Node* C = new Node('R');
    PushForward(C, 'A');
    PushForward(C, 'C');
    PrintList(C);
    cout << " " << IsPalindrom(C) << endl;

    Node* D = new Node('E');
    PushForward(D, 'Y');
    PushForward(D, 'E');
    PrintList(D);
    cout << " " << IsPalindrom(D) << endl;
}