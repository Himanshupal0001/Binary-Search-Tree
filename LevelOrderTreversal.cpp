#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
 node* insert(node* &root,int data)
 {
     if(root == NULL){
        root = new node();
        root->data = data;
        root->left=root->right = NULL;
     }
     else{
        if(data<root->data)
            root->left = insert(root->left,data);
        else
            root->right = insert(root->right,data);
     }
    return root;
 }

 void LevelOrder(node*root)
 {
     if(root == NULL) return;
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* current = q.front();
            q.pop();
            cout<<current->data;
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL) q.push(current->right);

        }

 }

int main()
{
    node* root = NULL;
    int n,data;
    cout<<"Enter size : "<<endl;
    cin>>n;
    cout<<"Enter data : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>data,insert(root,data);
    }

    cout<<"level order treversal is :"<<endl;
    LevelOrder(root);
    return 0;

}
