
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  10:59PM 1-17-2024
 *  Problem:                        10033. Minimum Number of Operations to Make X and Y Equal
 *  Reference:                      https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/description/
                                    https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/solutions/4518276/bfs-runtime-o-max-x-y-explained-solution/

  NOTE:
                                    WHAT ARE THE BASE CASES 
 '''

# 10033. Minimum Number of Operations to Make X and Y Equal
# Medium
# 102
# 19
# Companies
# You are given two positive integers x and y.

# In one operation, you can do one of the four following operations:

# Divide x by 11 if x is a multiple of 11.
# Divide x by 5 if x is a multiple of 5.
# Decrement x by 1.
# Increment x by 1.
# Return the minimum number of operations required to make x and y equal.

 

# Example 1:

# Input: x = 26, y = 1
# Output: 3
# Explanation: We can make 26 equal to 1 
# by applying the following operations: 
# 1. Decrement x by 1
# 2. Divide x by 5
# 3. Divide x by 5
# It can be shown that 3 is the minimum number of operations required 
# to make 26 equal to 1.

# Example 2:

# Input: x = 54, y = 2
# Output: 4
# Explanation: We can make 54 equal to 2 
# by applying the following operations: 
# 1. Increment x by 1
# 2. Divide x by 11 
# 3. Divide x by 5
# 4. Increment x by 1
# It can be shown that 4 is the minimum number of operations required 
# to make 54 equal to 2.

# Example 3:

# Input: x = 25, y = 30
# Output: 5
# Explanation: We can make 25 equal to 30 
# by applying the following operations: 
# 1. Increment x by 1
# 2. Increment x by 1
# 3. Increment x by 1
# 4. Increment x by 1
# 5. Increment x by 1
# It can be shown that 5 is the minimum number of operations required 
# to make 25 equal to 30.
 

# Constraints:

# 1 <= x, y <= 104

# Apply BFS with x as the starting node. The minimum depth of the graph 
# where y is found is your answer.
#
# The possible neighbours can be:
#
# If x % 5 == 0 then x // 5 (Node 1), if x % 11 == 0 then x // 11 (Node 2), 
# x - 1 (Node 3) (If x - 1 > 0) and x + 1 (Node 4)

# TC: O(V+E)O(V + E)O(V+E) --> O(n)O(n)O(n) where n = abs(x - y)
# SC: O(n)O(n)O(n) (Queue)

# If element found, return the depth
from collections import deque

class Solution:
    def minimumOperationsToMakeEqual(self, x, y):
    
        # 1. BASE CASES:
        # If x is already equal to y, return 0, as no operations are needed.
        # If x is less than y, return the absolute difference y - x 
        # as the minimum number of operations.
        if x == y:
            return 0
        if x < y:
            return y-x
        
        # 2. Initialization:
        # Initialize the number of operations as 0.
        # Create a queue to store intermediate values during the BFS traversal.
        # Create an unordered set (visited) to keep track of visited values 
        # to avoid redundant operations.
        
        # a queue to store the BFS states
        queue = deque()
        queue.append(x)
     
        # an unordered set to store the numbers that have already been processed, 
        # If we just implement BFS, we will get TLE
        visited = set()
   
        #  an int to store the number of the depth 
        #  (or the number of operations performed)
        depth = 0
        
        # 3. BFS Loop:
        # Perform a BFS traversal using a while loop until the queue is empty.
        # In each iteration, process all elements at the current level 
        # in the BFS tree (level-wise traversal).
        while queue:
            size = len(queue)
        
        # 4. Queue Processing Loop:
        # Get the front element current from the queue.
        # If current has already been visited, skip to the next iteration.
        # Mark current as visited.
        # Check if current is equal to y. If true, return the current number of operations.
        # Enqueue values obtained by dividing current by 11 (if divisible), by 5 (if divisible), 
        # and by incrementing or decrementing current by 1.

            for _ in range(size):
                current = queue.popleft()
                
                if current in visited:
                    continue
                visited.add(current)
                
                if current == y:
                    return depth
                    
                if current > 1:
                    queue.append(current-1)
                queue.append(current+1)
                if current % 11 == 0:
                    queue.append(current//11)
                if current % 5 == 0:
                    queue.append(current//5)
                    
        # 5. Increment operations:
        # After processing all elements at the current level, increment the operations counter.
            depth += 1
            
        # 6. Result:
        # If the loop completes and no equality is found, 
        # return -1 as there is no way to make x and y equal.
        return -1
                
                
