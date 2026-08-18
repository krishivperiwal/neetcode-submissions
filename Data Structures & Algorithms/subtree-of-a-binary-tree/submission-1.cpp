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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)return true;
        else if(!root || !subRoot)return false;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *temp= q.front();
            q.pop();

            if(isSame(subRoot,temp))return true;
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }

        return false;
    }

    bool isSame(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)return true;
        else if(!root1 || !root2)return false;

        if(root1->val != root2->val)return false;
        bool left = isSame(root1->left,root2->left);
        bool right = isSame(root1->right,root2->right);

        return left&&right;
    }
};
