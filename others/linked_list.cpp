#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

class LinkedList
{
public:
    LinkedList()
    {
        head=new Node();
    }

    ~LinkedList()
    {
        Node *p=head,*q;
        while(p->next!=NULL)
        {
            q=p->next;
            p->next=q->next;
            delete q;
        }
    }

    void Insert(int x);

    void Print();

private:
    struct Node
    {
        int val;
        Node* next;
        Node():val(0),next(NULL){}
    }*head;
};

void LinkedList::Insert(int x)
{
    Node *p=new Node();
    p->val=x;
    p->next=head->next;
    head->next=p;
}

void LinkedList::Print()
{
    Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
        printf("%d ",p->val);
    }
}

int main()
{
    LinkedList list;
    list.Insert(1);
    list.Insert(2);
    list.Insert(5);
    list.Insert(6);
    list.Insert(7);
    list.Insert(8);
    list.Print();
    return 0;
}
