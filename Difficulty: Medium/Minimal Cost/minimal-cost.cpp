//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

    int find(const std::vector<int> &arr, std::vector<int> &dp, int k, int idx) {
    if (idx == 0) return 0;
    if (dp[idx] != -1) return dp[idx];

    int minCost = INT_MAX;
    for (int count = 1; count <= k && (idx - count) >= 0; ++count) {
        minCost = min(minCost, find(arr, dp, k, idx - count) + abs(arr[idx - count] - arr[idx]));
    }
    dp[idx] = minCost;
    return dp[idx];
}

class Solution {
public:
    int minimizeCost(int k, std::vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return find(arr, dp, k, n - 1);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends