//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  vector<vector<int>>memo;
  int dp(const string &x,const string &y,int n,int m)
  {
      if(n==0|| m==0)
      {
          return 0;
      }
      if(memo[n][m]!=-1)
      {
          return memo[n][m];
      }
      if(n==0 || m==0)
      {
          return memo[n][m];
      }
      else if(x[n-1]==y[m-1])
      {
          memo[n][m]=1+dp(x,y,n-1,m-1);
      }
      else
      {
          memo[n][m]=max(dp(x,y,n-1,m),dp(x,y,n,m-1));
      }
      return memo[n][m];
  }
    int findMinCost(string x, string y, int costX, int costY) 
    {
        // Your code goes here
          int n=x.size();
        int m=y.size();
        memo.resize(n+1,vector<int>(m+1,-1));
          int ans=dp(x,y,n,m);
        int res=(n-ans)*costX+(m - ans)*costY;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends