#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} * head, *newnode, *temp;

void linklist(int num)
{
    // newnode= new node;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
    {
        temp = head = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = temp->next;
    }
}

void InsertBeg(int num)
{
    newnode = new node;
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}

void InsertEnd(int num)
{
    newnode = new node;
    newnode->data = num;
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void InsertPos(int num)
{
    int pos;
    cout << "enter the position \n";
    cin >> pos;

    newnode = new node;
    newnode->data = num;
    newnode->next = NULL;
    temp = head;
    while (--pos)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void Print()
{
    temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << temp->data;
}
void Delete_beg()
{
    temp = head;
    head = head->next;
    delete (temp);
}

void Delete_pos()
{
    int pos;
    cout << "enter the pos >> ";
    cin >> pos;
    struct node *previous;
    temp = head;
    while (--pos)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = temp->next;
    delete (temp);
}

void Delete_end()
{
    struct node *previous;
    temp = head;
    while (temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    delete (temp);
}

void reverselinklist()
{
    node *prev = new node;
    node *after = new node;

    prev = temp = head;
    temp = temp->next;
    after = temp->next;
    head->next = NULL;
    while (after != NULL)
    {
        temp->next = prev;
        prev = temp;
        temp = after;
        after = after->next;
    }
    temp->next = prev;
    head = temp;
}

int main()
{
    int n;
    cout << "enter the number of nodes >> ";
    cin >> n;

    int num;
    while (n--)
    {
        cin >> num;
        linklist(num);
    }

    int choice;
    while (1)
    {
        cout << "Insertion >> 1.At Beginning \n2.At Given Position \n3.At End\n";
        cout << "Deletion >> 4.At Beginning \n5.At Given Position \n6.At End \n7.Reversal of linkedlist \n8.prnit \n9.Exit \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the element to be inserted \n";
            cin >> num;
            InsertBeg(num);
            break;
        case 2:
            cout << "enter the element to be inserted \n";
            cin >> num;
            InsertPos(num);
            break;
        case 3:
            cout << "enter the element to be inserted \n";
            cin >> num;
            InsertEnd(num);
            break;
        case 4:
            Delete_beg();
            break;
        case 5:
            Delete_pos();
            break;
        case 6:
            Delete_end();
            break;
        case 7:
            reverselinklist();
            break;
        case 8:
            Print();
            break;
        case 9:
            exit(0);
        default:
            cout << "invalid input \n";
        }
    }
}