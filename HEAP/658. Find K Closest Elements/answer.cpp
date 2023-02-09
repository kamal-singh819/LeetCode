////////////////////////   USING MAX HEAP   ////////////////

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //create a max heap as Ques. is asking for K closest elements---

        
        //maxHeap will contain pairs of difference(abs(arr[i]-x)) with corresponding to arr[i]--
        priority_queue<pair<int, int>> maxHeap;  
        vector<int> ans;

        for(int i=0; i<arr.size(); i++){
            maxHeap.push(make_pair(abs(arr[i]-x), arr[i]));

            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());

        return ans;
        
    }
};
