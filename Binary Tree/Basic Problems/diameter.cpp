int height(Node* root)
{
    if(root==NULL)
        return -1;
    if(root->left==NULL && root->right==NULL)
        return 0;

    return 1+max(height(root->left), height(root->right));
}
int diameter(Node* root){
  
    if(root==NULL)
        return 0;

    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int h = height(root->left)+1+height(root->right)+1+1;//dia is no of nodes
    return max(max(ld,rd),h);
}
