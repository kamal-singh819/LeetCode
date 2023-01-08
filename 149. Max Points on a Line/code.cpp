class Solution {
private:
public:
    int maxPoints(vector<vector<int>>& points) {
        int def = INT_MIN; //take ans int for infinite slop
        int ans = 1; //for only one point i.e if points.size() == 1 return 1;
        int m = points.size();
        for(int i=0; i<m-1; i++){
            unordered_map<double,int> mp; //will store slop,count of that slop

            vector<int> x1y1 = points[i];

            for(int j=i+1; j<m; j++){
                vector<int> x2y2 = points[j];
                if(x2y2[0] == x1y1[0]){
                    mp[def]++;
                }
                else{
                    double slop = (double)(x2y2[1]-x1y1[1])/(double)(x2y2[0]-x1y1[0]);
                    mp[slop]++;
                }
            }
            int temp = 0;
            for(auto it : mp){
                temp = max(temp, it.second+1);
            }
            ans = max(ans, temp);
        }
        return ans;    
    }
};
