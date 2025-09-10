#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    priority_queue<int> maxHeap;
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=piles[i];
            maxHeap.push(piles[i]);
        }
        while(k){
          int topEl=maxHeap.top();
          maxHeap.pop();
          int remove=(topEl/2);
          topEl-=remove;
          ans-=remove;
          maxHeap.push(topEl);
          k--;
        }
        return ans;
    }
};