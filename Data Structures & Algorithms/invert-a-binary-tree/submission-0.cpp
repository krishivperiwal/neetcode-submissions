/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        invert(root);
        return root;
    }

    void invert(TreeNode* node){
        if(!node->left && !node->right)return;

        if(!node->left){
            invert(node->right);
            node->left = node->right;
            node->right = NULL;
        }else if(!node->right){
            invert(node->left);
            node->right = node->left;
            node->left = NULL;
        }else{
            invert(node->left);
            invert(node->right);
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        return;
    }
};
