//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<long long> prevSmallerElement(vector<long long>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<long long> ans(n);

        for (int i = 0; i < n; i++) {
            long long curr = arr[i];

            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<long long> nextSmaller(vector<long long>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<long long> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            long long curr = arr[i];

            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int getMaxArea(vector<int>& arr) {
        int n = arr.size();
        vector<long long> arrLong(arr.begin(), arr.end()); // Convert to long long vector

        vector<long long> prev = prevSmallerElement(arrLong, n);
        vector<long long> next = nextSmaller(arrLong, n);

        long long maxArea = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            long long length = arr[i];

            if (next[i] == -1) {
                next[i] = n;
            }

            long long width = next[i] - prev[i] - 1;
            long long area = length * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends