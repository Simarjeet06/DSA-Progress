#include<string>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        // int st=s.size();
        // string str="aeiouAEIOU";
        // string temp;
        // for(int i=0;i<st;i++){
        //     if(str.find(s[i])!=string::npos){
        //         //vowels
        //         temp.push_back(s[i]);

        //     }
        // }
        // sort(begin(temp),end(temp));
        // int ind=0;
        // for(int i=0;i<st;i++){
        //     if(str.find(s[i])!=string::npos){
        //        s[i]=temp[ind++];
        //      }
        //      else continue;
        // }
        // return s;
        //Approach -2 (count sort)
        int n=s.size();
        string str="AEIOUaeiou";
        map<char,int> freq;
        for(int i=0;i<n;i++){
             if(str.find(s[i])!=string::npos){
                freq[s[i]]++;
             }
        }
        int j=0;
        for(int i=0;i<n;i++){
           if(str.find(s[i])!=string::npos){
              while(freq.find(str[j])==freq.end()) j++;
              s[i]=str[j];
              freq[str[j]]--;
              if(freq[str[j]]==0) freq.erase(str[j]);
           }
           else continue;
        }
        return s;
    }
};