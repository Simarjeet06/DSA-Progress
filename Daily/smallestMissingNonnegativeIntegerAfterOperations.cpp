class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        unordered_map<int,int> freq;
       for(int& num:nums){
        int mod=((num%value)+value)%value;
        freq[mod]++;
       }
      int MEX=0;
      while(freq[MEX%value]>0){
        freq[MEX%value]--;
        MEX++;
      }
      return MEX;
    }
};