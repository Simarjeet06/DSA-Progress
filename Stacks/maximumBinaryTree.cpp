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
    int n;
    // TreeNode* dfs(vector<int>& nums,int l,int r){
    //     if(l>r) return nullptr;
    //     int maxel=INT_MIN,maxi=-1;
    //     for(int i=l;i<=r;i++){
    //        if(maxel<nums[i]){
    //         maxel=nums[i];
    //         maxi=i;
    //        }
    //     }
    //     TreeNode* root=new TreeNode(maxel);
    //     root->left=dfs(nums,l,maxi-1);
    //     root->right=dfs(nums,maxi+1,r);
    //     return root;
    // }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        n=nums.size();
        // return dfs(nums,0,n-1);/
        stack<TreeNode*> st;
        for(int i=0;i<n;i++){
            TreeNode* curr=new TreeNode(nums[i]);
            while(!st.empty() && st.top()->val<nums[i]){
                curr->left=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.top()->right=curr;
            }
            st.push(curr);
        }
        while(st.size()!=1) st.pop();
        return st.top();
    }
};