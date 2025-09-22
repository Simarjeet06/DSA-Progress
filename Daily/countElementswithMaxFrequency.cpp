class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> temp(101,0);
        int maxSz=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            temp[nums[i]]++;
            if(temp[nums[i]]>maxSz){
                maxSz=temp[nums[i]];
                cnt=1;
            }
            else if(temp[nums[i]]==maxSz) cnt++;
        }
        return cnt*maxSz;
    }
};