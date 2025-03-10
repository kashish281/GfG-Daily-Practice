//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int i,int j,string& s1, string& s2,vector<vector<int>> &dp){
        if(j==s2.length() && i==s1.length())
        return 0;
        
        if(j==s2.length())
         return s1.length()-i;
        
        if(i==s1.length())
        return s2.length()-j;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j])
        return dp[i][j] = solve(i+1,j+1,s1,s2,dp);
        
        int mini = INT_MAX;
        mini = min(mini,solve(i+1,j,s1,s2,dp));
        mini = min(mini,solve(i,j+1,s1,s2,dp));
        mini = min(mini,solve(i+1,j+1,s1,s2,dp));
        return dp[i][j] = 1 + mini;
    }
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
     
     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //dp[n][m] = 0
  
    
    for(int i=0;i<n;i++) dp[i][m]= n-i;
    for(int j=0;j<m;j++) dp[n][j] = m-j;
    
    
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            
            if(s1[i]==s2[j]) 
             dp[i][j] = dp[i+1][j+1];
            
            else{
                dp[i][j]= 1 + min({
                    dp[i+1][j], //remove
                    dp[i][j+1], //insert
                    dp[i+1][j+1],//replace
                    });
        }
       
    }
}
     return dp[0][0];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends