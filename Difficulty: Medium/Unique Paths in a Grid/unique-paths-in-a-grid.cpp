class Solution {
  public:
    int solve(int i, int j, int n, int m, vector<vector<int>> &arr, map<pair<int, int>, int> &memo) {
        if(i >= n || j >= m){
            return 0;
        }
        
        if(arr[i][j] == 1) {
            return 0;
        }
        
        pair<int, int> key = {i, j};
        if(memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        if(i == n - 1 && j == m - 1) {
            memo[key] = 1;
            return 1;
        }
        
        return memo[key] = (solve(i + 1, j, n, m, arr, memo) + solve(i, j + 1, n, m, arr, memo));
        
    }
    int uniquePaths(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        map<pair<int, int>, int> memo;
        int ans = solve(0, 0, n, m, arr, memo);
        return ans;
    }
};