//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
         if(arr[0]==0) return -1;
        int n=arr.size();
        
        vector<int> dp(n,1e9);
        dp[0]=0;
        
        
        for(int ind=0;ind<n;ind++){
            if(arr[ind]==0) continue;
             
            for(int i=1;i<=arr[ind];i++){
               if((ind+i)>=n) break;
            dp[ind+i]=min(dp[ind+i],1 + dp[ind]);
        }
        }
        
        if(dp[n-1]==1e9) return -1;
        return dp[n-1];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends