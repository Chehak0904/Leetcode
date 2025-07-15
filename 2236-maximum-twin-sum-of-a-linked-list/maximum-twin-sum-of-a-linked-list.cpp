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
    int pairSum(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        int target=cnt/2;
        temp=head;
        while(target>1){
            temp=temp->next;
            target--;

        }
        ListNode* head2=temp->next;
        temp->next=NULL;
        temp=head2;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        head2=prev;
        int ans=0;
        while(head2!=NULL){
            ans=max(ans,head->val+head2->val);
            head2=head2->next;
            head=head->next;
        }
        return ans;
    }
};