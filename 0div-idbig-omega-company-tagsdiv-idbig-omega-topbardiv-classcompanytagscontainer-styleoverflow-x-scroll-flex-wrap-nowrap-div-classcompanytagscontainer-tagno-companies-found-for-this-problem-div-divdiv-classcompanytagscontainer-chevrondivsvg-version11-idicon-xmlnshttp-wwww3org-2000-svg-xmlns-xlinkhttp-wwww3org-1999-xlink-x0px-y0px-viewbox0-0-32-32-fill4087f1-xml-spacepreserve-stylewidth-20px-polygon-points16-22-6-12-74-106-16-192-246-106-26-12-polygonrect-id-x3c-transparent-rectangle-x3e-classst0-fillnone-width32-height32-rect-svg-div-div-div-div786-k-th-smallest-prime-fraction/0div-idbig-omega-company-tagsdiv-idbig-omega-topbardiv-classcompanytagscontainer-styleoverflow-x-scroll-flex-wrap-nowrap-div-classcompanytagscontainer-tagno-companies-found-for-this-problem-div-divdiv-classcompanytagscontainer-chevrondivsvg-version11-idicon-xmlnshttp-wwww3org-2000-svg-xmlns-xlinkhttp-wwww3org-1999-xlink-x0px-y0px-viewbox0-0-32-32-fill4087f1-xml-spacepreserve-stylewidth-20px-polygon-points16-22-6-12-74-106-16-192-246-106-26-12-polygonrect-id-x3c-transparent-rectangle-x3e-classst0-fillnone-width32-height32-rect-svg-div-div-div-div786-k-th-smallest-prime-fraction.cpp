class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, vector<int> >> pq;
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                pq.push({(double)arr[i]/(double)arr[j], {arr[i], arr[j]}});
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top().second;
    }
};