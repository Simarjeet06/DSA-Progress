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
    unordered_map<string,int> mpp;
    string dfs(TreeNode* root,vector<TreeNode*>& ans){
        if(!root) return "#";
        string s=to_string(root->val)+","+dfs(root->left,ans)+","+dfs(root->right,ans);
        if(mpp[s]==1){
            ans.push_back(root);
        }
        mpp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
         dfs(root,ans);
        return ans;
    }
};