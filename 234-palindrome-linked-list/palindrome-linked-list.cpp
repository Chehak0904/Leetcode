class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

       
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        int half = n / 2;
        temp = head;
        ListNode* prev = nullptr;
        ListNode* curr = temp;

        
        while (half--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* head1 = prev;  
        ListNode* head2 = curr;  

        
        if (n % 2 != 0) {
            head2 = head2->next;
        }

       
        while (head1 != nullptr ) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};
