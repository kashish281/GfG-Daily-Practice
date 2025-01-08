//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
    if (n < 3)
        return 0; // A triangle requires at least 3 sides
    
    // Sort the array
    sort(arr.begin(), arr.end());
    
    int count = 0;

    // Fix the largest side at position k
    for (int k = 2; k < n; ++k) {
        int i = 0, j = k - 1;
        // Use two pointers to find valid pairs
        while (i < j) {
            if (arr[i] + arr[j] > arr[k]) {
                // All pairs from i to j are valid
                count += (j - i);
                --j; // Move the second pointer to check the next largest side
            } else {
                ++i; // Move the first pointer to increase the sum
            }
        }
    }

    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends