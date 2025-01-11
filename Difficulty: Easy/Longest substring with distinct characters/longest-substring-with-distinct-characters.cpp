//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char,int>mp;
       int j = 0;
       int ans = 0;
       for (int i = 0; i<s.length(); i++){
           mp[s[i]]+=1;
           while (j < i && mp[s[i]] > 1){
               mp[s[j]]--;
               if (mp[s[j]] == 0) mp.erase(s[j]);
               j++;
           }
           int sz = mp.size();
           ans = max(ans, sz);
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends