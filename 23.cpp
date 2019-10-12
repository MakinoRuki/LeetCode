// 归并排序可以达到O(n*logk)时间和O(1)内存。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define mp make_pair
class Solution {
public:
    ListNode* merge(vector<ListNode*>& lists, int b, int e) {
        if (b >= e) return NULL;
        if (b+1>=e) return lists[b];
        ListNode* lv=merge(lists, b, (b+e+1)/2);
        ListNode* rv = merge(lists, (b+e+1)/2, e);
        ListNode* nh = NULL;
        ListNode* nt = NULL;
        while(lv || rv) {
            ListNode* cur;
            if (lv) {
                if (!rv || rv->val > lv->val) {
                    cur=lv;
                    lv=lv->next;
                } else {
                    cur=rv;
                    rv=rv->next;
                }
            } else {
                cur=rv;
                rv=rv->next;
            }
            if (!nh) {
                nh=cur;
                nt=cur;
            } else {
                nt->next=cur;
                nt=nt->next;
            }
        }
        if (nt) nt->next=NULL;
        return nh;
    }
    ListNode* mergeKLists(vector<ListNode*> lists) {
        int n = lists.size();
        return merge(lists, 0, n);
    }
};
