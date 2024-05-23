//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int mod = (int) (1e9 + 7);
    int solve(vector<int> &arr, int n, int sum, vector<vector<int>> &dp)
    {
        
        if(n == 0)  
        {
            if(sum == 0)    return 1;
            return 0;
        }
        if(dp[n][sum] != -1)    return dp[n][sum];
        if( arr[n-1] <= sum) return dp[n][sum] = (solve(arr,n-1,sum-arr[n-1],dp) % mod + solve(arr,n-1,sum,dp) % mod) % mod;
        return dp[n][sum] = solve(arr,n-1,sum,dp) % mod;
    }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            sum += arr[i];
        }
        
        int s2 = sum + d;
        if(s2&1)    return 0;
        s2 /= 2;

        vector<vector<int>> dp(n+1, vector<int>(s2+1, -1));
        return solve(arr,n,s2,dp);
        
        
    }
    
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends