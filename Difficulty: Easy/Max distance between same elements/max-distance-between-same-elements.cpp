//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int n = arr.size(), ans = 0;
        for(int i=0; i<n; i++){
            mp1[arr[i]] = i;
        }
        for(int i=n-1; i>=0; i--){
            mp2[arr[i]] = i;
        }
        for(auto it: mp2){
            ans = max(ans, abs(it.second-mp1[it.first]));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends