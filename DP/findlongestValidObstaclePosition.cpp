#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> ans(n);
        vector<int> temp;
        for(int i=0;i<n;i++){
            int ind=upper_bound(temp.begin(),temp.end(),obstacles[i])-temp.begin();
            if(ind==temp.size()){
                temp.push_back(obstacles[i]);
            }
            else{
                temp[ind]=obstacles[i];
            }
            ans[i]=ind+1;
        }
        
        return ans;
    }
};