#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
class Twitter {
public:
   struct User{
    int id;
    vector<pair<int,int>> tweets;
    unordered_set<int> followees;
    User():id(-1){}
    User(int uid){
       id=uid;
    }
    void post(int tweetId,int& timer){
        tweets.push_back({timer++,tweetId});
    }
    void followUser(int followeeId){
        followees.insert(followeeId);
    }
     void unfollowUser(int followeeId){
        if(followees.find(followeeId)!=followees.end()) followees.erase(followeeId);
    }

   };
   unordered_map<int,User> users;
   int timer;
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(users.find(userId)==users.end()){
            User u=User(userId);
            users[userId]=u;
            // u.followUser(userId);
        }
        User& u=users[userId];
         u.post(tweetId,timer);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<pair<int,int>> pq;
        if(users.find(userId)==users.end()) return {};
        User& u=users[userId];
        for(auto [time,id]:u.tweets){
            pq.push({time,id});
        }
        for(auto it=u.followees.begin();it!=u.followees.end();it++){
            int followeeid=*it;
            if(users.find(followeeid) == users.end()) continue;
            User& v=users[followeeid];
            for(auto [time,id]:v.tweets){
                pq.push({time,id});
            }
        }
        int cnt=10;
        while(!pq.empty () && cnt>0){
            feed.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
         if(users.find(followerId)==users.end()){
            User u=User(followerId);
             users[followerId]=u;
            //   u.followUser(followerId);
        }
          if(users.find(followeeId)==users.end()){
            User v=User(followeeId);
             users[followeeId]=v;
            //   v.followUser(followeeId);
        }
        User& u=users[followerId];
         u.followUser(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
      User& u=users[followerId];
       u.unfollowUser(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */