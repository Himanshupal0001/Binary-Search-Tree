#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};

node* create(int data)
{
    node* newnode = new node();
    (*newnode).data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

/*node* insert(node* &root,int data)
{
    node* cur = root;
    if(root == NULL)
    {
        root = create(data);
    }
    else

        if(data<=root->data)
    {
        cur = insert(root->left,data);
        root->left = cur;
    }
    else
        cur = insert(root->right,data);
        root->right = cur;

    return root;
}
*/


void insert(node* &root,int data)
{
    if(root == NULL)
    {
        root = create(data);
    }
    else

        if(data<=root->data)
    {
     insert(root->left,data);

    }
    else
        insert(root->right,data);
}

void display(node *root)
{
    if(root!=NULL)
    {
        display(root->left);
        cout<<root->data<<endl;
        display(root->right);
    }
}

node* Lca(node* root,int v1,int v2)
{
    if(root == NULL)
        return NULL;
    if(root->data>v1 && root->data>v2)
    {
        return Lca(root->left,v1,v2);
    }
    if(root->data<v1 && root->data<v2)
    {
        return Lca(root->right,v1,v2);
    }
    return root;

}

int main()
{

    node *root = NULL;
    int n,data,v1,v2;
    cout<<"Enter number of elements of tree"<<endl;
    cin>>n;
    cout<<"Enter element of tree"<<endl;
    while(n-->0)
    {
        cin>>data,insert(root,data);
    }
    cout<<"Tree is "<<endl;
    display(root);
    cout<<"Enter two values of v1 and v2"<<endl;
    cin>>v1>>v2;
    node* t=Lca(root,v1,v2);
    cout<<"Lca of tree is :"<<t->data<<endl;
    return 0;
}
