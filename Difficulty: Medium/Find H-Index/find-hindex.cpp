class Solution {
  public:
    int hIndex(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        int num=INT_MIN;
        int j=*max_element(arr.begin(), arr.end());
        
        int i=0;
        
        while(i<=j){
            int mid = (i+j)/2;
            int cnt=0;
            for(int k=0; k<n; k++){
                if(mid<=arr[k]) cnt++;
            }
            if(cnt>=mid){ 
                num=max(mid, num);
                i=mid+1;
            }
            else j=mid-1;
            
        }
        
        return num;
    }
};