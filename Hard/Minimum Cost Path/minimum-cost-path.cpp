//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
       int n = grid.size();
       int m = grid[0].size();
       
       int delrow[] = {-1,0,+1,0};
       int delcol[] = {0,+1,0,-1};
       
       vector<vector<int>> dist(n,vector<int>(m,1e9));
       priority_queue<pair<int,pair<int,int>>,
       vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
       
       pq.push({grid[0][0],{0,0}});
       dist[0][0] = grid[0][0];
       
       while(!pq.empty()){
           int sum = pq.top().first;
           int row = pq.top().second.first;
           int col = pq.top().second.second;
           pq.pop();
           
           if(row == n-1 && col == m-1){
               break;
           }
           
           for(int i = 0; i<4; i++){
               int nrow = row + delrow[i];
               int ncol = col + delcol[i];
               
               if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                  dist[nrow][ncol] > dist[row][col] + grid[nrow][ncol])
                  {
                      dist[nrow][ncol] = dist[row][col] + grid[nrow][ncol];
                      pq.push({dist[nrow][ncol],{nrow,ncol}});
                  }
               
           }
           
       }
       
       return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends