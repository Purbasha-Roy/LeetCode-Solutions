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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        int prefixsum=0;
        map<int, ListNode*> mp;
        mp[0]=dummy;
        while(head){
            prefixsum+=head->val;
            if(mp.find(prefixsum)!=mp.end()){
                ListNode* node=mp[prefixsum];
                ListNode* start=node;
                int psum=prefixsum;
                while(start!=head){
                    start=start->next;
                    psum+=start->val;
                    if(start!=head){
                        mp.erase(psum);
                    }
                }
                node->next=start->next;
            }
            else{
                mp[prefixsum]=head;
            }
            head=head->next;
        }
        return dummy->next;
    }
};