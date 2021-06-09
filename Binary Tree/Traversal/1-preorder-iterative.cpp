void preorder(Node* root)
{   
    if(root==NULL)
        return;
    stack<Node*> st;
    st.push(root);
  
    while(!st.empty())
    {
        Node* curr = st.top();
        st.pop();
        
        cout<<curr->data<<" ";
        
        if(curr->right!=NULL)
        {
            st.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            st.push(curr->left);
        }
    }
}   
