/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // void serial(TreeNode* root,string& res){
    //     if(!root){
    //         res.append("#,");
    //         return;
    //     }
    //     else{
    //     res+=to_string(root->val)+",";
    //     }
    //     serial(root->left,res);
    //     serial(root->right,res);
    // }
    string serialisationLevel(TreeNode* root){
        string data="";
        if(!root) return data;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node){
                data+=(to_string(node->val)+",");
                q.push(node->left);
                q.push(node->right);
            }
            else{
                data.append("#,");
            }
        }
        return data;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // string res="";
        // serial(root,res);
        // if(!res.empty()) res.pop_back();
        // cout<<res<<endl;
        // return res;
        string res= serialisationLevel(root);
        cout<<res<<endl;
        return res;
    }
    TreeNode* buildTree(vector<string>& vec,int& idx,int n){
        if(idx>=n) return nullptr;
        if(vec[idx]=="#") return nullptr;
        string s=vec[idx];
        TreeNode* root=new TreeNode(stoi(s));
        idx++;
        root->left=buildTree(vec,idx,n);
        idx++;
        root->right=buildTree(vec,idx,n);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* levelDeserialisation(string data){
        if(data.empty()) return nullptr;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(!getline(ss,str,',')) break;
            if(str!="#"){
               node->left=new TreeNode(stoi(str));
               q.push(node->left);
            }
             if(!getline(ss,str,',')) break;
             if(str!="#"){
               node->right=new TreeNode(stoi(str));
               q.push(node->right);
            }
        }
        return root;
    }
    TreeNode* deserialize(string data) {
    //     if(data.size()==1 && data.compare("#")==0) return nullptr;
    //     int idx=0;
    //     istringstream iss(data); 
    //     char delimiter=',';
    //     vector<string> vec;
    //     string token;
    //     while(getline(iss,token,delimiter)){
    //         vec.push_back(token);
    //     }
    //     return buildTree(vec,idx,vec.size());
    return levelDeserialisation(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));