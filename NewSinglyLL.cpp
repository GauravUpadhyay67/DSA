#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode()
    {
        this->next = NULL;
        cout << "Default Ctor" << endl;
    }

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }

};

void printLL(ListNode* head)
{
    ListNode* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(ListNode* head)
{
    ListNode* temp = head;
    int len = 0;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(ListNode* &head, ListNode* &tail, int data)
{
    if(head == NULL)
    {
        ListNode* newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        ListNode* newNode = new ListNode(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(ListNode* &head, ListNode* &tail, int data)
{
    if(head == NULL)
    {
        ListNode* newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
       ListNode* newNode = new ListNode(data);
       tail->next = newNode;
       tail = newNode;
    }
}

void insertAtPosition(ListNode* &head, ListNode* &tail, int data, int pos, int size)
{
    if(pos <= 1)
    {
        insertAtHead(head, tail, data);
    }
    else if(pos > size)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        ListNode* newNode = new ListNode(data);
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }

        newNode->next = curr;
        prev->next = newNode;

    }
}

void deleteNode(ListNode* &head, ListNode* &tail, int pos)
{
    if(head == NULL)
    {
        cout << "Can not delete, Because LL is empty" << endl;
        return;
    }

    if(head == tail)
    {
        ListNode* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    int len = getLength(head);
    if(pos > len || pos < 1)
    {
        cout << "Invalid Postion" << endl;
        return;
    }

    if(pos == 1)
    {
        ListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if(pos == len)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        tail = prev;
        delete curr;
    }
    else
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main()
{
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    

    int size = getLength(head);

    // insertAtPosition(head, tail, 70, -2, size);
    printLL(head);
    deleteNode(head,tail,6);
    printLL(head);
}