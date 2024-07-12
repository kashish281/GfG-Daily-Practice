//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int mod=1e9+7;
         vector<int> cur(sum+1,0),prev(sum+1,0);
        
        prev[0]=cur[0]=1;
        if(arr[0]<=sum) prev[arr[0]]=cur[arr[0]]=1;
       if(arr[0]==0) prev[0]=cur[0]=2;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                
                int nottake=prev[j];
                int take=0;
                if(arr[i]<=j) take=prev[j-arr[i]];
                
                cur[j]=(take+nottake)%(mod);
            }
            prev=cur;
        }
        return prev[sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends