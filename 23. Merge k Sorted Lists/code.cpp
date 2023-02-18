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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
    
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;
        for(auto x : lists){
            ListNode* h = x;
            while(h != NULL){
                pq.push({h->val, h});
                h = h->next;
            }
        }
        ListNode* temp = NULL;
        while(!pq.empty()){
            if(head == NULL){
                head = pq.top().second;
                pq.pop();
                temp = head;
            }
            else{
                temp->next = pq.top().second;
                pq.pop();
                temp = temp->next;
            }
        }
        return head;
        
    }
};
