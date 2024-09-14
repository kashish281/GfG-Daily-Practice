//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    int stockBuyAndSell(int n, vector<int> &price) {
        int i = 0, buy = 0, sell = 0, profit = 0;
        while (i < n - 1) {
            // Find next local minima
            while (i < n - 1 && price[i + 1] <= price[i])
                i++;
            buy = i++;
            // Find next local maxima
            while (i < n && price[i] >= price[i - 1])
                i++;
            sell = i - 1;
            // Add profit
            profit += price[sell] - price[buy];
        }
        return profit;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends