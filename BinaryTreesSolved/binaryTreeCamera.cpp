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
    int finalCnt=0;
    //0->needs camera
    //1->has camera
    //2->gets covered by camera
    int checkCamera(TreeNode* root){
        //leaf node needs a camera
        if(!root) return 2;
       if(!root->left && !root->right) return 0;
       int left=checkCamera(root->left);
       int right=checkCamera(root->right);
      if(left==0 || right==0 ){
        //i need a camera for my children
        finalCnt++;
        return 1;
      }
      else if(left==1 || right==1) return 2;
       //both of the nodes are covered but they are not helping me so i need one
       return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        int val=checkCamera(root);
        if(val==0) finalCnt++;
        return finalCnt;
    }
};