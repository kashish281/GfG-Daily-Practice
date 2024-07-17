//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int find(vector<int>& arr, vector<vector<int>>& dp, int i, int n, bool isIncreasing) {
        if (i >= n) return 0;
        
        if (dp[i][isIncreasing] != -1) {
            return dp[i][isIncreasing];
        }
        
        int nottake = find(arr, dp, i + 1, n, isIncreasing);
        int take = -1e9;
        
        if (isIncreasing) {
           
            if (i == 0 || arr[i] > arr[i - 1]) {
                take = 1 + find(arr, dp, i + 1, n, !isIncreasing);
            }
        } else {
            
            if (i == 0 || arr[i] < arr[i - 1]) {
                take = 1 + find(arr, dp, i + 1, n, !isIncreasing);
            }
        }
        
        return dp[i][isIncreasing] = max(take, nottake);
    }
public:
    int alternatingMaxLength(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        int inc = find(arr, dp, 0, n, true);
        int dec = find(arr, dp, 0, n, false);
        
        return max(inc, dec);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends