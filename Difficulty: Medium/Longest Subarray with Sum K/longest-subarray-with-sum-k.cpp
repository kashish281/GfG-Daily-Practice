//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& a, int k) {
        // code here
        map<int, int> m;
        int ans = 0, sum = 0;
        
        for (int i = 0; i < a.size(); i++) {
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
            
            sum += a[i];
            
            if (m.find(sum - k) != m.end()) {
                ans = max(ans, i - m[sum - k] + 1);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends