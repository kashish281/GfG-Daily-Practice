//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
         vector<pair<int,char>>x;
        for(int i=0;i<n;i++){
            x.push_back({l[i],'l'});
            x.push_back({r[i],'r'});
        }
        sort(x.begin(),x.end());
        int maxi = INT_MIN;
        int ct = 0;
        int ans = -1;
        for(auto pai:x){
            char c = pai.second;
            if(c == 'l'){
                ct++;
            }
            else{
                ct--;
            }
            if(ct > maxi){
                ans = pai.first;
                maxi = ct;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends