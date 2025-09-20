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
 *//**
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
    void swapFunc(ListNode* node,int startpos,int secondpos){
        ListNode* temp1=nullptr;
        ListNode* temp2=nullptr;
        int cnt=1;
         while(node){
           if(temp1 && temp2) break;
           if(cnt==startpos){
              temp1=node;
           }
           if(cnt==secondpos){
            temp2=node;
           }
           cnt++;
           node=node->next;
         }
         if(temp1 && temp2) swap(temp1->val,temp2->val);
    }
    int findLen(ListNode* node){
        int cnt=0;
        while(node){
            cnt++;
            node=node->next;
        }
       return cnt;
    }
    void solve(ListNode* node,int k){
        ListNode* first=node;
        ListNode* second=node;
        int cnt=1;
        while(node->next){
            if(cnt<k){
               first=first->next;
            }
            if(cnt>=k){
                second=second->next;
            }
            cnt++;
            node=node->next;
        }
        swap(first->val,second->val);
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node=head;
        // int n=findLen(head);
        // int startpos=k;
        // int secondpos=n-k+1;
        // swapFunc(head,startpos,secondpos);
        solve(node,k);
        return head;
    }
};