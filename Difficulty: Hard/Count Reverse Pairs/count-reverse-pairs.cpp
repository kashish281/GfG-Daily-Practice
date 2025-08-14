class Solution {
  public:
      vector<int>subvec(vector<int>&arr,int lo,int hi){
        vector<int>ans;
        for(int i=lo;i<=hi;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
    int merge(vector<int>&arr,int lo,int mid,int hi){
        int ans = 0;
        vector<int>a = subvec(arr,lo,mid);
        vector<int>b = subvec(arr,mid+1,hi);
        for(int j=0;j<b.size();j++){
            //find upperbound of 2 * b[j] in a
            int idx = upper_bound(a.begin(),a.end(),2*b[j])-a.begin();
            if(idx >= a.size())continue;
            ans += a.size()-idx;
        }
        vector<int>finalArr;
        int i=lo,j=mid+1;
        while(i <= mid and j <= hi){
            if(arr[i] <= arr[j]){
                finalArr.push_back(arr[i]);
                i++;
            }
            else{
                finalArr.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid){
                finalArr.push_back(arr[i]);
                i++;
        }
        while(j <= hi){
                finalArr.push_back(arr[j]);
                j++;
        }
        for(int i=0;i<finalArr.size();i++){
            arr[lo+i] = finalArr[i];
        }
        return ans;
    }
    void solve(vector<int>&arr,int lo,int hi,int &ans){
        if(lo>=hi){
            return;
        }
        int n = arr.size();
        int mid = lo + (hi-lo)/2;
        solve(arr,lo,mid,ans);
        solve(arr,mid+1,hi,ans);
        ans += merge(arr,lo,mid,hi);
    }
    int countRevPairs(vector<int> &arr) {
        int lo = 0 , hi = arr.size()-1;
        int ans = 0;
        solve(arr,lo,hi,ans);
        return ans;
        
    }
};