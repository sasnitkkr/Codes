// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    stack<int> st;
    vector<int> output;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        
        st.push(curr->data);
        
        if(curr->right!=NULL)
            q.push(curr->right);
        if(curr->left!=NULL)
            q.push(curr->left);
        
    }
    while(!st.empty())
    {
        output.push_back(st.top());
        st.pop();
    }
    return output;
}
