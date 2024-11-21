//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
    int l=0;
    int r=l+1;
    int maxProfit=0;
    int currMax=-1;
    while(r<n){
        if(prices[l]<prices[r]){
            currMax=max(currMax,prices[r]-prices[l]);
            if(prices[r+1]<prices[r]){
                maxProfit+=currMax;
                currMax=-1;
                l=r+1;
                r=l+1;
            }else if(r==n-1){
               maxProfit+=currMax;
               r++; 
            }else{
               r++;
            }
        }else{
            l=r;
            r=l+1;
        }
    }
    return maxProfit;
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends