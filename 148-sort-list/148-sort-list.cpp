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
    ListNode* mergeList(ListNode* l1,ListNode *l2){
        ListNode* newnode=new ListNode(0);
        ListNode *pt=newnode;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                pt->next=l1;
                l1=l1->next;
            }
            else{
                pt->next=l2;
                l2=l2->next;
            }
            pt=pt->next;
        }
        while(l1!=NULL){
            pt->next=l1;
            l1=l1->next;
            pt=pt->next;
        }
        while(l2!=NULL){
            pt->next=l2;
            l2=l2->next;
            pt=pt->next;
        }
        return newnode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=NULL;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return mergeList(l1,l2);
    }
};