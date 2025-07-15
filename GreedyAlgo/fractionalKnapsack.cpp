#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<pair<double,int>> profit;
        for(int i=0;i<n;i++){
            double pt=(double)val[i]/wt[i];
            profit.push_back({pt,i});
            
        }
        sort(profit.begin(),profit.end(),[](auto a,auto b){
            return a.first>b.first;
        });
        double res=0;
        int i=0;
        while(capacity>0 && i<n){
            auto el=profit[i++];
            double pt=el.first;
            int ind=el.second;
            int v=val[ind];
            int w=wt[ind];
            if(w<=capacity){
                capacity-=w;
                res+=(v);
            }
            else{
                 res+=(pt*capacity);
                capacity=0;
            }
        }
    return res;
    }
};

