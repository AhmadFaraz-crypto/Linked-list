#include<iostream>
#include<stdio.h>
using namespace std;
struct link
{
    int data;
    link *next;
};
struct link *START=NULL;
struct link *createnode()
{
    struct link *n;
    n=(struct link *)malloc(sizeof(struct link));
    return (n);
}
void add()
{
    struct link *ptr, *temp;
    temp=createnode();
    cout<<"\n\t\t\tEnter a number ";
    cin>>temp->data;
    if(START==NULL)
    {
        START=temp;
    }
    else
    {
        ptr=START;
        while(ptr->next!=NULL)ptr=ptr->next;
        ptr->next=temp;
    }
}
void del(int v)
{
    struct link *temp, *pre;
    temp=START;
    if(temp->data==v)
    {
        START=temp->next;
        delete temp;
        cout<<endl<<v<<" Has been deleted ";
        return;
    }
    pre=temp;
    while(temp!=NULL)
    {
        if(temp->data==v)
        {
            pre->next=temp->next;
            delete temp;
            cout<<"\n\n\t\tValue deleted ";
            return;
        }
        pre=temp;
        temp=temp->next;
    }
    cout<<endl<<v<<"not found";
}
void show()
{
    struct link *temp;
    temp=START;
    cout<<"\n\n\n\t\t\tThe list as follows:  ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int menu()
{
    int ch;
    cout<<"\n\t\tEnter a choice ";
    cin>>ch;
    return (ch);
}
int main()
{
    cout<<"\n\t\t\t\t==============MENU==============="<<endl<<endl;
    cout<<"\n\t\t\t\t    1. ADD VALUE "<<endl;
    cout<<"\n\t\t\t\t    2. DELETE VALUE "<<endl;
    cout<<"\n\t\t\t\t    3. SHOW LIST "<<endl;
    cout<<"\n\t\t\t\t    4. EXIT "<<endl;
    while(1)
    {
        switch(menu())
        {
        case 1:
            add();
            break;
        case 2:
            int n;
            cout<<"\n\t\t\tEnter a number ";
            cin>>n;
            del(n);
            break;
        case 3:
            show();
            cout<<endl<<endl;
            break;
        case 4:
            exit (0);
        default:
            cout<<"Invalid choice ";
        }

    }
}
