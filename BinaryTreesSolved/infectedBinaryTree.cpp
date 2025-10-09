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
//     unordered_map<int,vector<int>> adj;
//     void buildGraph(TreeNode* root){
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//            TreeNode* node=q.front();
//            q.pop();
//            if(node->left){
//             q.push(node->left);
//             adj[node->val].push_back(node->left->val);
//             adj[node->left->val].push_back(node->val)
// ;           }
//             if(node->right){
//             q.push(node->right);
//             adj[node->val].push_back(node->right->val);
//             adj[node->right->val].push_back(->val);
// ;           }
//             }
//         }
    int result=0;
    int dfs(TreeNode* root,int start){
        if(!root) return 0;
        int lh=dfs(root->left,start);
        int rh=dfs(root->right,start);
        if(lh<0 || rh<0){
            result=max(result,abs(lh)+abs(rh));
            return min(lh,rh)-1;
        }
        if(root->val==start){
            int maxi=max(lh,rh);
            result=max(result,maxi);
            return -1;
        }
        return 1+max(lh,rh);
    }
    int amountOfTime(TreeNode* root, int start) {
    //   buildGraph(root);
    //   queue<pair<int,int>> qq;
    //   int maxDist=0;
    //   qq.push({start,0});
    //   unordered_set<int> vis;
    //   vis.insert(start);
    //   while(!qq.empty()){
    //     auto [node,dist]=qq.front();
    //     maxDist=max(maxDist,dist);
    //     qq.pop();
    //     for(int adjNode:adj[node]){
    //       if(!vis.count(adjNode)){
    //         vis.insert(adjNode);
    //         qq.push({adjNode,dist+1});
    //       }
    //     }
    //   }
    //   return maxDist;
    dfs(root,start);
    return result;
     
    }
};
