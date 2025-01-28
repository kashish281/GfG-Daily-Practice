//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        sort(s.begin(),s.end());
       set<string>st;
       st.insert(s);
       
       while(next_permutation(s.begin(),s.end())) 
            st.insert(s);
           
       return vector<string>(st.begin(),st.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends