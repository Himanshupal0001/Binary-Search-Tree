#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node* create(int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->left = newnode->right=NULL;
}

void insert(node* &root,int data)
{
    if(root == NULL)
        root = create(data);
    else
    {
        if(data<root->data)
            insert(root->left,data);
        else
            insert(root->right,data);
    }
}

void display(node* root)
{
    if(root!=NULL){
        display(root->left);
        cout<<root->data<<endl;
        display(root->right);
    }
}

node* Findmin(node* root)
{
    while(root->left!= NULL)
    {
        root=root->left;
    }
    return root;

}
node* Delete(node* root,int data)
{
    if(root == NULL)
        return root;
    else if(data<root->data)
        root->left = Delete(root->left,data);
    else if(data>root->data)
        root->right = Delete(root->right,data);
    else
        //CASE 1 : Root has no child
        if(root->left == NULL && root->right == NULL)
    {
        delete root;
        root = NULL;
    }
    //CASE 2 : Root has single child
    else if(root->left == NULL)
    {
        node* newnode = root;
        root = root->right;
        delete newnode;
    }
    else if(root->right == NULL)
    {

        node* newnode = root;
        root = root->left;
        delete newnode;
    }
    //CASE 3: 2 child
    else
    {
        node* newnode = Findmin(root->right);
        root->data = newnode->data;
        root->right = Delete(root->right,newnode->data);
    }
    return root;
}
int main()
{
    node* root = NULL;
    int n,data;
    cout<<"Enter the number of element in data"<<endl;
    cin>>n;
    cout<<"Enter element :\n";
    for(int i=0;i<n;i++)
    {
        cin>>data,insert(root,data);
    }
    cout<<"Display :"<<endl;
    display(root);

    cout<<"Enter the element u want to delete"<<endl;
    cin>>data;
    node* del = Delete(root,data);
    cout<<"Deletion is :"<<endl;
    display(root);
    return 0;
}
