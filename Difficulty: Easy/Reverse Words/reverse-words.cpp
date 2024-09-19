//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        reverse(str.begin(), str.end());
        int n = str.size();
        
        int start = 0;
        // Traverse the string and reverse each word in place
        for (int end = 0; end <= n; end++) {
            // If we reach a '.' or end of the string, reverse the current word
            if (end == n || str[end] == '.') {
                reverse(str.begin() + start, str.begin() + end);
                start = end + 1;
            }
        }
        
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends