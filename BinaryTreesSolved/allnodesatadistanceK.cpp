 #include<queue>
 #include<vector>
 #include<map>
 using namespace std;
 
 struct TreeNode {
   int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution {
public:
    void markParents(TreeNode* root,map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();
            if(p->left){
                q.push(p->left);
                parent[p->left]=p;
            }
            if(p->right){
                q.push(p->right);
                parent[p->right]=p;
            }
    }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent;
        markParents(root,parent);
        map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int currLevel=0;
        while(!q.empty()){
            if(currLevel==k) break;
            int s=q.size();
            for(int i=0;i<s;i++){
             TreeNode* node=q.front();
             q.pop();
             if(node->left && !vis[node->left]){
                q.push(node->left);
                vis[node->left]=true;
             }
             if(node->right && !vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;
             }
             if(parent.count(node) && !vis[parent[node]]){
                q.push(parent[node]);
                vis[parent[node]]=true;
             }
            }
            currLevel++;
    }
    vector<int> res;
      while(!q.empty()){
        auto p=q.front();
        q.pop();
        res.push_back(p->val);
      }
      return res;
    }
};