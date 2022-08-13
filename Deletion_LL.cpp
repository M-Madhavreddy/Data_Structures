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

void Delete_beg()
{
    temp=head;
    head=head->next;
    delete(temp);
}

void Delete_pos()
{  
    int pos;
    cout<<"enter the pos >> ";
    cin>>pos;
    struct node *previous;
    temp=head;
    while(--pos)
    {
        previous=temp;
        temp=temp->next;
    }
    previous->next=temp->next;
    delete(temp);
}

void Delete_end()
{
    struct node *previous;
    temp=head;
    while(temp->next != NULL)
    {
        previous=temp;
        temp=temp->next;
    }
    previous->next=NULL;
    delete(temp);
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

   int choice;
    while(1)
    {
        cout<<"menu Deletion>> \n";
        cout<<"1.At beginning \n2.At given pos \n3.At End \n4.Print \n5.Exit \n";
        cout<<"enter your choice >> ";
        cin>>choice;
        
        switch(choice)
        {
            case 1 : Delete_beg();
                     break;
            case 2 : Delete_pos();
                     break;
            case 3 : Delete_end();
                     break;
            case 4 : print();
                     break;
            case 5 : exit(0);
            default :cout<<"invalid Input \n";
        }
    }
}