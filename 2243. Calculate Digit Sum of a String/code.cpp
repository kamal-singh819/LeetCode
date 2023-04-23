class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        if(n <= k) return s;
        string ans = "";
        int i = 0;
        int j = 0;
        while(i < n){
            int sum = 0;
            while(j < n && j-i+1 <= k){
                sum += (s[j] - '0');
                j++;
            }
            ans += to_string(sum);
            i = j;
            if(j == n) break;
        }
        n = ans.length();
        if(n > k) ans = digitSum(ans, k);
        return ans;
    }
};
