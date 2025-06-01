class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
         int n=mat1.size();
        int i=0,j=0,k=n-1,l=n-1;
        int ans=0;
        while(j<n and l>=0){
            // cout<<i<<" "<<j<<endl;
            // cout<<k<<" "<<l<<endl;
            if(mat1[j][i]+mat2[l][k]==x){
                ans++;
                i++;
                k--;
            }else if(mat1[j][i]+mat2[l][k]>x){
                k--;
            }else{
                i++;
            }
            if(i>=n){
                i=0;
                j++;
            }
            if(k<0){
                k=n-1;
                l--;
            }
        }
    return ans;
    }
};