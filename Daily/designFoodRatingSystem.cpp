#include<string>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
class FoodRatings {
public:
//{rating,{cuisine,food}}

    struct ComparisonFunc{
      bool operator()(const pair<int,string>& a,const pair<int,string>& b)const{
          if(a.first!=b.first){
            return a.first>b.first;
          }
          return a.second<b.second;
      }
    };
    int n;
    unordered_map<string,set<pair<int,string>,ComparisonFunc>> cuisineMap;
    unordered_map<string,pair<string,int>> foodItem;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n=foods.size();
        for(int i=0;i<n;i++){
         foodItem[foods[i]]={cuisines[i],ratings[i]};
         cuisineMap[cuisines[i]].insert({ratings[i],foods[i]});
        } 
    }
    
    void changeRating(string food, int newRating) {
         auto [cuisine,rating]=foodItem[food];
        if(cuisineMap.find(cuisine)!=cuisineMap.end()){
            cuisineMap[cuisine].erase({rating,food});
           }
       cuisineMap[cuisine].insert({newRating,food});
       foodItem[food].second=newRating;     
    }
    
    string highestRated(string cuisine) {
      return cuisineMap[cuisine].begin()->second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */