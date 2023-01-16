class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> negative;
        vector<int> positive;

        for(int i=0; i<len; i++){
            int x = nums[i];
            if(x < 0)
                negative.push_back(x);
            else
                positive.push_back(x);    
        }
        
        int j = 0;
        int k = 0;
        while(k < len){
            nums[k] = positive[j];
            nums[k+1] = negative[j];
            k = k+2;
            j++;
        }
        return nums;    
    }
};
