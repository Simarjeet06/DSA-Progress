#include <string>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int cnt=1;
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) cnt++;
            else cnt=1;
            if(cnt<3) ans+=s[i];
        }
        return ans;
    }
};