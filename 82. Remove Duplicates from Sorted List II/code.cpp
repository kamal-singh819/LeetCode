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

//USING MAP--------------------------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        map<int, int> mp;
        ListNode* temp = head;
        while(temp != NULL){
            mp[temp->val]++;
            temp = temp->next;
        }
        
        ListNode* newhead = NULL;
        ListNode* newtemp = NULL;
        for(auto x : mp){
            if(x.second == 1){
                if(newhead == NULL){
                    newhead = new ListNode(x.first);
                    newtemp = newhead;
                }
                else{
                    ListNode* p = new ListNode(x.first);
                    newtemp->next = p;
                    newtemp = p;
                }
            }
        }

        return newhead;
        
    }
};
