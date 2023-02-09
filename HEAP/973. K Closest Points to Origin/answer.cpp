class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        //Ques. is asking for K closest points... means distance from origin of than point should be minimum..

        //so use maxheap-----------
        //ans maxHeap will store pair of distance(square of distance(optional)) with corresponding point.....
        priority_queue<pair<int, vector<int>> > maxHeap;
        for(int i=0; i<points.size(); i++){
            int d = pow(points[i][0], 2) + pow(points[i][1], 2);
            maxHeap.push(make_pair(d, points[i]));

            if(maxHeap.size() > k)
                maxHeap.pop();
        }

        ///pop out all the elements one by one ans give the answer--

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;

        
    }
};
