//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        vector<int>alph(26 , 0) ; 
        
        for(char ch : s1) alph[ch - 'a'] ++ ;
        
        for(char ch : s2) alph[ch - 'a'] -- ;
        
        for(int i : alph) if(i != 0) return 0 ;
        
        return 1 ;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends