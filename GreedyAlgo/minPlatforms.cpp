#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
    vector<pair<int,int>> v;
    int n=arr.size();
    for(int i=0;i<n;i++){
        v.push_back({arr[i],dep[i]});
    }
    sort(v.begin(),v.end());
    int maxi=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto el:v){
        int arrival=el.first;
        int departure=el.second;
        while(!pq.empty() && pq.top()<arrival){
            pq.pop();
        }
        pq.push(departure);
        maxi=max(maxi,(int) pq.size());
    }
    return maxi;
    
    }
};
