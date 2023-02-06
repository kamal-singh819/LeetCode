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
    private:
    ListNode* reverseLL(ListNode* &head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next == NULL)
            return {0};
        
        vector<int> ans;
        head = reverseLL(head);
        stack<ListNode*> st;

        while(head != NULL){
            while(!st.empty() && st.top()->val <= head->val)
                st.pop();

            int greaterValue = st.empty() ? 0 : st.top()->val;
            ans.push_back(greaterValue);
            st.push(head);
            head = head->next;    
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
