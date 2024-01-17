
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

# But what about replacing Counter with custom code? That would avoid the overhead 
# of a Counter object, and tracking that isn't needed for this problem. 
# I could count the number of letters / characters in each word, and then 
# only keep counts that they had in common. I'll have some extra work to do 
# at the end: I'll need to output the characters times the count. 
# Since I'll be performing frequency counts in two different places, 
# I split that code into it's own method, giving me:

class Solution:
    def commonChars(self, words):
#   create own counter
#   create the dictionary
#   iterate through the parameter & update the dictionary as necessary
#   result the iterated result
        def counter(self, w):
            frequencies = {}

            for c in w:
                frequencies[c] = frequencies.get(c, 0) + 1
            return frequencies
        
#   handle extreme cases
        if len(words) < 2:
            return words
        
#   init the first element as a counter
        model = counter(self, words[0])

#   iterate through the remaining elements
        for word in words[1:]:
#   creating each as a new counter
            new_model = counter(self, word)
#   for each subsequence elements, run them against the first counter
#   and reduce to the lowest common count
            for c, count in list(model.items()):
                try:
                    model[c] = min(count, new_model[c])
                except KeyError:
#   update (delete) key as needed
                    del model[c]

#   create result list
        commonToAll = []
#   extend element * respective count int the list
        for c, count in model.items():
            commonToAll.extend( [c] * count)

#   return the result
        return commonToAll