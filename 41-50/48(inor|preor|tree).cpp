unordered_map<int, int> mp;
    int index = 0;
    
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int l, int r){
        if(l > r){
            return nullptr;
        }
        
        int idx = mp[preorder[index]];
        
        TreeNode* node = new TreeNode(preorder[index++]);
        
        node->left = solve(preorder, inorder, l, idx-1);
        node->right = solve(preorder, inorder, idx+1, r);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0){
            return NULL;
        }
        
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        
        int idx = mp[preorder[index]];
        
        TreeNode* root = new TreeNode(preorder[index++]);
        
        root->left = solve(preorder, inorder, 0,idx-1);
        root->right = solve(preorder, inorder, idx+1, n-1);
        
        return root;
    }