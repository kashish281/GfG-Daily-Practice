//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
           int n=arr.size();
        int m=arr[0].size();
     for(int k=0;k<arr.size();k++){
         int i=0, j=m-1;
         while(i<j){
             if(arr[k][i]!=arr[k][j]) break;
             else {
                 i+=1;
                 j-=1;
                 continue;
             }
         }
         if(i>=j){
             return to_string(k)+" "+"R";
            
         }
     }
     for(int k=0;k<m;k++){
         int i=0, j=n-1;
         while(i<j){
             if(arr[i][k]!=arr[j][k]) break;
             else {
                 i+=1;
                 j-=1;
             }
         }
         if(i>=j) {
             return to_string(k)+" "+"C";
         }
     }
     return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends