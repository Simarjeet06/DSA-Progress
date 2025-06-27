
//  * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution {
public:
    // bool solve(TreeNode* root,vector<TreeNode*>& ans,int n){
    //     if(root==NULL) return false;
    //     ans.push_back(root);
    //     if(root->val==n) return true;
    //     if(solve(root->left,ans,n) || solve(root->right,ans,n)) return true;
    //     ans.pop_back();
    //     return false;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL) return root;
        // vector<TreeNode*> ans1;
        // vector<TreeNode*> ans2;
        // solve(root,ans1,p->val);
        // solve(root,ans2,q->val);
        // int n1=ans1.size();
        // int n2=ans2.size();
        // TreeNode* ans;
        // for(int i=0;i<n1;i++){
        //    for(int j=0;j<n2;j++){
        //     if(ans1[i]->val==ans2[j]->val){
        //         ans=ans1[i];
        //         break;
        //     }
        //    }
        // }
        // return ans;
        if(root==nullptr || root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        return left?left:right;
    }
};