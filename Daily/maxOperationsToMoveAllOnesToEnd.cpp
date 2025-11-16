class Solution {
public:
    int maxOperations(string s) {
        int total=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
            }
            else{
                if(i>0 && s[i-1]=='1' ) total+=cnt;
            }
        }
        return total;
    }
};