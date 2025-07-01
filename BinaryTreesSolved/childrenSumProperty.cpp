//Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};


class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int  helper(Node* root){
        if(root==nullptr) return 0;
        else if((root->left==nullptr && root->right==nullptr)) return root->data;
        int left=helper(root->left);
        int right=helper(root->right);
        if(left== -1 || right==-1) return -1;
        return root->data==left+right?root->data:-1;
        
    }
    int isSumProperty(Node *root) {
        
        // Add your code here
        if(root==nullptr) return 1;
        return helper(root)!=-1;
    }
};