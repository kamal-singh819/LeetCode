class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        int n = goal.length();
        s = s+s;

        for(int i=0; i<=s.length()-n; i++){
            string sub = s.substr(i, n);
            if(sub == goal)
                return true;
        }
        return false;
        
    }
};
