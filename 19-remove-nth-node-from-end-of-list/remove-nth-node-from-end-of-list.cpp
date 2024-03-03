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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL || head==NULL){
            return NULL;
        }
        int count=0;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(n>count){
            return head;
        }
        int i=0;
        temp=head;
        int k=count-n;
        while(i<k){
            prev=temp;
            temp=temp->next;
            i++;
        }
        if(prev==NULL){
            head=temp->next;
        }
        else{
            prev->next=temp->next;
        }
        delete temp;
        return head;
    }
};