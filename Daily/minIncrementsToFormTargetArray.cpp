class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int operations=target[0];
        int n=target.size();
        for(int i=1;i<n;i++){
            if(target[i]>target[i-1]){
                //break can't use the previous operations so we need to add more operations equal to the difference in heights.
                operations+=(target[i]-target[i-1]);
            }
        }
        return operations;
    }
};