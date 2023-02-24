class Solution {
    private:
    string sumOfTwoString(string X, string Y){
        int i = X.length()-1;
        int j = Y.length()-1;
        int rem = 0;
        string t = "";
        while(i >= 0 || j >= 0 || rem != 0){
            int a = 0, b = 0, s = 0;
            if(i >= 0) a = X[i]-'0';

            if(j >= 0) b = Y[j]-'0';

            s = rem + a + b;
            rem = s/10;
            t += (s%10)+'0';
            i--;
            j--;
        }
        reverse(t.begin(), t.end());
        return t;
    }
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int m = num1.length();
        int n = num2.length();
        string ans = "";
        string prev = "0";
        for(int i=m-1; i>=0; i--){
            char ch = num1[i];
            string temp = "";
            int rem = 0;
            for(int j=n-1; j>=0; j--){
                int x = num2[j]-'0';
                int res = rem + x*(ch-'0');
                temp.push_back((res%10)+'0');
                rem = res/10;
            }
            if(rem != 0)
                temp.push_back(rem+'0');

            reverse(temp.begin(), temp.end());
            int zeroAppend = m-1-i;
            for(int k=1; k<=zeroAppend; k++)
                temp += '0';
            
            ans = sumOfTwoString(prev, temp);
            //cout<<ans<<" ";
            prev = ans;
        }
        return ans;    
    }
};
