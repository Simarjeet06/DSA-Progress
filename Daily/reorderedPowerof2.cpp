#include<algorithm>
#include<cmath>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    // void f(vector<vector<int>>& ans,vector<int>& digits,int index,int num){
    //     if(index==num){
    //         ans.push_back(digits);
    //         return;
    //     }
    //     for(int i=index;i<num;i++){
    //        swap(digits[i],digits[index]);
    //        f(ans,digits,index+1,num);
    //        swap(digits[i],digits[index]);
    //     }
    // }
    string sortedStrings(int n){
        string str=to_string(n);
        sort(str.begin(),str.end());
        return str;
    }
    vector<int> getCount(int n){
        vector<int> v(10,0);
        while(n){
            v[n%10]++;
            n/=10;
        }
        return v;
    }
    int getNum(int n){
        int num=0;
        while(n>0){
            int val=(n%10);
            num+=(pow(10,val));
            n/=10;
        }
        return num;
    }
    bool reorderedPowerOf2(int n) {
        // vector<int> digits;
        // vector<vector<int>> ans;
        // while(n>0){
        //     digits.push_back(n%10);
        //     n/=10;
        // }
        // int num=digits.size();
        // f(ans,digits,0,num);
        // for(auto v1:ans){
        //     int el=0;
        //     if(v1[0]==0) continue;
        //     for(auto ind:v1){
        //         el=(el*10)+ind;
        //     }
        //     if(el>0 && ((el & (el-1))==0)) return true;
        // }
        // return false;


        // Approach -2
        // string target=sortedStrings(n);
        // unordered_set<string> st;
        // for(int i=0;i<=30;i++){
        //     int num=1<<i;
        //      st.insert(sortedStrings(num));
        // }
        // return (st.find(target)!=st.end());


        //Approach-3
        // vector<int> t=getCount(n);
        // for(int p=0;p<=29;p++){
        //    if(t==getCount(1<<p)) return true;
        // }
        // return false;

        //Approach-4
        int temp=getNum(n);
        for(int p=0;p<=29;p++){
            if(temp==getNum(1<<p)) return true;
        }
        return false;
    }
    
};