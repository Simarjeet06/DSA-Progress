class Router {
public: 
    int maxSize=0;
    queue<string> q;
    unordered_map<string,vector<int>> packetInfo;
    unordered_map<int,vector<int>> destinationInfo;
//     queue<tuple<int,int,int>> q;
//     unordered_map<string,bool> mpp;
//     unordered_map<int,vector<int>> packetCnt;
    Router(int memoryLimit) {
        maxSize=memoryLimit;
    }
    string encodeKey(int s,int d,int t){
        return to_string(s)+"*"+to_string(d)+"*"+to_string(t);
    }
    bool addPacket(int source, int destination, int timestamp) {
//         string key=encodeKey(source,destination,timestamp);
//         if(mpp.find(key)!=mpp.end()) return false;
//         while(q.size()>=maxSize){
//             auto p=q.front();
//             q.pop();
//             int s=get<0>(p);
//             int d=get<1>(p);
//             int t=get<2>(p);
//             string oldKey=encodeKey(s,d,t);
//             mpp.erase(oldKey);
//             auto& vec=packetCnt[d];
//             auto it=lower_bound(vec.begin(),vec.end(),t);
//             if(it!=vec.end() && *it==t) vec.erase(it);
//         }
//         mpp[key]=true;
//         q.push({source,destination,timestamp});
//         auto& vec=packetCnt[destination];
//         auto it=lower_bound(vec.begin(),vec.end(),timestamp);
//         vec.insert(it,timestamp);
//         return true;
string key=encodeKey(source,destination,timestamp);
if(packetInfo.find(key)!=packetInfo.end()) return false;
while(q.size()>=maxSize){
forwardPacket();
}
q.push(key);
packetInfo[key]={source,destination,timestamp};
destinationInfo[destination].push_back(timestamp);
return true;
  }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
//          auto p=q.front();
//             q.pop();
//             int s=get<0>(p);
//             int d=get<1>(p);
//             int t=get<2>(p);
//             string oldKey=encodeKey(s,d,t);
//             mpp.erase(oldKey); 
//             auto& vec=packetCnt[d];
//             auto it=lower_bound(vec.begin(),vec.end(),t);
//             if(it!=vec.end() && *it==t) vec.erase(it);
//             return {s,d,t};
string key=q.front();
q.pop();
 auto& vec=packetInfo[key];
 int s=vec[0];
  int des=vec[1];
  int time=vec[2];
  packetInfo.erase(key);
  auto& v=destinationInfo[des];
  v.erase(v.begin());
  return {s,des,time};
    }
    
    int getCount(int destination, int startTime, int endTime) {
//         auto& vec=packetCnt[destination];
//         int ind1=lower_bound(vec.begin(),vec.end(),startTime)-vec.begin();
//         int ind2=upper_bound(vec.begin(),vec.end(),endTime)-vec.begin()-1;
//         return max(0,ind2-ind1+1);
 auto& vec=destinationInfo[destination];
  int ind1=lower_bound(vec.begin(),vec.end(),startTime)-vec.begin();
int ind2=upper_bound(vec.begin(),vec.end(),endTime)-vec.begin();
return max(0,ind2-ind1);
    }
};

// /**
//  * Your Router object will be instantiated and called as such:
//  * Router* obj = new Router(memoryLimit);
//  * bool param_1 = obj->addPacket(source,destination,timestamp);
//  * vector<int> param_2 = obj->forwardPacket();
//  * int param_3 = obj->getCount(destination,startTime,endTime);
//  */