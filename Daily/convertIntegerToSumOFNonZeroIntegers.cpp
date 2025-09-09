#include<vector>
using namespace std;
class Solution {
public:
    bool checkB(int b){
        while(b){
            int val=(b%10);
            if(val==0) return false;
            b/=10;
        }
        return true;
    }
    bool checkA(int a){
        while(a){
            int val=(a%10);
            if(val==0) return false;
            a/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        // int a=1;
        // vector<int> ans;
        // while(true){
        //     int b=n-a;
        //     if(checkB(b) && checkA(a)){
        //         ans.push_back(a);
        //         ans.push_back(b);
        //         break;
        //     }
        //     else a++;
        // }
        // return ans;
        //Approach-2
        int a=n;
        int b=0;
        int placeValue=1;
        while(n>1){
            int take=1;
             if((n%10)==1){
                take=2;
             }
             b+=take*placeValue;
             a-=take*placeValue;
             n=(n-take)/10;
             placeValue*=10;
        }
        return {a,b};
    }
};