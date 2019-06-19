#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node* left;
node* right;};

node* create(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}
void insert(node* &root,int data)
{
    if(root == NULL)
        root = create(data);
    else
        if(data<=root->data)
        insert(root->left,data);
        else
            insert(root->right,data);
}

void display(node* root)
{
    if(root!= NULL)
    {
        display(root->left);
        cout<<root->data<<endl;
        display(root->right);
    }
}

int hight(node* root)
{
    if(root==NULL)
        return -1;
    else
    {
        int left_tree = hight(root->left);
        int right_tree = hight(root->right);
        return max(left_tree,right_tree)+1;
    }

}

int main()
{
    cout<<"+++++++Same code for depth of binary search tree+++++++++"<<endl;
    node* root = NULL;
    int data,n;
    cout<<"Number of elements in a tree"<<endl;
    cin>>n;
    cout<<"Input elements of the tree"<<endl;
    for(int i=0;i<n;i++){
    cin>>data,insert(root,data);
    }
    cout<<"Tree is :"<<endl;
    display(root);

    cout<<"hight of the bst :"<<hight(root)<<endl;
    return 0;
}
