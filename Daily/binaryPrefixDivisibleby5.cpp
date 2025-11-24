#include<bits/stdc++.h>
#include<bitset>
#include<climits>
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> ans(n,false);
        int num=0;
        for(int i=0;i<n;i++){
            num=((num<<1)+nums[i])%5;
            ans[i]=(num==0);
        }
        return ans;
    }
};