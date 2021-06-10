void includeLeft(Node* root,vector<int>& op)
    {
        if(root==NULL)
            return;
        if(root->left != NULL)
        {
            op.push_back(root->data);
            includeLeft(root->left,op);
        }
        else if(root->right != NULL)
        {
            op.push_back(root->data);
            includeLeft(root->right, op);
        }
        // if left null and right null => leaf node => do nothing
    }
    void includeLeaves(Node* root,vector<int>& op)
    {
        if(root==NULL)
            return;
        includeLeaves(root->left,op);
        if(root->left==NULL && root->right==NULL)
        {
            op.push_back(root->data);
        }
        includeLeaves(root->right,op);
    }
    void includeRight(Node* root,vector<int>& op)
    {
        if(root==NULL)
            return;
        
        if(root->right!=NULL)
        {  
            includeRight(root->right, op);
            op.push_back(root->data);
        }
        else if(root->left!=NULL)
        {
            includeRight(root->left, op);
            op.push_back(root->data);   
        }
            
        // else b sides null => leaf node => do nothing 
        
    }
    void printHelp(Node* root, vector<int>& op)
    {
        // root
        op.push_back(root->data);
        // include left part except root and leaf node
        includeLeft(root->left, op);
        // include all leaves
        includeLeaves(root,op);
        // include right part except root and leaf node
        includeRight(root->right, op);
    }
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> op;
        if(root == NULL)
            return op;
        if(root->left == NULL && root->right ==NULL)
        {
            op.push_back(root->data);
            return op;
        }
        printHelp(root, op);
        return op;
    }
