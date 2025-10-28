class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void f(vector<int>& nums,int i,vector<int>& temp){
        ans.push_back(temp);
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            f(nums,j+1,temp);
            temp.pop_back();
        }
    }
    void backtrack(vector<int>& nums,int i,vector<int>& subset,vector<vector<int>>& res){
        if(i==n){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        //pick
        backtrack(nums,i+1,subset,res);
        subset.pop_back();
        //skipping duplicates
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        //skip
        backtrack(nums,i+1,subset,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        // // vector<int> temp;
        sort(begin(nums),end(nums));
        // // f(nums,0,temp);
        // // return ans;
        vector<vector<int>> res;
        // vector<int> subset;
        // backtrack(nums,0,subset,res);
        // return res;
        set<vector<int>> st;
        int num=1<<n;
        for(int mask=0;mask<num;mask++){
            vector<int> v;
            for(int j=0;j<n;j++){
                if(mask & 1<<j){
                    v.push_back(nums[j]);
                }
            }
            st.insert(v);
        }
        for(auto it=st.begin();it!=st.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};