//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
         int l=0;
        int r=0;
        int n=arr.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        
        while(r<n){
            if(r>=k){
                ans.push_back(mp.size());
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
                
            }
            mp[arr[r]]++;
            r++;
        }
    ans.push_back(mp.size());
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends