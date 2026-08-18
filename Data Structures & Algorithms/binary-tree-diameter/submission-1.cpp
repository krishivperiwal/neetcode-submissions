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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int dep = dp(root);
        return ans;
    }
    int dp(TreeNode* node){
        if(!node)return 0;

        int left = node->left?dp(node->left):0;
        int right = node->right?dp(node->right):0;

        ans = max(ans,left + right);
        return 1 + max(left,right);
    }
};
