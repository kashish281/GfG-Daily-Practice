//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
         long long ans = -1;
        long long curr = 0;
        int numberGoing = 0;
        for(auto &e: sentence){
            if(isdigit(e)){
                if(e == '9'){
                    numberGoing = -1;
                    curr = 0;
                }
                else if(numberGoing == -1){
                    continue;
                }
                else{
                    curr = curr*10 + (e - '0');
                    numberGoing = 1;
                }
            }
            else{
                if(numberGoing == 1)
                    ans = max(curr, ans);
                curr = 0;
                numberGoing = 0;
            }
        }
        if(numberGoing == 1){
            ans = max(curr, ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends