class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int borrow = 0;
        int i = a.length()-1;
        int j = b.length()-1;

        while(i >= 0 || j >= 0 || borrow == 1){
            borrow += ((i >= 0) ? a[i]-'0' : 0);
            borrow += ((j >= 0) ? b[j]-'0' : 0);

            ans = char(borrow%2 + '0') + ans; //
            borrow = borrow/2;
            i--;
            j--;
        }
        return ans;
        
    }
};
