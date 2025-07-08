class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        int largest = arr[0];
        vector<int> ans(n, -1);
    
        for(int i=1; i<n; i++){
            if(arr[i] > largest)
                largest = arr[i];
        }
    
        vector<int> countArr(largest+1, 0);
    
        for(int i=0; i<n; i++){
            countArr[arr[i]]++;        
        }
    
        for(int i=0; i<n; i++){
            // ans[i] = countArr[arr[i+1]] > countArr[arr[i]] ? arr[i+1] : -1;
            for(int j=i+1; j<n; j++){
                if(countArr[arr[j]] > countArr[arr[i]]){
                    ans[i] = arr[j];
                    break;
                }
            }
        }
    return ans;
    }
};
