//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int i = s.size()-1;
        while(i>=0 && s[i]!='0'){
            s[i] = '0';
            i--;
        }
        if(i != -1)
            s[i] = '1';
        else
            s = "1"+s;
        i = 0;
        while(s[i]=='0'){
            i++;
        }
        if(s[0] == '0')
            s.erase(0, i);
        return s;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends