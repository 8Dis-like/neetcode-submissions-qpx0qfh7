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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true;
        if((p&&!q)||(!p&&q))return false;
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        return (left&&right&&(p->val==q->val));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)return true;
        if(!root)return false;
        bool self=isSameTree(root,subRoot);
        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);
        return self||left||right;
    }
};
