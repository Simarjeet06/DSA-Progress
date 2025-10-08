class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
         for(int spell:spells){
            long long required=(spell+success-1)/spell;
            int idx=lower_bound(potions.begin(),potions.end(),required)-potions.begin();
            ans.push_back(m-idx);
         }
        return ans;
    }
};