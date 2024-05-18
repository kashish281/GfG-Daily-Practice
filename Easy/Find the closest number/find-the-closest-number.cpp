//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k, int A[]) 
    {
        int floor = -1;
        int lo = 0;
        int hi = n-1;
        while (lo <= hi) {
            int mid = (lo + hi)>>1;
            if (A[mid] == k) return k;
            if (A[mid] < k) {
                floor = A[mid];
                lo = mid+1;
            }
            else hi = mid-1;
        }
        int ceil = -1;
        lo = 0;
        hi = n-1;
        while (lo <= hi) {
            int mid = (lo + hi)>>1;
            if (A[mid] == k) return k;
            if (A[mid] < k) lo = mid+1;
            else {
                ceil = A[mid];
                hi = mid-1;
            }
        }
        if (floor == -1) return ceil;
        if (ceil == -1) return floor;
        int d1 = k - floor;
        int d2 = ceil - k;
        return d1 < d2 ? floor : ceil;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends