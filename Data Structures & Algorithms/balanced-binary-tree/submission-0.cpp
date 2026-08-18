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
    bool isBalanced(TreeNode* root) {
        return !(depth(root) == -1);
    }
    int depth(TreeNode* node){
        if(!node)return 0;

        int left = node->left?depth(node->left):0;
        int right = node->right?depth(node->right):0;

        if(left == -1 || right == -1 || abs(right-left) > 1)return -1;

        return 1 + max(right,left);
    }
};
