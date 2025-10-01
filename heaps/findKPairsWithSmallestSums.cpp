class Solution {
public: 
// typedef pair<int,int> p;
//{sum,{i,j}}
// typedef pair<int,pair<int,int>> p;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    //  auto comp=[&](pair<int,int>& a,pair<int,int>& b){
    //    return (nums1[a.first]+nums2[a.second])>(nums1[b.first]+nums2[b.second]);
    //  };
    //     priority_queue<p,vector<p>,decltype(comp)> pq(comp);
    //     pq.push({0,0});
    //     set<pair<int,int>> vis;
    //     vis.insert({0,0});
    //     vector<vector<int>> ans;
    //     while(k--){
    //         auto [i,j]=pq.top();
    //         pq.pop();
    //         ans.push_back({nums1[i],nums2[j]});
    //         if( i+1<nums1.size() && vis.find({i+1,j})==vis.end()){
    //             pq.push({i+1,j});
    //             vis.insert({i+1,j});
    //         }
    //         if(j+1<nums2.size() && vis.find({i,j+1})==vis.end()){
    //             pq.push({i,j+1});
    //             vis.insert({i,j+1});
    //         }
    //     }
    //     return ans;


    //using brute force:- trying all possible pairs with eatly exit if no smaller sums possible; since we want smaller values we must be able to remove larger sums hence we use max-heap for this purpose;
    //   int m=nums1.size();
    //   int n=nums2.size();
    //   //max heap
    //   priority_queue<p,vector<p>> pq;
    //   for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         int sum=nums1[i]+nums2[j];
    //         if(pq.size()<k){
    //             pq.push({sum,{i,j}});
    //         }
    //         else if(pq.top().first>sum){
    //             pq.pop();
    //             pq.push({sum,{i,j}});
    //         }
    //         else{
    //             //pq is full and current sum is greater than sum at the top since arrays are sorted in non decreasing fashion sums are only going to increase in the rightward direction so we should break out of the loop;
    //             break;
    //         }
    //     }
    //   }
    //   vector<vector<int>> ans;
    //   while(!pq.empty()){
    //    auto [sum,p]=pq.top();
    //    pq.pop();
    //    ans.push_back({nums1[p.first],nums2[p.second]});
    //   }
    //    reverse(begin(ans),end(ans));
    //    return ans;
      typedef tuple<int,int,int> t;
      int m=nums1.size();
      int n=nums2.size();
      priority_queue<t,vector<t>,greater<t>> pq;
      vector<vector<int>> ans;
      set<pair<int,int>> vis;
      pq.push({nums1[0]+nums2[0],0,0});
      vis.insert({0,0});
      while(k-- && !pq.empty()){
          auto [sum,i,j]=pq.top();
          pq.pop();
          ans.push_back({nums1[i],nums2[j]});
          if(i+1<m && (vis.find({i+1,j})==vis.end())){
            pq.push({nums1[i+1]+nums2[j],i+1,j});
            vis.insert({i+1,j});
          }
          if(j+1<n && (vis.find({i,j+1})==vis.end())){
            pq.push({nums1[i]+nums2[j+1],i,j+1});
            vis.insert({i,j+1});
          }
      }
return ans;
    }
};