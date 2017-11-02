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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur = NULL, *head = NULL;
        int sum = 0, add = 0;
        while(l1 || l2) {
            sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += add;
            add = sum / 10;
            sum %= 10;
            if (!cur) {
                cur = new ListNode(sum);
                head = cur;
            } else {
                cur->next = new ListNode(sum);
                cur = cur->next;
            }
        }
        if (add) {
            cur->next = new ListNode(add);
            cur = cur->next;
        }
        return head;
    }
};
