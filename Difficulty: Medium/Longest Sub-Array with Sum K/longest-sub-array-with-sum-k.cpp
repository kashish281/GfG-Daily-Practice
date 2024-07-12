//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
          map<long long, int> preSum;
        long long sum = 0;
        long long maxLen = 0;
        for(int i = 0; i<N;i++){
            sum = sum + A[i];
            if(sum==K){
                if(maxLen<i+1){
                    maxLen = i +1;
                }
                else{
                    maxLen = maxLen;
                }
            }
            long long rem = sum - K;
            if(preSum.find(rem)!=preSum.end()){
                int len = i - preSum[rem];
                if(maxLen<len){
                    maxLen = len;
                }
                else{
                    maxLen = maxLen;
                }
            }
            if(preSum.find(sum)==preSum.end()){
                preSum[sum] = i;
            }
        }
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends