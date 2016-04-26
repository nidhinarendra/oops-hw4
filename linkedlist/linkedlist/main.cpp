#include<iostream>
using namespace std;

struct node {
    int data;
    node* nextlink;
    node * nexthighest;
    };

node * head;
node* newnode;
node* temp;


node*  maxnode(node *ptr1, node * ptr2)
{
    if(ptr1 == NULL)
        return ptr2;
    if(ptr2 == NULL)
        return ptr1;
    
    if (ptr1 -> data  > ptr2 -> data)
        return ptr1;
    else
        return ptr2;
}

node * gethighest(node * localhead)
{
    if(localhead == NULL)
        return NULL;
    else
    {
        localhead -> nexthighest = gethighest(localhead -> nextlink);
        return maxnode(localhead -> nexthighest, localhead);
    }
}

void Insert (int x){
    if(head == NULL)
    {
       newnode = new node;
       newnode -> data = x;
       newnode -> nextlink = NULL;
       newnode -> nexthighest = NULL;
       temp = newnode;
        head = newnode;
      
    }
    else
    {
        newnode = new node;
        newnode -> data = x;
        newnode -> nextlink = NULL;
        newnode -> nexthighest = NULL;
        temp -> nextlink = newnode;
        temp = newnode;
    }
}

void printhighest()
{
    node * temp2 = head;
    while(temp2!= NULL)
    {
        cout << temp2->data << "and it's next value is";
        
        if (temp2->nexthighest != NULL)
            cout << temp2->nexthighest->data << endl;
        else
            cout << "NULL"<<endl;
        
        temp2 = temp2 -> nextlink;
    }
    
}
void PrintList()
{
    node * temp2 = head;
   while(temp2!= NULL)
   {
       cout << temp2 -> data;
       temp2 = temp2 -> nextlink;
       cout << endl;
   }
       
}

int main(int argc, const char * argv[]) {
    head = NULL; //Initially creating an empty list
    Insert (4);
    Insert (8);
    Insert (1);
    Insert (12);
    Insert (5);
    Insert (2);
    
    PrintList();
    
    gethighest(head);
    printhighest();
    
    }