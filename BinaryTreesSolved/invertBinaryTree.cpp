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
    TreeNode* invertTree(TreeNode* root) {
        // iterative 
//         queue<TreeNode*> q;
//         if(root==NULL) return root;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* p=q.front();
//             q.pop();
//             if(p->left) q.push(p->left);
//             if(p->right) q.push(p->right);
//             TreeNode* temp=p->left;
//             p->left=p->right;
//             p->right=temp;
//         }
//         return root;
//recursive:
if(root==NULL) return root;
TreeNode* left=invertTree(root->left);
TreeNode* right=invertTree(root->right);
root->left=right;
root->right=left;
return root;
       
    }

};