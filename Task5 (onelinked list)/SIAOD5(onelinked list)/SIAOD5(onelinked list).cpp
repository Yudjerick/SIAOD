// вариант = 22 % 17 + 1 = 6
#include <iostream>
using namespace std;

struct Node
{
    double info;
    Node* next;

    Node(double i) {
        info = i;
        next = nullptr;
    }
};

void PushForward(Node* &list, double info) //вставка нового элемента в начало списка
{
    Node* newEl = new Node(info);
    newEl->next = list;
    list = newEl;
} 

void PushBackNode(Node*& list, Node* el) { //вставка уже существуещего узла в конец списка
    Node* last = list;
    while (last->next) {
        last = last->next;
    }
    last->next = el;
    el->next = nullptr;
}

void PrintList(Node* list) //вывод списка
{
    while (list) 
    {
        cout << list->info << "  ";
        list = list->next;
    }
}

void InsertNode(Node*& list, Node* el, int pos) //вставка уже существуещего узла на какую-либо позицию в списке
{
    Node* post = list;
    Node* pre = nullptr;
    for (int i = 0; i < pos; i++) {
        pre = post;
        post = post->next;
    }
    el->next = post;
    if (pre) {
        pre->next = el;
    }
    else
    {
        list = el;
    }
}

void InsertInfo(Node*& list, double info, int pos) //вставка нового элемента в список
{
    Node* el = new Node(info);
    InsertNode(list, el, pos);
}

void EraseNode(Node*& list, Node* el) //удаление узла из списка по указателю
{
    Node* post = list;
    Node* pre = nullptr;
    while (post && post!= el)
    {
        pre = post;
        post = post->next;
    }
    if (!post) {
        return;
    }
    post = post->next;
    if (pre) {
        delete pre->next;
        pre->next = post;
    }
    else {
        delete list;
        list = post;
    }
}

Node* UnboundNode(Node*& list, Node* el) // разрывает связь узла со списком, при этом узел не удаляется
{
    Node* post = list;
    Node* pre = nullptr;
    while (post && post != el)
    {
        pre = post;
        post = post->next;
    }
    if (!post) {
        return nullptr;
    }
    post = post->next;
    if (pre) {
        Node* r = pre->next;
        pre->next = post;
        r->next = nullptr;
        return r;
    }
    else {
        Node* r = list;
        list = post;
        r->next = nullptr;
        return r;
    }
}

Node* Max(Node* list) //поиск максимального элемента сптска
{
    Node* m = list;
    while (list)
    {
        if (m->info < list->info) {
            m = list;
        }
        list = list->next;
    }
    return m;
}

void DeleteNeg(Node*& list) //удаление первого отрицательного числа
{
    Node* el = list;
    while (el) 
    {
        if (el->info < 0) {
            EraseNode(list, el);
            return;
        }
        el = el->next;
        
    }
}

void Insert2(Node* &list, double info1, double info2)  //вставка двух новых элементов перед последним
{
    Node* last = list;
    int i = 0;
    while (last->next)
    {
        i++;
        last = last->next;
    }
    InsertInfo(list, info2,i);
    InsertInfo(list, info1,i);
}

void MaxToEnd(Node*& list) //перемещение максимального числа в конец списка
{
    PushBackNode(list,UnboundNode(list, Max(list)));
}

int main()
{
    cout << "original list:" << endl;
    Node* mylist = new Node(5);
    PushForward(mylist, -0.5);
    PushForward(mylist, 25);
    PushForward(mylist, 2);
    PushForward(mylist, -30);
    PushForward(mylist, 7);
    PrintList(mylist);
    cout << endl << endl;
    
    cout << "two elements inserted before last:" << endl;
    Insert2(mylist, 1, 2);
    PrintList(mylist);
    cout << endl << endl;

    cout << "first negative element deleted:" << endl;
    DeleteNeg(mylist);
    PrintList(mylist);
    cout << endl << endl;

    cout << "max element moved to the end of list:" << endl;
    MaxToEnd(mylist);
    PrintList(mylist);
}

