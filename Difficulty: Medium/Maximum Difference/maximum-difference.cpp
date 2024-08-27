//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
          int n=arr.size();
        vector<int> lA(n);
        vector<int> rA(n);
        lA[0]=0;
        rA[n-1]=0;
        
        stack<int> st;
        st.push(arr[0]);
        
        for(int i=0;i<n;i++) {
            while(st.size()!=0 && st.top()>=arr[i]) {
                st.pop();
            }
            if(st.size()!=0) {
                lA[i]=st.top();
            }
            else {
                lA[i]=0;
            }
            st.push(arr[i]);
        }
        
        while(!st.empty()) {
            st.pop();
        }
        
        st.push(arr[n-1]);
        
        for(int i=n-2;i>=0;i--) {
            while(st.size()!=0 && st.top()>=arr[i]){
                st.pop();
            }
            if(st.size()!=0) {
                rA[i]=st.top();
            }
            else {
                rA[i]=0;
            }
            st.push(arr[i]);
        }
        
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) {
            maxi=max(maxi,abs(lA[i]-rA[i]));
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends