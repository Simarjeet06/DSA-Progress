class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int maxi=0;
        while(l<r){
            int area=(r-l)*min(height[l],height[r]);
            maxi=max(maxi,area);
            if(height[l]<height[r]){
               l++;
            }
            else{
              r--;
            }
        }
        return maxi;
    }
};