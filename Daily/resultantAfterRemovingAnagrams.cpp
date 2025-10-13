class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            string last=ans.back();
            string curr=words[i];
            sort(begin(last),end(last));
            sort(begin(curr),end(curr));
            if(curr!=last) ans.push_back(words[i]); 
        }
        return ans;
    }
};