class Solution:
    # Function to find the majority elements in the array
    def findMajority(self, nums):
        e1, e2, c1, c2 = -1, -1, 0, 0  # Initialize two potential majority candidates and their counts
        
        # First pass: Identify potential candidates for majority elements
        for i in nums:
            if e2 != i and c1 == 0:  # Assign e1 if its count is 0
                e1 = i
                c1 = 1
            elif e1 != i and c2 == 0:  # Assign e2 if its count is 0
                e2 = i
                c2 = 1
            elif e1 == i:  # Increment count if e1 matches
                c1 += 1
            elif e2 == i:  # Increment count if e2 matches
                c2 += 1
            else:  # Decrement both counts if no match
                c1 -= 1
                c2 -= 1
        
        # Second pass: Validate the candidates
        c1, c2 = 0, 0
        for i in nums:  # Count occurrences of e1 and e2
            if e1 == i:
                c1 += 1
            elif e2 == i:
                c2 += 1
        
        # Add valid candidates to the result
        a = []
        if c1 >= len(nums) // 3 + 1: a.append(e1)
        if c2 >= len(nums) // 3 + 1: a.append(e2)
        
        return a if a else [-1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.findMajority(nums)
        print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()

# } Driver Code Ends