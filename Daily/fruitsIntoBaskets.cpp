#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    //     int i=0;
    //     unordered_map<int,int> mpp;
    //     int n=fruits.size();
    //     int maxi=0;
    //    for(int j=0;j<n;j++){
    //      mpp[fruits[j]]=j;
    //     if(mpp.size()==3){
    //     int oldest=INT_MAX;
    //     int val=-1;
    //       for(auto [el,ind]:mpp){
    //         if(ind<oldest){
    //             oldest=ind;
    //             val=el;
    //         }
    //       }
    //         i=oldest+1;
    //         mpp.erase(val);
    //     }
    //       maxi=max(maxi,j-i+1);  
    //    }
    //   return maxi;
    int i=0;
    int j=0;
    int cnt=0;
    map<int,int> mpp;
    int n=fruits.size();
    while(j<n){
        mpp[fruits[j]]++;
        if(mpp.size()<=2){
            cnt=max(cnt,j-i+1);
        }
        else{
            mpp[fruits[i]]--;
            if(mpp[fruits[i]]==0){
                mpp.erase(fruits[i]);
            }
            i++;
        }
        j++;
    }
    return cnt;
    }
};