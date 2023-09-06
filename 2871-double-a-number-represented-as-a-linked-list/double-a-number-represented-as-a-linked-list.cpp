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
ListNode* reverseLL(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* nextp=NULL;
    while(curr!=NULL){
        nextp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextp;
    }
    return prev;
}
    ListNode* doubleIt(ListNode* head) {
        ListNode* root=reverseLL(head);
        ListNode* prev=new ListNode();
        ListNode* h=prev;
        int carry=0;
        while(root!=NULL || carry){
            int value=0;
            if(root){
                value=root->val*2;
                root=root->next;
            }
            value+=carry;
            carry=value/10;
            ListNode* node=new ListNode(value%10);
            prev->next=node;
            prev=node;
        }
        ListNode* ans=reverseLL(h->next);
        return ans;
    }

};