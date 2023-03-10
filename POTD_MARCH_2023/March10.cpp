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
private: ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0));
        
    }
    
    int getRandom() {
        int ans = 0;
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;

            if(rand()%count == 0) ans = temp->val;

            temp = temp->next;
        }
        return ans;  
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */



/////////////////////////////////////////    2nd Approach    /////////////////////////////////


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
private: ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0));
        
    }
    
    int getRandom() {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(len == 1) return head->val;
        int random = rand()%len;
        temp = head;
        for(int i=0; i<random; i++){
            temp = temp->next;
        }
        return temp->val;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
