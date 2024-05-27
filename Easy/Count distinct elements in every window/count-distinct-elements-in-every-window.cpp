//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
         //optimised approach Time complexity is O(N) and space complexity is O(K)
        vector<int> ans;
        unordered_map<int,int> elements;
        
        //initial population of the frequency map with the first window
        for(int i=0; i<k; i++){
            elements[A[i]]++;
        }
        
        ans.push_back(elements.size()); //3 based on this case
        
        //sliding window approach
        for(int i=k; i<n; i++){
            //remove the element going out of the window
            if(elements[A[i-k]]==1) {
                 // If the frequency is 1, remove the element from the map
                 elements.erase(A[i-k]);
            }
            else{
                 // If the frequency is more than 1, decrement the count
                 elements[A[i-k]]--;
            }
            
              // Add the new element coming into the window
            elements[A[i]]++;
            
            //store the number of distinct elements in the current window
            ans.push_back(elements.size());
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends