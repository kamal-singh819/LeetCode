class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        int ans = INT_MAX;
        unordered_map<int, unordered_set<int>> hash;
        for(auto x : points){
            hash[x[0]].insert(x[1]);
        }

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(points[i][1] == points[j][1]){
                    int x = points[i][0];
                    int y = points[j][0];
                    for(auto it : hash[x]){
                        if(it != points[i][1] && hash[y].find(it) != hash[y].end()){
                            int area = abs(it-points[i][1]) * abs(points[i][0]-points[j][0]);
                            ans = min(ans, area);
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;   
    }
};
