//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<tuple<int, int, int>> tips;

for (int i = 0; i < n; ++i) {

tips.push_back(make_tuple(abs(arr[i] - brr[i]), arr[i], brr[i]));

}


sort(tips.begin(), tips.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {

return get<0>(a) > get<0>(b);

}

);


long long totalTips = 0;

int aCount = 0,

bCount = 0;


for (int i = 0; i < n; ++i) {

int tipA = get<1>(tips[i]);

int tipB = get<2>(tips[i]);

if ((tipA >= tipB && aCount < x) || bCount >= y)

{

totalTips += tipA; ++aCount;

}

else {

totalTips += tipB; ++bCount;

}

}

return totalTips;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends