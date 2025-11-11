class Solution {
public:
    int len;
    vector<vector<vector<int>>> t;
    // vector<pair<int,int>> vec;
    pair<int,int> cntZeros(string& str){
        int zero=0;
        for(char ch:str){
            if(ch=='0') zero++;
        }
        return {zero,(int)str.size()-zero};
    }
    // int helper(vector<string>& strs,int i,int m,int n){
    //     if(i==len) return 0;
    //     if(t[i][m][n]!=-1) return t[i][m][n];
    //     int skip=0,take=0;
    //      skip=helper(strs,i+1,m,n);
    //     auto [zeros,ones]=vec[i];
    //     if(m>=zeros && n>=ones){
    //          take=1+helper(strs,i+1,m-zeros,n-ones);
    //     }
    //     return t[i][m][n]=max(take,skip);
    // }
    int findMaxForm(vector<string>& strs, int m, int n) {
        len=strs.size();
        // vec.resize(len);
        // for(int i=0;i<len;i++){
        //     vec[i]=cntZeros(strs[i]);
        // }
        // t.resize(len+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        // return helper(strs,0,m,n);
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<len;i++){
            // vector<vector<int>> curr(m+1,vector<int>(n+1,0));
            auto [z,o]=cntZeros(strs[i]);
            for(int j=m;j>=z;j--){
                for(int k=n;k>=o;k--){
                    // int skip=nextt[j][k];
                    // int take=0;
                    // if(j>=vec[i].first && k>=vec[i].second){
                    //    take=1+nextt[j-vec[i].first][k-vec[i].second];
                    // }
                    dp[j][k]=max(dp[j][k],1+dp[j-z][k-o]);
                }
            }
            // nextt=curr;

        }
        return dp[m][n];

    }
};