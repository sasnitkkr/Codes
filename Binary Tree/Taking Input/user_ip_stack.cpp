#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
};

Node* buildBT()
{
    int rd;
    cout<<"Enter root data = ";
    cin>>rd;
    if(rd == -1)
        return NULL;
    queue<Node*> q;
    Node* root=(Node*)malloc(sizeof(Node));
    root->data = rd;
    root->left = root->right = NULL;
    q.push(root);
    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        cout<<"For the Node "<<cur->data<<"\n";
        int ld, rd;
        cout<<"Enter left child\n";
        cin>>ld;
        if(ld!=-1)
        {
            Node* lNode = (Node*)malloc(sizeof(Node));
            lNode->data = ld;
            lNode->left = lNode->right = NULL;
            cur->left = lNode;
            q.push(lNode);
        }
        cout<<"Enter right child\n";
        cin>>rd;
        if(rd!=-1)
        {
            Node* rNode = (Node*)malloc(sizeof(Node));
            rNode->data = rd;
            rNode->left = rNode->right = NULL;
            cur->right = rNode;
            q.push(rNode);
        }
    }
    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
    
int main()
{   
    Node* root = buildBT();
    inorder(root);
    return 0;
}   
