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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> inorder;
        while(curr){
            if(curr->left==nullptr){
            //if there is no left we print our current node and move to the right
             inorder.push_back(curr->val);
             curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                   prev->right=nullptr;
                   inorder.push_back(curr->val);
                   curr=curr->right;
                }
            }
        }
        return inorder;
    }
};