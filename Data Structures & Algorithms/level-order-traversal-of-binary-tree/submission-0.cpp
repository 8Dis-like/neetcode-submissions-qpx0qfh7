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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return vector<vector<int>>{};
        queue<TreeNode*>q;
        vector<vector<int>>res;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>vec;
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();q.pop();
                if(!cur)continue;
                q.push(cur->left);
                q.push(cur->right);
                vec.push_back(cur->val);
            }if(vec.size()>0)res.push_back(vec);
        }return res;
    }
};
