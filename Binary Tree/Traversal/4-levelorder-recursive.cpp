// Time:- O(h^2)
// Space:- Recursion Stack- O(h) for height and getLevel

int height(Node* root)
{
    if(root == NULL)
        return -1;
    if(root->left==NULL && root->right==NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
void getLevel(Node* root, int level, vector<int>& output)
{
    if(root == NULL)
        return;
    if(level == 1)
    {
        output.push_back(root->data);
    }
    else
    {
        getLevel(root->left, level-1, output);
        getLevel(root->right, level-1, output);
    }
}
vector<int> levelOrder(Node* node)
{

  //Your code here
  vector<int> output;
  if(node==NULL) return output;
  int h = height(node);
  for(int level=1; level<=h+1; level++)
  {
       getLevel(node, level, output);  
  }
  return output;
}
