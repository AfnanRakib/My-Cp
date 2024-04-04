#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *root=NULL;
node *tail=NULL;

void insert_last(int val){
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    if(root==NULL){
        root=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void delete_last(){
    tail=tail->prev;
    tail->next=NULL;
}

void insert_first(int val){
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;

    if(root==NULL){
        root=temp;
        tail=temp;
    }
    else{
        root->prev=temp;
        temp->next=root;
        root=temp;
    }
}

void delete_first(){
    root=root->next;
    root->prev=NULL;
}

void insert_anywhere(int pos, int val)
{
    node *temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    node *curr_node = root;

    if (pos == 1){
        insert_first(val);
        return;
    }
    for(int i=1; i<pos; i++){
        curr_node = curr_node->next;
    }
    temp->prev = curr_node->prev;
    temp->next = curr_node;
    curr_node->prev->next = temp;
    curr_node->prev = temp;
}

void delete_anywhere(int val)
{
    if (root->data == val)
    {
        delete_first();
        return;
    }

    node *curr_node = root;

    while (curr_node != NULL)
    {
        if (curr_node->next->data == val){
            curr_node->next=curr_node->next->next;
            curr_node->next->prev=curr_node;
            return;
        }
        curr_node = curr_node->next;
    }
}

void printing(){
    cout<<"Forward"<<endl;
    node *curr_node=root;
    while(curr_node!=NULL){
        cout<<curr_node->data<<endl;
        curr_node=curr_node->next;
    }
    cout<<"Backward"<<endl;
    node *curr_node2=tail;
    while(curr_node2!=NULL){
        cout<<curr_node2->data<<endl;
        curr_node2=curr_node2->prev;
    }
}

void size_of_the_list(){
    node *curr_node=tail;
    int cnt=0;
    while(curr_node!=NULL){
        cnt++;
        curr_node=curr_node->prev;
    }
    cout<<cnt<<endl;
}

void searching(int val){
    node *curr_node=tail;
    while(curr_node!=NULL){
        if(curr_node->data==val){
            cout<<"found"<<endl;
            return;
        }
        curr_node=curr_node->prev;
    }
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
