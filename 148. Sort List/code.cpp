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
    ListNode* sortList(ListNode* head) {
        priority_queue<int, vector<int>, greater<int> > minHeap;
        ListNode* temp = head;
        while(temp != NULL){
            minHeap.push(temp->val);
            temp = temp->next;
        }
        head = NULL;
        temp = NULL;
        while(!minHeap.empty()){
            int x = minHeap.top();
            minHeap.pop();
            ListNode* node = new ListNode(x);
            if(head == NULL && temp == NULL){
                head = node;
                temp = node;
                continue;
            }
            temp->next = node;
            temp = node;

        }
        return head;   
    }
};
