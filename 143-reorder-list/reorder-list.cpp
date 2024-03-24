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
    ListNode* mid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nextp=NULL;
        while(curr){
            nextp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* middle=mid(head);
        ListNode* reversehead=reverse(middle->next);
        middle->next=NULL;

        ListNode* curr1=head;
        ListNode* curr2=reversehead;
        ListNode* fow1=NULL;
        ListNode* fow2=NULL;
        while(curr1 && curr2){
            fow1=curr1->next;
            fow2=curr2->next;

            curr1->next=curr2;
            curr2->next=fow1;

            curr1=fow1;
            curr2=fow2;
        }
    }

};