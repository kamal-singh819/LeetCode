//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    /*
    int recfun(string s1, int n, string s2, int m){
        if(n == 0 || m == 0) return 0;
        
        if(s1[n-1] == s2[m-1]) return 1+recfun(s1, n-1, s2, m-1);
        return max(recfun(s1, n-1, s2, m), recfun(s1, n, s2, m-1));
    }
    */
    /*
    int memofun(string s1, int n, string s2, int m, vector<vector<int>> &dp){
        if(n == 0 || m == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s1[n-1] == s2[m-1]) return dp[n][m] = 1+memofun(s1, n-1, s2, m-1, dp);
        return dp[n][m] = max(memofun(s1, n-1, s2, m, dp), memofun(s1, n, s2, m-1, dp));
    }
    */
    
    int tabulation(string &s1, int &n, string &s2, int &m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    
    int lcs(int n, int m, string s1, string s2)
    {
        // return recfun(s1, n, s2, m);
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return memofun(s1, n, s2, m, dp);
        
        return tabulation(s1, n, s2, m);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends