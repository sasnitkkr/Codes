Time :- O(n)
Space:- Rec Stack
int height(struct Node* node)
{
    // code here
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    int l = height(node->left);
    int r = height(node->right);
    return max(l,r) + 1;
}
