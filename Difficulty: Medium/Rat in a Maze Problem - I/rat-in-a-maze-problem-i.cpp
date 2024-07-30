//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     vector<string> ans;
    vector<vector<bool>> vis;
    void solve(int i, int j, int n, vector<vector<int>> &mat, string str){
        if(i == n-1 && j == n-1){
            ans.emplace_back(str);
            return;
        }
        if(i >= n || j >= n || i < 0 || j < 0 || mat[i][j] == 0) return;
        if(vis[i][j] == true) return;
        vis[i][j] = true;
        solve(i+1, j, n, mat, str + 'D');
        solve(i-1, j, n, mat, str + 'U');
        solve(i, j+1, n, mat, str + 'R');
        solve(i, j-1, n, mat, str + 'L');
        vis[i][j] = false;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        ans.clear();
        int n = mat.size();
        vis.resize(n, vector<bool>(n, false));
        if(mat[0][0] == 0 or mat[n-1][n-1] == 0) return ans;
        solve(0, 0, n, mat, "");
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends