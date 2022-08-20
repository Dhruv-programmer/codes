#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
void insertAtHead(node *&head, int data)
{
    node *n = new node(data);
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
}
void insertAtEnd(node *&head, int data)
{
    node *n = new node(data);
    if (head == NULL)
        head = n;
    else
    {
        node *last = head;
        while (last->next != NULL)
            last = last->next;
        node *n = new node(data);
        last->next = n;
        n->prev = last;
    }
}
void insertAtpos(node *&head, int pos, int data)
{
    if (pos == 0)
    {
        insertAtHead(head, data);
        return;
    }
    // inserting between current and previous
    node* temp = head;
    while (pos>1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
        insertAtEnd(head, data);
    else
    {
        node *n = new node(data);
        temp->next->prev = n;
        n->next = temp->next;
        temp->next = n;
        n->prev = temp;
    }
}
void print(node *&head)
{
    node *a = head;
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    print(head);
    insertAtHead(head, 4);
    print(head);
    insertAtEnd(head, 56);
    print(head);
    insertAtpos(head, 0, 2);
    print(head);
    insertAtpos(head, 3, 99);
    print(head);
    return 0;
}