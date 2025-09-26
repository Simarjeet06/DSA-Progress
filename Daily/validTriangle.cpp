class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        //approach-2 
        sort(nums.begin(),nums.end());
    //     int cnt=0;
    //     for(int i=0;i<n-2;i++){
    //        for(int j=i+1;j<n-1;j++){
    //         int sum=nums[i]+nums[j];
    //         int ind=lower_bound(nums.begin()+j+1,nums.end(),sum)-nums.begin()-1;
    //         cnt+=(ind-j);
    //        }
    //     }
    //    return cnt;
    int cnt=0;
    for(int k=n-1;k>=2;k--){
        int i=0;
        int j=k-1;
        while(i<j){
          if(nums[i]+nums[j]>nums[k]){
            cnt+=(j-i);
            j--;
          }
          else i++;
        }
    }
     return cnt;
    }
};