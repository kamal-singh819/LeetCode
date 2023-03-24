////////////           Create a prefix sum array             /////////////////////
class Solution {
    private: static bool comp(int i, int j){
        if(i > j) return true;
        return false;
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> vec(n);
        
        sort(nums.begin(), nums.end(), comp); //sort it into decreasing order
        vec[0] = nums[0];
        for(int i=1; i<n; i++){
            vec[i] = nums[i] + vec[i-1];
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(vec[i] > 0) count++;
            else break;
        }
        return count;  
    }
};

////////////           No need to create prefix sum array   //////////////////////

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), greater<>()); //sort it into decreasing order

        long long sum = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum > 0) count++;
            else break;
        }
        return count;  
    }
};
