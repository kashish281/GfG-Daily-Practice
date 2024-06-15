//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
          long long dp[n+1][10]; 
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 9; j++) {
                if(i == 1) dp[i][j] = 1; 
                else {
                    long long sum = 0; 
                    if(j == 0) {
                        sum += (dp[i-1][0] + dp[i-1][8]); 
                    } else if(j == 1) {
                        sum += (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]); 
                    } else if(j == 2) {
                        sum += (dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][5]); 
                    } else if(j == 3) {
                        sum += (dp[i-1][2] + dp[i-1][3] + dp[i-1][6]); 
                    } else if(j == 4) {
                        sum += (dp[i-1][1] + dp[i-1][4] + dp[i-1][5] + dp[i-1][7]); 
                    } else if(j == 5) {
                        sum += (dp[i-1][2] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6] + dp[i-1][8]); 
                    } else if(j == 6) {
                        sum += (dp[i-1][3] + dp[i-1][5] + dp[i-1][6] + dp[i-1][7]); 
                    } else if(j == 7) {
                        sum += (dp[i-1][4] + dp[i-1][7] + dp[i-1][8]);
                    } else if(j == 8) {
                        sum += (dp[i-1][5] + dp[i-1][7] + dp[i-1][8] + dp[i-1][9] + dp[i-1][0]); 
                    } else if(j == 9) {
                        sum += (dp[i-1][6] + dp[i-1][8] + dp[i-1][9]); 
                    }
                    
                    dp[i][j] = sum; 
                }
            }
        }
        
        long long ans = 0; 
        for(int j = 0; j <= 9; j++) {
            ans += dp[n][j]; 
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends