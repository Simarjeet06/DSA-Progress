#include<vector>
#include<string>
using namespace std;
int n,m;
bool possible(string str){
        vector<int> freq(26,0);
        for(char& ch:str){
             if(freq[ch-'a']>=1) return false;
             freq[ch-'a']++;
        }
        return true;
    }
    int calculate(vector<int>& vec,int j,int res){
        if(j>=m) return __builtin_popcount(res);
        int skip,pick=0;
        skip=calculate(vec,j+1,res);
        if(!(res & vec[j])){
            pick=calculate(vec,j+1,res|vec[j]);
        }
        return max(pick,skip);
    }
    int maxLength(vector<string>& arr) {
        n=arr.size();
        // string str="";
        // return solve(arr,str,0);
        vector<int> vec;
        for(int i=0;i<n;i++){
             string str=arr[i];
             int res=0;
            if(!possible(str)) continue;
             for(char ch:str){
                int val=ch-'a';
                res|=(1<<val);
             }
             vec.push_back(res);
         }
         m=vec.size();
         return calculate(vec,0,0);

    }
