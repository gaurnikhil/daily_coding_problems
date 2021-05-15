int solveExpressionTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    string val = root->val;

    if(val == "*" || val == "+" || val == "-" || val == "/"){

        int a = 0;
        int b = 0;

        if(root->left){
            a = solveExpressionTree(root->left);
        }
        if(root->right){
            b = solveExpressionTree(root->right);
        }

        if(val == "*"){
            return a * b;
        }
        else if(val == "+"){
            return a + b;
        }
        else if(val == "-"){
            return a - b;
        }
        else{
            return a / b;
        }
    }
    
    return stoi(val);

}