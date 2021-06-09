void inorder(Node* root)
{
    if(root == NULL)
        return;
    
    Node* curr = root;
    stack<Node*> st;
  
    while(curr!=NULL || !st.empty())
    {
         while(curr != NULL)
         {
            st.push(curr);
            curr = curr->left;
         }
        
        curr = st.top();
        st.pop();
        cout<<curr->data;
        
        curr = curr->right;
    }
}
