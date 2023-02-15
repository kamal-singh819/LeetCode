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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        if(head->next->next == NULL){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        vector<int> indexStored;
        int right = 0;
        int left = head->val;
        ListNode* curr = head->next;
        ListNode* forward = curr->next;
        int index = 2; 
        while(forward != NULL){
            right = forward->val; //forward ka val right me store kr liya...
            if((curr->val < left && curr->val < right) || (curr->val > left && curr->val > right)){
                indexStored.push_back(index);
            }
            left = curr->val; //aage jane se pahle val left me store kar liya..
            curr = curr->next;
            forward = forward->next;
            index++;
        }  
        if(indexStored.size() < 2){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int mn = INT_MAX;
        for(int i=1; i<indexStored.size(); i++){
            mn = min(mn, indexStored[i] - indexStored[i-1]);
        } 
        int mx = indexStored[indexStored.size()-1] - indexStored[0];
        ans.push_back(mn);
        ans.push_back(mx);
        return ans;
    }
};
