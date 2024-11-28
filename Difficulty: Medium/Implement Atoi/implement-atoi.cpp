//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        long long ans = 0;
        bool isNeg = false;
        int i = 0;
        
        while(s[i] == ' ') i++;
        if(s[i] == '-') isNeg = true, i++;
        else if(s[i] == '+') i++;
        
        
        while(s[i] >= '0' && s[i] <= '9'){
            int num = s[i] - '0';
            ans = ans*10 + num;
            
            if(ans > INT_MAX && !isNeg) return INT_MAX;
            else if(ans > INT_MAX && isNeg) return INT_MIN;
            i++;
        }
        
        if(isNeg) return -1*ans;
        else return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends