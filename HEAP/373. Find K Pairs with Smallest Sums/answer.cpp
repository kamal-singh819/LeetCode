class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int> > ans;
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<pair<int, vector<int>> > maxHeap;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vector<int> v = {nums1[i], nums2[j]};
                int s = nums1[i]+nums2[j];
                if(maxHeap.size() < k)
                    maxHeap.push({s, v});
                else if(s < maxHeap.top().first){
                    maxHeap.pop();
                    maxHeap.push({s, v});
                }
                else
                    break;
            }
        }

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
        
    }
};
