#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *root=NULL;

void insert_last(int val){
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    if(root==NULL)
        root=temp;
    else{
        node *curr_node=root;
        while(curr_node!=NULL){
            if(curr_node->next==NULL){
                curr_node->next = temp;
                break;
            }
            curr_node=curr_node->next;
        }
    }
}

void insert_first(int val){
    node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    if(root==NULL)
        root=temp;
    else{
        temp->next=root;
        root=temp;
    }
}

void insert_anywhere(int pos, int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    node *curr_node = root;

//jodi age theke inputted er same position e arekta dite chaile tokhon
//ager ta same rekhe er porei new ta dite nicher code gula lagbe

//ar ager ta niche namai new ta oi position ei rakhte chaile code gula skip

//jemon 3rd e 6 ase ami abar 3rd e 5 rakhle output e age 6 then 5 asbe nicher code use korle
// ar use na korle age 5 then 6 asbe

//nicher code bolte int cnt theke inseret_last er if condition porjonto

/*
    int cnt = 0;
    while(curr_node!=NULL){
        curr_node = curr_node->next;
        cnt++;
    }
    curr_node = root;
    if(cnt == pos){
        insert_last(val);
        return;
    }
*/

    if (pos == 1){
        insert_first(val);
        return;
    }

    for(int i = 1; i<pos-1; i++){
        curr_node = curr_node->next;
        //root holo 1st index so 1st iteration por curr node 2
        //2nd iteration por curr node 3, erkm hocche karon curr node e poreer ta assign kortesi
        //tai jodi 4th position e insert kori curr node 3 te rekhe kaj korte hobe then 3rd er seshe temp
        //temp er seshe 4th ta lagai dite hoi so loop 2 bar chalano lagbe
        //so 4th e dite i=1 theke 2 porjonto cholbe taile curr node 3 hobe;
    }
    temp->next = curr_node->next;
    curr_node->next = temp;
}

void delete_first(){
    root = root->next;
}

void delete_last(){
    node *curr_node=root;
    while(curr_node!=NULL){
        if(curr_node->next->next==NULL){
            curr_node->next = NULL;
            break;
        }
        curr_node=curr_node->next;
    }
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
            return;
        }
        curr_node = curr_node->next;
    }
}

void last_node(){
    node *curr_node=root;
    while(curr_node!=NULL){
        if(curr_node->next==NULL){
            break;
        }
        curr_node=curr_node->next;
    }
    cout<<curr_node->data<<endl;
}

void prev_node(int val)
{
    node *curr_node=root;
    while(curr_node!=NULL){
        if(curr_node->next->data==val){
            break;
        }
        curr_node=curr_node->next;
    }
    cout<<curr_node->data <<endl;
}

void print(){
    node *curr_node=root;
    while(curr_node!=NULL){
        cout<<curr_node->data<<endl;
        curr_node=curr_node->next;
    }
}

void cntprint(int x){
    node *curr_node=root;
    int cnt=0;
    while(curr_node!=NULL){
        if(curr_node->data==x)
            cnt++;
        curr_node=curr_node->next;
    }
    cout<<cnt<<endl;
}

void rvprint(node *curr_node){
    if(curr_node->next!=NULL)
        rvprint(curr_node->next);
    cout<<curr_node->data<<endl;

}

void nprint(int n){
    node *curr_node=root;
    int i=1;
    while(i<n){
        curr_node=curr_node->next;
        i++;
    }
    cout<<curr_node->data<<endl;
}

void searching(int val){
    node *curr_node=root;
    while(curr_node!=NULL){
        if(curr_node->data==val){
            cout<<"found"<<endl;
            return;
        }
        curr_node=curr_node->next;
    }
    cout<<"not found"<<endl;
}

void size_of_the_list(){
    node *curr_node=root;
    int cnt=0;
    while(curr_node!=NULL){
        cnt++;
        curr_node=curr_node->next;
    }
    cout<<cnt<<endl;
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

    cout<<"inserted values-----------"<<endl;
    print();
    cout<<"size of the list----------------"<<endl;
    size_of_the_list();
    cout<<"search 5----------------"<<endl;
    searching(5);
    cout<<"3rd value-------------"<<endl;
    nprint(3);
    cout<<"last node-----------"<<endl;
    last_node();
    cout<<"prev node of 4-----------"<<endl;
    prev_node(4);
    cout<<"reverse print-----------"<<endl;
    rvprint(root);
    cout<<"count of 3-----------"<<endl;
    cntprint(3);


    delete_anywhere(1);
    delete_anywhere(4);
    delete_anywhere(7);
    delete_last(); //will delete 2
    delete_first(); //will delete 10

    cout<<"after deleting 1,4,7,2,10-----------"<<endl;
    print();

    return 0;
}
