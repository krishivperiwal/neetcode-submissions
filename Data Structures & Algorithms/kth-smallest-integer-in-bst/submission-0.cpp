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
    int kthSmallest(TreeNode* root, int k) {
        int pre = 0;
        int pos = -1;
        while(pos != k){
            pos = 1 + count(root->left) + pre;
            if(pos > k)root = root->left;
            else if(pos < k){
                pre = pos;
                root = root->right;
            }
        }
        return root->val;
    }

    int count(TreeNode* node){
        if(!node)return 0;

        int left = node->left?count(node->left):0;
        int right = node->right?count(node->right):0;

        return 1 + left + right;
    }
};
