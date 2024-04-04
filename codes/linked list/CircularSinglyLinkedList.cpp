/*
    Md. Rakib Hasan
    20210204027
*/


#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *last=NULL;

void insert_last(int val)
{
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;

    if(last==NULL){
        last=temp;
        last->next=last;
    }
    else{
        temp->next=last->next;
        last->next=temp;
        last=temp;
    }
}

void insert_first(int val)
{
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;

    if(last==NULL){
        last=temp;
        last->next=last;
    }
    else{
        temp->next=last->next;
        last->next=temp;
    }
}

void insert_anywhere(int pos, int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;

    node *curr_node = last->next;

    if (pos == 1){
        insert_first(val);
        return;
    }

    for(int i = 1; i<pos-1; i++){
        curr_node = curr_node->next;
    }
    temp->next = curr_node->next;
    curr_node->next = temp;
}

void delete_first()
{
    if(last==NULL)
        return;
    else if(last->next==last)
        last=NULL;
    else
        last->next=last->next->next;
}

void delete_last()
{
    if(last==NULL)
        return;
    else if(last->next==last)
        last=NULL;
    else{
        node *curr_node=last->next;
        while(curr_node->next!=last){
            curr_node=curr_node->next;
        }
        curr_node->next=last->next;
        last=curr_node;
    }
}

void delete_anywhere(int val)
{
    if(last==NULL)
        return;

    if (last->next->data == val)
    {
        delete_first();
        return;
    }

    node *curr_node = last->next;

    while (curr_node != last)
    {
        if (curr_node->next->data == val){
            curr_node->next=curr_node->next->next;
            return;
        }
        curr_node = curr_node->next;
    }
}

void printing()
{
    if(last==NULL)
        return;
    node *curr_node=last->next;
    do{
        cout<<curr_node->data<<endl;
        curr_node=curr_node->next;
    }while(curr_node!=last->next);
}

void size_of_the_list()
{
    int cnt=0;
    if(last==NULL)
        return;
    node *curr_node=last->next;
    do{
        cnt++;
        curr_node=curr_node->next;
    }while(curr_node!=last->next);
    cout<<cnt<<endl;
}

void searching(int val)
{
    if(last==NULL)
        return;
    node *curr_node=last->next;
    do{
        if(curr_node->data==val){
            cout<<"found"<<endl;
            return;
        }
        curr_node=curr_node->next;
    }while(curr_node!=last->next);
    cout<<"not found"<<endl;
}

int main(){

    insert_first(4);
    insert_first(3);
    insert_first(2);

    insert_last(8);
    insert_last(9);
    insert_last(10);

    insert_anywhere(1,1);
    insert_anywhere(5,5);
    insert_anywhere(6,7);
    insert_anywhere(6,6);

    cout<<"printing inserted values--------"<<endl;
    printing();

    cout<<"size of the list----------------"<<endl;
    size_of_the_list();

    cout<<"searching value 5----------------"<<endl;
    searching(5);

    delete_anywhere(1);
    delete_anywhere(4);
    delete_anywhere(7);
    delete_last(); //will delete 2
    delete_first(); //will delete 10

    cout<<"printing after deleting-----------"<<endl;
    printing();

    return 0;
}
