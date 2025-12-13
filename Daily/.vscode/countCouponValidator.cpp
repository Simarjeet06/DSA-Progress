#include<bits/stdc++.h>
#include<cctype>
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
       unordered_set<string> st={"electronics","grocery","pharmacy","restaurant"};
        vector<pair<string,string>> temp;
       for(int i=0;i<code.size();i++){
        if(!isActive[i]) continue;
        if(code[i].empty()) continue;
        bool isValid=true;
        for(char c:code[i]){
            if(!isalnum(c) && c!='_'){
                isValid=false;
                break;
            }
        }
        if(!isValid) continue;
        if(st.find(businessLine[i])==st.end()) continue;
        temp.push_back({businessLine[i],code[i]});
       }
       sort(begin(temp),end(temp));
        vector<string> ans;
        for(auto e:temp){
            ans.push_back(e.second);
        }
       return ans;
    }
};