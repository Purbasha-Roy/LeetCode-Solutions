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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count=0;
        ListNode* temp=list1;
        ListNode* anode=NULL;
        ListNode* bnode=NULL;
        while(temp!=NULL){
            if(count==a-1){
                anode=temp;
            }
            else if(count==b+1){
                bnode=temp;
            }
            count++;
            temp=temp->next;
        }
        anode->next=list2;
        temp=list2;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=bnode;
        return list1;
        
    }
};