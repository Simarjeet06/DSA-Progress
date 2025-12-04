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
    int dfs(TreeNode* root,long long currSum,long long target,unordered_map<long long,int>& mpp){
        if(!root) return 0;
        currSum+=root->val;
        int cnt=0;
        if(mpp.find(currSum-target)!=mpp.end()){
            cnt+=mpp[currSum-target];
        }
        mpp[currSum]++;
        cnt+=dfs(root->left,currSum,target,mpp);
        cnt+=dfs(root->right,currSum,target,mpp);
        mpp[currSum]--;
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mpp;
        mpp[0]=1;
        return dfs(root,0,targetSum,mpp);
    }
};