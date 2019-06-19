//minimum element is found in left most node followed by an Null
#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node* left;
node*right;
};

 node* create(int data)
 {
     node* newnode = new node();
     newnode->data = data;
     newnode->left = newnode->right = NULL;
     return newnode;
 }

void insert(node* &root,int data)
{
    if(root == NULL)
        root = create(data);
    else if(root->data>data)
        insert(root->left,data);
    else insert(root->right,data);

}

 void display(node* root)
 {
     if(root!= NULL){
        display(root->left);
        cout<<root->data<<endl;
        display(root->right);}
 }

 int minvalue(node* root)
 {
     if(root == NULL){
        cout<<"Tree is empty"<<endl;
        return -1;}
    else if(root->left==NULL){
        return root->data;}
    return minvalue(root->left);
 }

 int main()
 {
     node* root = NULL;
     int n,data;
     cout<<"Enter number of elements u want"<<endl;
     cin>>n;
     cout<<"Enter element"<<endl;
     for(int i=0;i<n;i++)
     {
         cin>>data,insert(root,data);
     }
     cout<<"Display tree"<<endl;
     display(root);
      cout<<"Min value is "<<minvalue(root)<<endl;
    return 0;
 }
