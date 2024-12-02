//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        int LPS[2*(s.size()+1)];
        char ch[2*(s.size()+1)];
        int n = 2*(s.size()+1); 
        
        for(int i=0 ; i < s.size() ; i++) {
            ch[i+1] = ch[n-i-1] = s[i];
            LPS[i] = LPS[i + s.size()] = 0;
        }
        LPS[n-1] = LPS[n-2] = 0; 
        ch[s.size()+1] = '%'; 
        int first = 0 ; int second = 2;
        while(second < n) { 
            if(ch[first+1]==ch[second]) {
                LPS[second] = first+1;
                first++;
                second++;
            } else {
                if(first==0) {
                    second++;
                } else{
                    first = LPS[first];
                }
            }
        }
        
        return s.size() - LPS[n-1]; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends