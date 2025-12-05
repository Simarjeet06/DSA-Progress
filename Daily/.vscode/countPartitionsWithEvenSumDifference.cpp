class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total=accumulate(begin(nums),end(nums),0);
        return ((total & 1) ==0)?nums.size()-1:0;
    }
};