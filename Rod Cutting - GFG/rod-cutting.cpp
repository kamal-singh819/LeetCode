//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  private:
    int fun(int price[], int n, int w, vector<vector<int>> &dp){
        if(n == 0 || w == 0) return 0;
        if(dp[n][w] != -1) return dp[n][w];
        
        if(n <= w) return dp[n][w] = max(price[n-1] + fun(price, n, w-n, dp), fun(price, n-1, w, dp));
        return dp[n][w] = fun(price, n-1, w, dp);
    }
  public:
    int cutRod(int price[], int n) {
        // int length[n];
        // for(int i=0; i<n; i++) length[i] = i+1; (No need of this array)
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int w = n;
        return fun(price, n, w, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends