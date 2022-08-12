#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head,*newnode,*temp;


void linklist(int num)
{
  newnode = new node;
  newnode -> data =num;
  newnode -> next =NULL;
  if(head == NULL)
  {
    temp=head=newnode;
  }
  else{
    temp->next=newnode;
    temp=temp->next;
  }
}

void InsertBeg(int num)
{
    newnode =new node;
   newnode -> data =num;
  newnode -> next =head;
  head = newnode;
}

void InsertEnd(int num)
{
    newnode = new node;
    newnode ->data = num;
    newnode -> next = NULL;
    temp=head;
    while(temp->next != NULL)
    {
      temp=temp->next;
    }
    temp->next=newnode;
}

void InsertPos(int num)
{    
    int pos;
    cout<<"enter the position \n";
    cin>>pos;

newnode = new node;
newnode -> data = num;
newnode -> next =NULL;
   temp=head;
    while(--pos)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void Print()
{
    temp=head;
    while(temp->next != NULL)
    {
      cout<<temp->data<<" --> ";
      temp=temp->next;
    }
    cout<<temp->data;
}
int main()
{
    int n;
    cout<<"enter the number of nodes >> ";
    cin>>n;

    int num;
    while(n--)
    {
        cin>>num;
        linklist(num);
    }
   
    int choice;
    while(1){
        cout<<"enter the element to be inserted \n";
        cin>>num;
        cout<<"Insertion >> 1.At Beginning \n2.At Given Position \n3.At End\n4.prnit \n5.Exit";
        cin>>choice;
        switch (choice)
        {
            case 1 : InsertBeg(num);
                     break;
            case 2 : InsertPos(num);
                     break;
            case 3 : InsertEnd(num);
                     break;
            case 4 : Print();
                     break;
            case 5 : exit(0);
            default : cout<<"invalid input \n";

        }
        
    }
}