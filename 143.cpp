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
    void reorderList(ListNode *head) {
        if(!head)return;
        if(!head->next)return;
        int len=0;
        int tmplen=0;
        ListNode* reorderHead=NULL;
        ListNode* tmpHead=NULL;
        for(ListNode* ptr=head;ptr;ptr=ptr->next){
            len++;
        }
        for(ListNode* ptr=head;ptr;ptr=ptr->next){
            tmplen++;
            if(tmplen==(len+1)/2){
                tmpHead=ptr->next;
                ptr->next=NULL;
                break;
            }
        }
        while(tmpHead){
            ListNode* tmp=tmpHead;
            tmpHead=tmp->next;
            tmp->next=reorderHead;
            reorderHead=tmp;
        }
        for(ListNode* ptr=head;ptr;){
            if(reorderHead==NULL)break;
            ListNode* tmp=reorderHead;
            reorderHead=tmp->next;
            tmp->next=ptr->next;
            ptr->next=tmp;
            ptr=ptr->next->next;
        }
    }
};
