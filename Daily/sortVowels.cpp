#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string sortVowels(string s) {
        int st=s.size();
        string str="aeiouAEIOU";
        string temp;
        for(int i=0;i<st;i++){
            if(str.find(s[i])!=string::npos){
                //vowels
                temp.push_back(s[i]);

            }
        }
        sort(begin(temp),end(temp));
        int ind=0;
        for(int i=0;i<st;i++){
            if(str.find(s[i])!=string::npos){
               s[i]=temp[ind++];
             }
             else continue;
        }
        return s;
    }
};