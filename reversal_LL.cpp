#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
}*head,*newnode,*temp;


void linklist(int num)
{
    //newnode= new node;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if( head == NULL)
    {
        temp=head=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=temp->next;
    }
}



void reverselinklist()
{
   node *prev =new node;
   node *after =new node;

   prev=temp=head;
   temp=temp->next;
   after=temp->next;
   head->next=NULL;
   while(after!=NULL)
   {
     temp->next=prev;
     prev=temp;
     temp=after;
     after=after->next;
   }
   temp->next=prev;
   head=temp;
}

void print()
{
   temp=head;
   while(temp -> next != NULL)
   {
    cout<<temp->data<<" -> ";
    temp=temp->next;
   }
   cout<<temp->data;
}


int main()
{
    int n;
    cout<<"Enter the no of nodes \n";
    cin>>n;
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        linklist(num);
    }

    reverselinklist();
    print();
}