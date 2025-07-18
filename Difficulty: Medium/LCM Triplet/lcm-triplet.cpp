class Solution {
  public:
    int lcmTriplets(int n) {
        // code here
         if(n<3)return n;
        if(n%2==1) // for odd nums there would be no common divisor < 3 so we can  return multiple of 3 highest numbers
        return n*(n-1)*(n-2); 
        else if(n%3!=0) // if n is even and not multiple of 3
        return (n)*(n-1)*(n-3);
        else // if 3 divides n and n is even  then 3 would be common divisor of n and n-3 so skip n and take n-2 
        return (n-1)*(n-2)*(n-3);
        
    }
};