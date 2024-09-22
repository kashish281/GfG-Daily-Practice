//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
          int n = str.size();
    vector<int> ans(n,0);
    int i = 0;
    int j = 1;
    
    while(j != n){
         // case 1 : Both are same
         if(str[i] == str[j]){
            ans[j] = i + 1;
            i++;
            j++;
         }
           // case 2 : Both are not same
          else{
              // case 1: i == 0
              if(i ==0){
                  ans[j] = 0;
                  j++;
              }
              //case 2 : i!=0
              else{
                  i = ans[i - 1];
              }
          }
    }
  return ans.back();
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
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends