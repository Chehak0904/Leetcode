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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            if(prev==NULL && st.find(curr->val)!=st.end()){
                curr=curr->next;
                head=curr;
            }
            else if(st.find(curr->val)!=st.end()){
                curr=curr->next;
                prev->next=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
        
    }
};