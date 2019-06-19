#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node* right;
};

node* create(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left=temp->right = NULL;
    return temp;
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
    if(root!=NULL){
        display(root->left);
        cout<<root->data<<endl;  //inorder
        display(root->right);
    }
}

bool search(node* root,int data)
{
    if(root == NULL)
        return false;
    if(root->data=data)
        return true;
    if(data<=root->data)
        return search(root->left,data);
     else
        return search(root->right,data);
}
int main()
{
    node *root = NULL;
    int n,num;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    cout<<"Enter elements of tree"<<endl;
    for(int i=0;i<n;i++)
        cin>>num,insert(root,num);
    cout<<"***********tree**************"<<endl;
    display(root);
    char c;
    cout<<"U want to search element :Y/N"<<endl;
    cin>>c;
    if(c=='y' || c=='Y')
    {
        cout<<"Enter the number u want to search"<<endl;
        cin>>num;
        if(search(root,num)== true)
            cout<<"found"<<endl;
        else
            cout<<"Not found"<<endl;
    }
    else if(c=='n' || c=='N')
        cout<<"Alright then"<<endl;
    else
        cout<<"Wrong input"<<endl;
    return 0;
}
