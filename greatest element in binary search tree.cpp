//finding element in bst is easy because right most element is greatest followed by a null.

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node *right;
};

node* create(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->left=newnode->right = NULL;
    return newnode;
}

/*node* insertt(node* &root,int data)
{
    if(root==NULL)
        return create(data);
    else
        if(data<=root->data)
    {
        root->left = insertt(root->left,data);
    }
    else
        root->right = insertt(root->right,data);
    return root;
}
*/

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
    if(root!=NULL)
    {
        display(root->left);
        cout<<root->data<<endl ;
        display(root->right);
    }
}
int maxvalue(node* root)
{
    if(root==NULL)
    {
        cout<<"Tree is empty"<<endl;
        return -1;
    }
    else if(root->right==NULL)
    {
        return root->data;
    }
    return maxvalue(root->right);
}

int main()
{
    node* root = NULL;
    int data,n;
    cout<<"Enter number of elements u want"<<endl;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>data,insert(root,data);
    }
    cout<<"Tree element is "<<endl;
    display(root);
    cout<<"Max value is "<<maxvalue(root)<<endl;
    return 0;
}
