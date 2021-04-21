#include<bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int locked_descendends;
    bool isLocked;

    TreeNode(int val, TreeNode* parent){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->parent = parent;
        this->locked_descendends = 0;
        this->isLocked = false;
    }
};


class LockableTree{
public:

    TreeNode* root;

    LockableTree(TreeNode* root){
        this->root = root;
    }

    //see if the current node is lockable or unlockable or not by traversing its ancestors and seeing is locked_descendends attribute.
    bool isLockable(TreeNode* node){
        if(node == NULL){
            return false;
        }

        if(node->locked_descendends > 0){
            return false;
        }

        TreeNode* curr = node->parent;

        while(curr){
            if(curr->isLocked){
                return false;
            }
            curr = curr->parent;
        } 

        return true;
    }

    bool isLocked(TreeNode* node){
        return node->isLocked;
    }

    bool lock(TreeNode* node){
        if(node == NULL){
            return false;
        }

        if(!isLockable(node)){
            return false;
        }

        node->isLocked = true;

        TreeNode* curr = node->parent;

        while(curr){

            curr->locked_descendends++;
            curr = curr->parent;
        }

        return true;
    }

    bool unlock(TreeNode* node){
        if(node == NULL){
            return false;
        }

        if(!isLockable(node)){
            return false;
        }

        node->isLocked = false;

        TreeNode* curr = node->parent;

        while(curr){
            curr->locked_descendends--;
            curr = curr->parent;
        }

        return true;
    }

};