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
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return deep(root);
    }

    int deep(TreeNode* node){
        if(!node)return 0;

        int left = node->left ? deep(node->left):0;
        int right = node->right ? deep(node->right):0;

        return 1 + max(left,right);
    }
};
