
#   example:
#   0   1   2   3
#   [2] [1] [5] [3]
#   target = 4

#   most intuitive way
#   check every combination of two values and see if they can sum up to the target
#   notice that we don't have to check numbers which come after it
#   O( N ** 2)

#   can we do better?
#   the value we are looking is the number = target - current number
#   the easiest, most efficient way to use a hash map

#   hashmap 
#   we could add every value in the way into the hash map before we iterate through it
#   0   1   2   3
#   [2] [1] [5] [3]
#
#   but there is an easier way
#
#   hashmap
#   val: index
#
#   0   1   2   3
#   [2] [3] [0] [1]

