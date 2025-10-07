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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(!prev->right){
                    //when building the connection for the first time this is the first time of meeting the root so before exploaring left and right push it into the result first and then explore its children.
                 prev->right=curr;
                 preorder.push_back(curr->val);
                 curr=curr->left;
                }
                else{
                    //since we have already explored the root and its left we now move to the right
                    prev->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};