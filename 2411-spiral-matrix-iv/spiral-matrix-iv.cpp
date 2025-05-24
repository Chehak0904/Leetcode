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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>matrix(m,vector<int>(n,-1));
      ListNode* temp=head;

        int sr = 0;
        int er = m - 1;
        int sc = 0;
        int ec = n - 1;

        while (temp!=NULL) {

            for (int j = sc; j <= ec && temp!=NULL; j++) {
                matrix[sr][j]=temp->val;
                temp=temp->next;
            }
            sr++;

            for (int i = sr; i <= er && temp!=NULL; i++) {
                matrix[i][ec]=temp->val;
                 temp=temp->next;
            }
            ec--;

            for (int j = ec; j >= sc && temp!=NULL; j--) {
                matrix[er][j]=temp->val;
                 temp=temp->next;
            }
            er--;

            for (int i = er; i >= sr && temp!=NULL; i--) {
             matrix[i][sc]=temp->val;
                 temp=temp->next;
            }
            sc++;
        }

        return matrix;
        
    }
};