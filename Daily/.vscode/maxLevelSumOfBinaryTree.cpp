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
    vector<int> sum={INT_MIN};
    void dfs(TreeNode* root,int level){
        if(!root) return;
        if(sum.size()==level) sum.push_back(root->val);
        else sum[level]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        return max_element(begin(sum),end(sum))-begin(sum);
    }
};