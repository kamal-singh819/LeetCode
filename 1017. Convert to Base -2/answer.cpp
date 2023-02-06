class Solution {
public:
    string baseNeg2(int n) {
        string ans = "";
        if(n == 0)
            return "0";
        while(n != 0){
            int rem = n%(-2);
            //cout<<rem<<"  ";
            n = n/(-2);  
            if(rem < 0){
                rem += 2;
                n++;
            }
            ans += to_string(rem);
        }
        reverse(ans.begin(), ans.end());
        return ans;    
    }
};
