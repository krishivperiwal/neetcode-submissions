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
    bool isValidBST(TreeNode* root) {
        return valid(root,INT_MAX,INT_MIN);
    }

    bool valid(TreeNode* node,int maxi,int mini){
        if(!node)return true;

        if(node->val > mini && node->val < maxi){
            return valid(node->left,node->val,mini)&&valid(node->right,maxi,node->val);
        }else{
            return false;
        }

    }
};
