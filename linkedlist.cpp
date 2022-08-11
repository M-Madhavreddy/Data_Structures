#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node * next;
}*head,*newnode,*temp ;


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
    cout<<"enter the number of nodes\n";
    cin>>n;
    
    int num;

    for(int i=0;i<n;i++)
    {
        cin>>num;
        linklist(num);
    }

    print();
}