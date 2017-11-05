/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur1 = NULL, *cur2 = NULL;
        ListNode* pre = NULL;
        int idx = 0;
        cur1 = head;
        while(cur1) {
            idx++;
            if (idx == n + 1) {
                cur2 = head;
            }
            cur1 = cur1->next;
            if (cur2) {
                pre = cur2;
                cur2 = cur2->next;
            }
        }
        if (cur2) {
            pre->next = cur2->next;
        } else {
            head = head->next;
        }
        return head;
    }
};
