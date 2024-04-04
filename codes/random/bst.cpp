#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;

void INSERT(int val)
{
    node *temp = new node();

    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        root = temp;
    else{
        node *curr_node = root;
        node *prev_node = root;
        while (curr_node != NULL){
            if (curr_node->data > temp->data){
                prev_node = curr_node;
                curr_node = curr_node->left;
            }
            else{
                prev_node = curr_node;
                curr_node = curr_node->right;
            }
        }
        if (prev_node->data > temp->data)
            prev_node->left = temp;
        else
            prev_node->right = temp;
    }
}

void DELETE(int val)
{
    node *curr_node = root;
    node *prev_node = root;
    while (curr_node != NULL){
        if (curr_node->data == val)
            break;
        prev_node = curr_node;
        if (curr_node->data < val)
            curr_node = curr_node->right;
        else
            curr_node = curr_node->left;
    }
    //leaf node
    if (curr_node->left == NULL && curr_node->right == NULL){
        if (prev_node->right == curr_node)
            prev_node->right = NULL;
        else
            prev_node->left = NULL;
    }
    //one child
    else if (curr_node->left == NULL || curr_node->right == NULL){
        node *child;
        if (curr_node->right == NULL)
            child = curr_node->left;
        else
            child = curr_node->right;
        if(prev_node->right == curr_node)
            prev_node->right = child;
        else
          prev_node->left = child;
    }
    //two child
    else{
        node *temp=curr_node;
        prev_node = curr_node;
        curr_node = curr_node->right;
        while(curr_node->left != NULL){
            prev_node = curr_node;
            curr_node = curr_node->left;
        }
        temp->data = curr_node->data;
        if(prev_node->left == curr_node)
            prev_node->left = curr_node->right;
        else
            prev_node->right = curr_node->right;

    }
}

void pre_order(node *temp)
{
    if (temp != NULL){
        cout << temp->data << "\t";
        pre_order(temp->left);
        pre_order(temp->right);
    }
}

void post_order(node *temp)
{
    if (temp != NULL){
        post_order(temp->left);
        post_order(temp->right);
        cout << temp->data << "\t";
    }
}

void in_order(node *temp)
{
    if (temp != NULL){
        in_order(temp->left);
        cout << temp->data << "\t";
        in_order(temp->right);
    }
}

int main(){
    INSERT(100);
    INSERT(50);
    INSERT(200);
    INSERT(150);
    INSERT(300);
    INSERT(250);
    INSERT(270);
    INSERT(320);

    cout<<"in"<<endl;
    in_order(root);
    DELETE(300);
    cout<<endl;
    in_order(root);
}
