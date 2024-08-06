//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
         str.push_back('.');
        int n=str.size();
        stack<string> st;
        int c=0;
        for(int i=0;i<n;i++){
            string s;
            while(str[i]!='.'){
                s.push_back(str[i]);
                i++;
            }
            if(str[i]=='.') c++;
            if(str[i]=='.' and str[i+1]=='.') return false;
            st.push(s);
        }
        if(c!=4) return false;
        while(!st.empty()){
            string aa = st.top();
            if(aa.size()>1 && aa[0]=='0') return false;
            int x = stoi(aa);
            st.pop();
            if(x<0 || x>255) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends