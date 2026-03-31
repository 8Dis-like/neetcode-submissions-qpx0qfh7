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
        int maxv=-1001;
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        bool left=isValidBST(root->left);
        if(root->val>maxv)maxv=root->val;
        else return false;
        bool right=isValidBST(root->right);
        return left&&right; 
    }
};
