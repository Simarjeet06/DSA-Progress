#include <vector>
using namespace std;
class Solution {
public:
//    void helper(vector<vector<int>>& ans,vector<int>& ds,vector<int>& nums,vector<bool>& taken,int n){
//     if(ds.size()==n){
//         ans.push_back(ds);
//         return;
//     }
//     for(int i=0;i<n;i++){
//         if(!taken[i]){
//             ds.push_back(nums[i]);
//             taken[i]=true;
//             helper(ans,ds,nums,taken,n);
//             taken[i]=false;
//             ds.pop_back();
//         }
//     }
//    }
   void f(vector<vector<int>>& ans,vector<int>& nums,int n,int index){
       if (index==n){
        ans.push_back(nums);
        return;
       }
       for(int i=index;i<n;i++){
        swap(nums[index],nums[i]); // inplace so no need of an extra data structure
        f(ans,nums,n,index+1);
        swap(nums[index],nums[i]);
       }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool> taken(n,false);
        vector<vector<int>> ans;
        vector<int> ds;
        // helper(ans,ds,nums,taken,n);
       f(ans,nums,n,0);
        return ans;
    }
};