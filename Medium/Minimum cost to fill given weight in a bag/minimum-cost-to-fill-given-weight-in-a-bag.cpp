//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimumCost(int n, int W, vector<int> &cost) {
        const int INF = 1e8;
        vector<int>prev(W + 1, INF);
        prev[0] = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int w = 1; w <= W; w++){
                int take = INF, nottake = prev[w];
                if(i + 1 <= w && cost[i] != -1)
                    take = cost[i] + prev[w - (i + 1)];
                prev[w] = min(take, nottake);
            }
        }
    
        int ans = prev[W];
        if(ans >= INF)
            ans = -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends