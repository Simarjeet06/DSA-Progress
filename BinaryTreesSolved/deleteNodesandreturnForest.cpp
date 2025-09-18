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
    vector<TreeNode*> vec;
    TreeNode* helper(TreeNode* root,set<int>& st){
        if(!root) return root;
        root->left= helper(root->left,st);
        root->right= helper(root->right,st);
        if(st.find(root->val)!=st.end()){
            if(root->left) vec.push_back(root->left);
            if(root->right) vec.push_back(root->right);
            st.erase(root->val);
            return nullptr;
        }
        return root;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st(begin(to_delete),end(to_delete));
        root=helper(root,st);
        if(root) vec.push_back(root);
        return vec;
    }
};