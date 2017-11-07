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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = NULL, *pre = NULL;
        int idx = 0;
        cur = head;
        while(cur) {
            idx++;
            if (idx % k == 0 && idx / k >= 1) {
                ListNode* next = cur->next;
                ListNode* tmp;
                if (pre) tmp = pre->next;
                else tmp = head;
                ListNode* tmpHead = NULL, *tmpTail = NULL;
                while(tmp != next) {
                    ListNode* tmpNext = tmp->next;
                    if (!tmpHead) {
                        tmpHead = tmp;
                        tmpTail = tmp;
                    } else {
                        tmp->next = tmpHead;
                        tmpHead = tmp;
                    }
                    tmp = tmpNext;
                }
                if (pre) pre->next = tmpHead;
                else head = tmpHead;
                tmpTail->next = next;
                pre = tmpTail;
                cur = pre;
            }
            cur = cur->next;
        }
        return head;
    }
};
