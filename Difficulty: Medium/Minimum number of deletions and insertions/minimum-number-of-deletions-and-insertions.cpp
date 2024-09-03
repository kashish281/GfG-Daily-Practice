//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size(), m = str2.size(); long long dp[n+1][m+1];
	    for ( int i = 0; i<n+1; i++ ){
	        for ( int j = 0; j<m+1; j++ ) dp[i][j] = -1e15;
	        dp[i][m] = 0;
	    }
	    for ( int j = 0; j<m+1; j++ ) dp[n][j] = 0;
	    for ( int i = n-1; i>=0; i-- ){
	        for ( int j = m-1; j>=0; j-- ){
	            if ( str1[i] == str2[j] ) dp[i][j] = 1 + dp[i+1][j+1];
	            else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
	        }
	    } return n + m - 2*dp[0][0];
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends