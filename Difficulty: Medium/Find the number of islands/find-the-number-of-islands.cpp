//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     void BFS(vector<vector<bool>>&visit,int i,int j,int n,int m,vector<vector<char>>&grid){
      
      visit[i][j]=true;
      int x[]={1,1,0,-1,-1,-1,0,1};
      int y[]={0,1,1,1,0,-1,-1,-1};
      queue<pair<int,int>>q;
      q.push({i,j});
      
      while(q.empty()==false){
          
          int r=q.front().first;
          int c=q.front().second;
          q.pop();
          for(int k=0;k<8;k++){
              int newR=r+x[k];
              int newC=c+y[k];
              if(newR>=0 && newR<n && newC>=0 && newC<m && visit[newR][newC]==false && grid[newR][newC]=='1'){
                  q.push({newR,newC});
                  visit[newR][newC]=true;
              }
          }
          
      }
      
  }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visit[i][j]==false){
                    BFS(visit,i,j,n,m,grid);
                    ans++;
                }
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
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends