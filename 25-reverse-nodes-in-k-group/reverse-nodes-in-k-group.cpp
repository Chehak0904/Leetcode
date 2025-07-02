class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* curr = head;
        int count = 0;

        
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count < k) return head; 

      
        ListNode* prev = NULL;
        curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        
        head->next = reverse(curr, k);

        
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head, k);
    }
};
