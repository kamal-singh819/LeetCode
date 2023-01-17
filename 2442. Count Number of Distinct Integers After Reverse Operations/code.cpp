//Using unordered_set---------------------

class Solution {
private:
    int reverseOfNumber(int x){
        int num = 0;
        while(x > 0){
            num = num*10 + x%10;
            x = x/10;
        }
        return num;
    }    
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
            if(x < 10)
                st.insert(x);
            else{
                st.insert(x);
                int y = reverseOfNumber(x);
                st.insert(y);
            }    
        }

        return st.size();
        
    }
};
