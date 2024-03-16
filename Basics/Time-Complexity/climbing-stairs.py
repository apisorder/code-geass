
# bottom up programming approach

dp = [0] * n

demo = '''

        o
        - | -
        /   \
                sub     sub     sub             sub       sub
                problem problem problem         problem   problem
        0       1       2       3       ...     n-1       n             n+1

    DP                                              1       1 (always)      0 (we overshot)
'''
