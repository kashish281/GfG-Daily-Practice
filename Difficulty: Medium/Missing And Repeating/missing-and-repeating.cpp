//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        vector<int> ans(2, -1);
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int curr = abs(arr[i]);
            if(arr[curr - 1] < 0) {
                ans[0] = curr;
            }
            else {
                arr[curr - 1] = -arr[curr - 1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                ans[1] = i + 1;
                break;
            }
        }
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends