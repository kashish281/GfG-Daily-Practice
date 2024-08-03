//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
         int index =-1;
        int cnt =0;
        int n =mat.size();
        for(int i =0;i< n;i++){
            int flag =1;
            for(int j =0;j< n;j++){
                if(mat[i][j] == 1){
                    flag =0;
                }
            }
            if(flag){
                index =i;
                cnt++;
            }
        }
        int cnt2=0;
        if(cnt ==1){
            for(int i =0;i< n;i++){
                if(mat[i][index] == 1){
                    cnt2++;
                }
            }
            if(cnt2 == n -1){
                return index;
            }return -1;
        }else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends