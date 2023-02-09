//T.C = O(nlogn)

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end()); //max heap

        for(int i=1; i<nums.size(); i += 2){  //top large elements put on odd indices--
            nums[i] = pq.top();
            pq.pop();
        }

        for(int i=0; i<nums.size(); i += 2){  // small elements put on odd indices--
            nums[i] = pq.top();
            pq.pop();
        }
        
        
    }
};
