//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool func(int n, int k, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(k == 0){
            if(target == 0) return 1;
            else return 0;
        }
        if(dp[k][target] != -1) return dp[k][target];
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(target >= coins[i]){
                bool res = func(n, k-1, target-coins[i], coins, dp);
                if(res) return dp[k][target] = 1;
            }
        }
        return dp[k][target] = 0;
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<int>> dp(K+1, vector<int> (target+1, -1));
        return func(N, K, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends