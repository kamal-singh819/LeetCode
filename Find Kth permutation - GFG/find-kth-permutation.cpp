//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        vector<int> num;
        int fact = 1;
        //find factorial of n-1 numbers of num , and store n numbers in vector num
        for(int i=1; i<n; i++){
            fact *= i;
            num.push_back(i);
        }
        num.push_back(n);
        k = k-1; //0-based indexing
        string ans = "";
        while(1){
            int index = k/fact;
            ans += to_string(num[index]);
            num.erase(num.begin()+index); //O(n) time to erase an element from vector
            
            if(num.size() == 0) break;
            //now update k & fact
            k = k%fact; 
            fact = fact/num.size();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends