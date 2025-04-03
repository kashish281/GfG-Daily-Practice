//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
  
    bool isValid(int i, int j,int n, int m, vector<vector<int>> &mat){
        if(i>=0 && j>=0 && i<n && j<m && mat[i][j]==1)  
            return true;
        return false;    
    }
  
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int, pair<int, int>>> pq;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2)
                    pq.push({i, {j, 0}});
            }
            
        }
        
        int ans = 0;
        
        while(!pq.empty()){
            auto z = pq.front();
            int ix = z.first;
            int jy = z.second.first;
            int cost = z.second.second;
            ans = max(ans, z.second.second);
            
            pq.pop();
            
            for(int k=0;k<4;k++){
                int ti = ix+dx[k];
                int tj = jy+dy[k];
                
                if(isValid(ti, tj, n, m, mat)){
                    pq.push({ti, {tj, cost+1}});
                    mat[ti][tj] = 2;
                }
            }
            
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)
                    return -1;
            }
            
        }

        
        return ans;   
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends