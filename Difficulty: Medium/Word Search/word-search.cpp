//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool solve(vector<vector<char>>&mat,string word,int i,int j,int k,int n,int m){
        if(i < 0 || i >= n || j < 0 || j >= m || k >= word.size() || mat[i][j] != word[k])
        return false;
        
        if(k == word.size()-1)
        return true;
        
        char ch = mat[i][j];
        mat[i][j] = '*';
        bool up = 0 , down = 0 , left = 0 , right = 0;
        
        up = solve(mat,word,i-1,j,k+1,n,m);
        down = solve(mat,word,i+1,j,k+1,n,m);
        left = solve(mat,word,i,j-1,k+1,n,m);
        right = solve(mat,word,i,j+1,k+1,n,m);
        
        mat[i][j] = ch;
        
        return (up || down || left || right);
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
            int n = mat.size() , m = mat[0].size();
    for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
    if(word[0] == mat[i][j]){
    if(solve(mat,word,i,j,0,n,m))
    return true;
    }
    }
    }
    
    return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends