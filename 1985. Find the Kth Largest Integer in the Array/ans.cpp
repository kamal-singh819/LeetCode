class Solution {
public:
    static bool comp(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] < s2[i];
        }
    }
    return false;
}

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        
        
        return nums[nums.size()-k];   
    }
};
