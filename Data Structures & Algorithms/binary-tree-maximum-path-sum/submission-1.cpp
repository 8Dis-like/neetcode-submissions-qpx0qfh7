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
    int traversal(TreeNode* root){
        if(!root)return 0;
        int left=traversal(root->left);
        int right=traversal(root->right);
        maxv=max(maxv,max(left+root->val+right,root->val));
        return max(max(left,right),0)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxv=max(maxv,traversal(root));
        return maxv;
    }
};
