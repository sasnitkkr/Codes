vector<int> levelOrder(Node* node)
{
  //Your code here
    queue<Node*> q;
    q.push(node);
    vector<int> output;
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        output.push_back(curr->data);

        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
    return output;
}
