#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
   
    vector<int> powersArr(int n){
        vector<int> arr;
        int i=0;
        while(n>0){
            if((n&1)==1){
                arr.push_back(pow(2,i));
            }
            i++;
            n>>=1;
        }
        return arr;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // string binaryVal=decimalToBinaryBitwise(n);
        // int num=stoi(binaryVal);
        vector<int> powers=powersArr(n);
        vector<int> ans;
        int mod=1e9+7;
        for(auto v:queries){
            int el1=v[0];
            int el2=v[1];
            long long  prod=1;
            for(int i=el1;i<=el2;i++){
                 int val=(powers[i]%mod);
                 prod=(prod*val)%mod;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};