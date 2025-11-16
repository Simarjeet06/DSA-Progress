class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> cumCount(n,0);
        cumCount[0]=(s[0]=='1')?1:0;
        for(int i=1;i<n;i++){
            cumCount[i]=cumCount[i-1]+((s[i]=='1')?1:0);
        }
        int result=0;
        for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int oneCnt=cumCount[j]-((i>=1)?(cumCount[i-1]):0);
            int zeroCnt=(j-i+1)-oneCnt;
            if((zeroCnt*zeroCnt)>(oneCnt)){
                int need=(zeroCnt*zeroCnt)-oneCnt;
                j+=(need-1);
            }
            else if((zeroCnt*zeroCnt)==oneCnt) result++;
            else{
                result+=1;
                int k=((sqrt(oneCnt))-zeroCnt);
                int next=j+k;
                if(next>=n){
                    result+=(n-j-1);
                    break;
                }
                else{
                    result+=k;
                }
                j=next;

        }
        }
        }
        return result;
    }
};