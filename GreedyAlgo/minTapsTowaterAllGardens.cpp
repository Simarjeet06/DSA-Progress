class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // vector<vector<int>> limits(n+1);
        // for(int i=0;i<=n;i++){
        //     int x=i-ranges[i];
        //     int y=i+ranges[i];
        //     limits[i].push_back(max(x,0));
        //     limits[i].push_back(min(y,n));
        // }
        // sort(begin(limits),end(limits));
        // int currEnd=0;
        // int tapCnt=0;
        // int idx=0;
        // while(currEnd<n && idx<=n){
        //    int potential=currEnd;
        //    if(limits[idx][0]>currEnd) return -1;
        //    while(idx<=n && limits[idx][0]<=currEnd){
        //     //potential
        //     potential=max(potential,limits[idx][1]);
        //     idx++;
        //    }
        //    if(potential==currEnd) return -1;
        //    currEnd=potential;
        //    tapCnt+=1;
        // }
        // return (currEnd>=n)?tapCnt:-1;
        vector<int> startEnd(n+1);
        //each index defines the start of garden while the value at the index is the max watered range in the rightmost part of the garden;
        for(int i=0;i<ranges.size();i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            startEnd[start]=max(startEnd[start],end);
        }
        int maxEnd=0,currEnd=0,taps=0;
        for(int i=0;i<=n;i++){
            //if i am able to reach unwatered garden then it is not possible to water the entire garden
            if(i>maxEnd) return -1;
            //i have reached the max capacity of one tap now i need to open a new one and update my currEnd
            if(i>currEnd){
                currEnd=maxEnd;
                taps++;
            }
            maxEnd=max(maxEnd,startEnd[i]);
        }
        return taps;
    }
};