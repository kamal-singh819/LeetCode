class Solution{
public:
    int findJudge(int n, vector<vector<int>> &trust){
        if(n==1){
            return 1;
        }
        vector<int> totalDegree(n+1, 0);
        for(auto x : trust){
            totalDegree[x[0]]--; //out
            totalDegree[x[1]]++; //in
        }

        //indegree-outdegree == n-1 hona chahiye...
        for(int i=0; i<n+1; i++){
            if(totalDegree[i] == n-1)
                return i;
        }
        return -1;
    }
};
