class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        
        int hmin, hmax; //hmin -> start    and hmax -> end
        int ans = -1;

        while(i < j){
            hmin = height[i];
            hmax = height[j];

            int area = (j-i)*min(hmin, hmax);
            ans = max(ans, area);

            if(hmin < hmax){
                while(height[i+1] < hmin)
                    i++;
                i++;
            }
            else if(hmax < hmin){
                while(height[j-1] < hmax)
                    j--;
                j--;
            }
            else{
                i++;
                j--;
            }

        }
        return ans;
        
    }
};
