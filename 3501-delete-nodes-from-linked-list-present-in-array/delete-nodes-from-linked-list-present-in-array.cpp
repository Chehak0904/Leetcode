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
          unordered_set<int> st;
        for(int num:nums){
            st.insert(num);
        }
        while(head!=NULL && st.find(head->val)!=st.end()){
            head=head->next;
        }
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=NULL){
            ListNode* next=curr->next;
            if(st.find(curr->val)!=st.end()){
                prev->next=next;
                curr->next=NULL;
                curr=next;
            }
            else{
                prev=curr;
                curr=next;
            }
        }
        return head;
         
        
    }
};