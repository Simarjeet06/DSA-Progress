#include<bits/stdc++.h>
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
         map<int,int> mpp;
         queue<pair<Node*,pair<int,int>>> q;
         q.push({root,{0,0}});
         vector<int> ans;
         while(!q.empty()){
             auto p=q.front();
             q.pop();
             Node* node=p.first;
             int x=p.second.first;
             int y=p.second.second;
             if(mpp.find(x)==mpp.end()) mpp[x]={node->data};
             if(node->left) q.push({node->left,{x-1,y+1}});
             if(node->right) q.push({node->right,{x+1,y+1}});
         }
         for (auto p:mpp){
             ans.push_back(p.second);
         }
         return ans;
    }
    
};