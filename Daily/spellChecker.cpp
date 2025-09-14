#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        //hashset for exact match
        unordered_set<string> words(wordlist.begin(),wordlist.end());
        unordered_map<string,string> capitaliseCheck;
        unordered_map<string,string> vowelCheck;
        for(string word:wordlist){
             string lowered;
             string vowelTransform;
            for(char ch:word){
               char l=tolower(ch);
                lowered+=l;
               if(l=='a' || l=='e' || l=='i' || l=='o' ||l=='u'){
                  vowelTransform+='#';
               }
               else vowelTransform+=l;
            }
            if(!capitaliseCheck.count(lowered)) capitaliseCheck[lowered]=word;
            if(!vowelCheck.count(vowelTransform)) vowelCheck[vowelTransform]=word;
        }
        for(string query:queries){
            if(words.find(query)!=words.end()){
                ans.push_back(query);
                continue;
            }
            string lowered,vowelTransform;
            for(char ch:query){
                char l=tolower(ch);
                 lowered+=l;
               if(l=='a' || l=='e' || l=='i' || l=='o' ||l=='u'){
                  vowelTransform+='#';
               }
               else vowelTransform+=l;
            }
               if(capitaliseCheck.count(lowered)) ans.push_back(capitaliseCheck[lowered]);
               else if(vowelCheck.count(vowelTransform)) ans.push_back(vowelCheck[vowelTransform]);
               else ans.push_back("");
        }  
        
       return ans;
     
    }
};