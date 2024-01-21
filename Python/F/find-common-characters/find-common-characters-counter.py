
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  8:02PM 1-6-2024
 *  Problem:                        1002. Find Common Characters (Easy)
 *  Reference:                      https://leetcode.com/problems/find-common-characters/description/   
                                    https://leetcode.com/problems/find-common-characters/solutions/247560/python-1-line/
'''

# 1002. Find Common Characters
# Easy
# 3.3K
# 267
# Companies
# Given a string array words, return an array 
# of all characters that show up in all strings 
# within the words (including duplicates). 
# You may return the answer in any order.

 

# Example 1:

# Input: words = ["bella","label","roller"]
# Output: ["e","l","l"]
# Example 2:

# Input: words = ["cool","lock","cook"]
# Output: ["c","o"]
 

# Constraints:

# 1 <= words.length <= 100
# 1 <= words[i].length <= 100
# words[i] consists of lowercase English letters.
# Accepted
# 193.5K
# Submissions
# 281.9K
# Acceptance Rate
# 68.6%

#   include Counter
from collections import Counter

class Solution:
    def commonChars(self, words):
#   check extreme cases
        if len(words) < 2:
            return words

#   init the first element to be counter
        model = Counter(words[0])

#   iterate through the list
        for word in words[1:]:
#   reduce to the lowest common counts
            model &= Counter(word)        

#   return the result
        return list(model.elements())