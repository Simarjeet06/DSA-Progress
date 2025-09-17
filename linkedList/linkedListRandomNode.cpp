/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//Approach 1: store all the nodes in an array and use rand() function as it returns numbers with equal probability and to get the number from array we need its index so we do rand()%n this will always return numbers from 0 to n-1 so it makes sure a valid index is received;
    // vector<int> arr;
    // int n;
    ListNode* head;
    Solution(ListNode* head) {
        // ListNode* node=head;
        // while(node){
        //     arr.push_back(node->val);
        //     node=node->next;
        // }
        // n=arr.size();
       
        this->head=head;
    }
    
    int getRandom() {
        // int getIndex=rand()%n;
        // return arr[getIndex];
        int res=0;
        int cnt=0;
        ListNode* temp=head;
        while(temp){
             cnt++;
            if(cnt==1){
                res=temp->val;
            }
            else if(rand()%cnt==0){
                res=temp->val;
            }
            temp=temp->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */