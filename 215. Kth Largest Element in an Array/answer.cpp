
//   USING MIN HEAP   //////////

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //use min heap cozz we have to find largest element....
        priority_queue<int, vector<int>, greater<int> > minHeap;
        for(int x : nums){
            minHeap.push(x);
            if(minHeap.size() > k)
                minHeap.pop();
        }

        return minHeap.top();
        
    }
};












class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++)
            pq.push(nums[i]);

        for(int i=1; i<k; i++){
            pq.pop();
        } 

        return pq.top();   
        
    }
};
