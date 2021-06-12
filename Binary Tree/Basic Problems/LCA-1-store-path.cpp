bool preorder(TreeNode* root, vector<TreeNode*>& path, TreeNode* p)
{
    if(root == NULL)
        return false;
    if(root==p)
    {
        path.push_back(p);
        return true;
    }
    path.push_back(root);
    if(preorder(root->left, path, p))
        return true;
    if(preorder(root->right, path, p))
        return true;
    path.pop_back();
    return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    vector<TreeNode*> p1, p2;
    preorder(root, p1, p);
    preorder(root, p2, q);
    int i;
    for(i=0; i<p1.size()&&i<p2.size(); i++)
    {
        if(p1[i]->val!=p2[i]->val)
            break;
    }
    return p1[i-1];
}
