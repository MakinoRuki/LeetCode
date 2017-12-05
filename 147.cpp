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
    ListNode *insertionSortList(ListNode *head) {
        if(!head)return head;
        ListNode* newHead=NULL;
        while(head){
            ListNode* tmp=head;
            head=head->next;
            if(!newHead){
                newHead=tmp;
                tmp->next=NULL;
            }else{
                ListNode* cur;
                if(tmp->val<=newHead->val){
                    tmp->next=newHead;
                    newHead=tmp;
                }else{
                    for(cur=newHead; cur->next; cur=cur->next){
                        ListNode* next=cur->next;
                        if(cur->val <= tmp->val && next->val>=tmp->val){
                            tmp->next=next;
                            cur->next=tmp;
                            break;
                        }
                    }
                    if(!cur->next){
                        cur->next=tmp;
                        tmp->next=NULL;
                    }
                }
            }
        }
        return newHead;
    }
};
