//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int f(int i, int j,int n, string &s, vector<vector<int>>&dp){
        if(i == j) return 1;
        if(i > j || i >= n || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(s[i] == s[j]){
            ans = 2 + f(i + 1, j - 1,n, s, dp);
        }
        ans = max(ans, max(f(i + 1, j,n, s, dp), f(i, j - 1,n, s, dp)));
        
        return dp[i][j] = ans;
    }
    int longestPalinSubseq(string &s) {
        // code here
        
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return f(0, n - 1,n, s, dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends