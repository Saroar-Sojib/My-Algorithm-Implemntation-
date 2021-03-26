#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int value;
    struct node* next;
    struct node* prev;
};
struct node* head;
struct node* tail;

void init()
{
    head=NULL;
    tail=NULL;
}

void insertFirst(int element)
{
    struct node* newItem;
    newItem=new node;
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->value=element;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        newItem->next=head;
        newItem->value=element;
        newItem->prev=NULL;
        head->prev=newItem;
        head=newItem;
    }
}

void insertLast(int element)
{
    struct node* newItem;
    newItem=new node;
    newItem->value=element;
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        newItem->prev=tail;
        tail->next=newItem;
        newItem->next=NULL;
        tail=newItem;
    }
}



void deleteFirst()
{
    if(head==NULL)
    {
        return;
    }
    if(head==tail)///one element in the list
    {
        struct node* cur;
        cur=head;
        head=NULL;
        tail=NULL;
        delete cur;
        return;
    }
    else
    {
        struct node* cur;
        cur=head;
        head=head->next;
        head->prev=NULL;
        delete cur;
    }
}


void deleteItem(int element)
{
    struct node* temp;
    temp=head;
    if(head==tail)
    {
        if(head->value!=element)
        {
            cout<<"could not delete"<<endl;
            return;
        }
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
    if(head->value==element)
    {
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }
    else if(tail->value==element)
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
        return;
    }
    while(temp->value!=element)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"element not found"<<endl;
            return;
        }
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete temp;
}

struct node* searchItem(int element)
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->value==element)
        {
            return temp;
            break;
        }
        temp=temp->next;
    }
    return NULL;
}

void printList()
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->value);
        temp=temp->next;
    }
    puts("");
}




int dltfrst()
{
    if(head==NULL)
    {
        return 0;
    }
    int prev;
    prev=head->value;
    if(head==tail)///one element in the list
    {
        struct node* cur;
        cur=head;
        head=NULL;
        tail=NULL;
        delete cur;
        return prev;
    }
    else
    {
        struct node* cur;
        cur=head;
        head=head->next;
        head->prev=NULL;
        delete cur;
        return prev;
    }
}




int main()
{
    init();

    int choice;
    while(1)
    {
        printf("1.InsertFirst 2. InsertLast  3.PrintList 4.DeleteItem 5.DeleteHead\n");

        cin>>choice;
        if(choice==1)
        {
            int element;
            cout<<"Enter element: ";
            cin>>element;
            insertFirst(element);
            printList();
        }
        else if(choice==2)
        {
            int element;
            cout<<"Enter element: ";
            cin>>element;
            insertLast(element);
            printList();
        }


        else if(choice==3)
        {
            printList();
        }


        else if(choice==4)
        {
            int element;
            cin>>element;
            deleteItem(element);
            printList();
        }
       else if(choice==5)
        {
            deleteFirst();
            printList();
        }

    }
return 0;
}
