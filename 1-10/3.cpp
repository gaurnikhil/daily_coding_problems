	string serialize(TreeNode* root) {  //serialize the root
        if(root == NULL){
            return ".";   //a '.' character represents a null node
        }
        
        string serialized = "";
        
        serialized += to_string(root->val);  //add the current node to the serialized string then traverser its left and right children respectively
        
        serialized += "," + serialize(root->left);     //add the saperator after each node
        serialized += "," + serialize(root->right);
        
        return serialized;
    }
    
    TreeNode* deserializeUtil( vector<string> &serialized, int &i){
        
        if(i == serialized.size()){   //if the whole array is exhausted
            return NULL;
        }
        
        string val = serialized[i++];
        
          if(val == "."){   //if we encounter the '.' character => a null pointer
            return NULL;
        }
        //build the tree using the serialized array
        TreeNode* node = new TreeNode(stoi(val));
        
        node->left = deserializeUtil(serialized, i);
        node->right = deserializeUtil(serialized, i);
        
        return node;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> serialized;  //store the node array
        
        stringstream ss(data);  //use a string stream to saperate the node
        string node;
        
        while(getline(ss,node,',')){
            cout<<node<<" ";
            serialized.push_back(node);
        }
        
        int i=0;
        return deserializeUtil(serialized, i);
    }
