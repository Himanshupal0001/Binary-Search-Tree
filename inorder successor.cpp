#include<iostream>
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
node* Find(node*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}
node* InorderSuccessor(node* root,int data)
{

    node* curr = Find(root,data);
    if(curr==NULL) return NULL;
    if(curr->right!=NULL)
    {
        node* temp = curr->right;
        while(temp->left!=NULL)
            temp=temp->left;
        return temp;
    }
    else
    {
        node* Successor = NULL;
        node* ancestor = root;
        while(ancestor!=curr)
        {
            if(curr->data > ancestor->data)
            {
                Successor = ancestor;
                ancestor = ancestor->right;
            }
            if(curr->data < ancestor->data){
                Successor = ancestor;
                ancestor = ancestor->left;}
        }
            return Successor;
    }
}

int main()
{
    node* root=NULL;
    int n,data;
    cout<<"Enter number of elements u want"<<endl;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>data,insert(root,data);
    }
    cout<<"Tree is"<<endl;
    display(root);

    int x;
    cout<<"Enter element u want to find successor"<<endl;
    cin>>x;
    node* temp = InorderSuccessor(root,x);
    cout<<"Successor is "<<temp->data<<endl;
    return 0;

}
