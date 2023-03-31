class Solution {
public:
    //this function returns true if str consists only digits, if any character return false
    bool is_digits(string str){
        return all_of(str.begin(), str.end(), ::isdigit); 
    }
    int maximumValue(vector<string>& strs) {
        int ans = INT_MIN;
        for(auto str : strs){
            if(is_digits(str)) ans = max(ans, stoi(str));
            else ans = max(ans, (int)str.length());
        }
        return ans;
    }
};
