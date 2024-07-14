//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s>9*d) return "-1";
    string ans;
    for(int i=0;i<d;i++){
        int x = (i==d-1)?s:s-1;
        ans+=to_string(min(9,x));
        s-=min(9,x);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends