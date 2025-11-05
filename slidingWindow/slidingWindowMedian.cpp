class MedianFinder{
    //maxheap->stores left side
    priority_queue<int> s;
    //minheap->stores right side
    priority_queue<int,vector<int>,greater<int>> l;
    unordered_map<int,int> toRemove;
    int k;
    int smallSize=0,largeSize=0;
    void lazyDeleteS(priority_queue<int>& pq){
        while(!pq.empty() && toRemove[pq.top()]){
            toRemove[pq.top()]--;
            pq.pop();
        }
    }
    void lazyDeleteL(priority_queue<int,vector<int>,greater<int>>& pq){
         while(!pq.empty() && toRemove[pq.top()]){
            toRemove[pq.top()]--;
            pq.pop();
        }
    }
    void balance(int d){
        if(d>1){
            l.push(s.top());
            s.pop();
            smallSize--;
            largeSize++;
        }
        if(d<0){
            s.push(l.top());
            l.pop();
            smallSize++;
            largeSize--;
        }
        lazyDeleteS(s);
        lazyDeleteL(l);
    }
    public:
    MedianFinder(int k){
        this->k=k;
        while(!s.empty()) s.pop();
        while(!l.empty()) l.pop();
        toRemove.clear();
        smallSize=largeSize=0;
    }
    void add(int x){
        if(s.empty() || x<=s.top()){
         s.push(x);
         smallSize++;
        }
        else{
         l.push(x);
         largeSize++;
        }
        balance(smallSize-largeSize);
}
void remove(int x){
    toRemove[x]++;
    if(!s.empty() && x<=s.top()) smallSize--;
    else largeSize--;
    balance(smallSize-largeSize);
}
double findMedian(){
    lazyDeleteS(s);
    lazyDeleteL(l);
    if(k & 1) return (double) (s.top());
    else return ((double)s.top()+(double)l.top())/2.0;
}
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // multiset<int> mp1,mp2;
        // int n=nums.size();
        // int i=0;
        // vector<double> ans;
        // for(int j=0;j<n;j++){
        //     if(mp1.empty() || *mp1.rbegin()>=nums[j]){
        //         mp1.insert(nums[j]);
        //     }
        //     else{
        //         mp2.insert(nums[j]);
        //     }
        //     while(!mp2.empty() && mp2.size()>mp1.size()){
        //         auto it=mp2.begin();
        //         mp1.insert(*it);
        //         mp2.erase(it);
        //     }
        //     while(!mp1.empty() && mp1.size()>mp2.size()+1){
        //         auto it=prev(mp1.end());
        //         mp2.insert(*it);
        //         mp1.erase(it);
        //     }
        //    if(j>=k-1){
        //       if(mp1.size()==mp2.size()){
        //         double sum=((double)*mp1.rbegin())+((double)*mp2.begin());
        //         sum/=2.0;
        //         ans.push_back(sum);
        //       }
        //       else{
        //         double sum=(double)*mp1.rbegin();
        //         ans.push_back(sum);
        //       }
        //      auto it=mp1.find(nums[i]);
        //      if(it!=mp1.end()) mp1.erase(it);
        //     else  mp2.erase(mp2.find(nums[i]));
        //     while(!mp2.empty() && mp2.size()>mp1.size()){
        //         auto it=mp2.begin();
        //         mp1.insert(*it);
        //         mp2.erase(it);
        //     }
        //     while(!mp1.empty() && mp1.size()>mp2.size()+1){
        //         auto it=prev(mp1.end());
        //         mp2.insert(*it);
        //         mp1.erase(it);
        //     }
        //       i++;

        //    }
        // }
        // return ans;
        MedianFinder mf(k);
        vector<double> ans;
        for(int i=0;i<nums.size();i++){
            mf.add(nums[i]);
            if(i>=k-1){
                ans.push_back(mf.findMedian());
                mf.remove(nums[i-k+1]);
            }
        }
        return ans;

    }
};