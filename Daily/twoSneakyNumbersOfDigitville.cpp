class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        // vector<int> temp(n+1,0);
        // vector<int> res;
        // for(int el:nums){
        //     temp[el]++;
        //     if(temp[el]==2) res.push_back(el);
        // }
        // return res;
        int size=n-2;
        int xr=0;
        for(int num:nums) xr^=num;
        for(int i=0;i<size;i++) xr^=i;
        //rightmost set bit
        int diff=xr & -xr;
        int a=0,b=0;
        for(int num:nums){
            if((diff & num)==0) a^=num;
            else b^=num;
        }
        for(int i=0;i<size;i++){
            if((diff & i)==0) a^=i;
            else b^=i;
        }
        return {a,b};
    }
};