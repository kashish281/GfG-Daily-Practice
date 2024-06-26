//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
          int n=matrix.size();
        int m=matrix[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<4;k++){
                        int newr=i+delrow[k];
                        int newc=j+delcol[k];
                        if (newr >= 0 && newr < n && newc >= 0 && newc < m && matrix[newr][newc] == 1) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends