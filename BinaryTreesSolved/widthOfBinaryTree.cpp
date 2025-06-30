#include<queue>
#include<algorithm>
using namespace std;
//  * Definition for a binary tree node.
 struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        if(root==NULL) return 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            int first,last;
            unsigned long long mmin=q.front().second;
            for(int i=0;i<s;i++){
                auto p=q.front();
                q.pop();
                TreeNode* node=p.first;
                unsigned long long num=p.second-mmin;
                if(i==0) first=num;
                if(i==s-1) last=num;
                if(node->left) q.push({node->left,(2*num+1)});
                if(node->right) q.push({node->right,(2*num+2)});
                ans=max(ans, 1LL*(last-first+1));
            }
        }
        return ans;
        /*if(root==NULL)
        return 0;
       
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int res=0;
        while(q.empty()==false)
        {
           int start=q.front().second;
           int end=q.back().second;
           res=max(res,end-start+1);
           int size=q.size();
           for(int i=0;i<size;i++)
           {
               auto x=q.front();
               int index=x.second-end;
               q.pop();

               if(x.first->left!=NULL)
               q.push({x.first->left,2*index+1});
            
               if(x.first->right!=NULL)
               q.push({x.first->right,2*index+2});     
           }      
        }
        return res;   
        */
    }
};