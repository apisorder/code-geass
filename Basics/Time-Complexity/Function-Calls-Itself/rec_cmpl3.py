
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  04:43PM 03-12-2024
 *  Problem:                        TC-Primer-3 (Zero)
 * @param {None}
 * @return {None}
'''

question = """
            What is the worst case time complexity of the following code:

            int memo[101][101];
            int findMinPath(vector<vector<int> >& V, int r, int c) {
            int R = V.size();
            int C = V[0].size();
            if (r >= R || c >= C) return 100000000; // Infinity
            if (r == R - 1 && c == C - 1) return 0;
            if (memo[r][c] != -1) return memo[r][c];
            memo[r][c] =  V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
            return memo[r][c];
            }

            Callsite : 
            memset(memo, -1, sizeof(memo));
            findMinPath(V, 0, 0);
            Assume R = V.size() and C = V[0].size() and V has positive elements"""
choices = """
            1 TC = O( 2**(R + C) )
            2 TC = O( R x C )
            3 TC = O( R + C )
            4 TC = O( R x R + C x C )
            5 TC = O( R x C x log( R x C ) )
"""

hint = """
            In the worst case, how many function calls will be made from a single function ?
            It seems like every function will make 2 calls. But do note that we have a memo array 
            which keeps getting updated and controls how functions are called.

            Can you say something about the number of times the following code will be executed :

            memo[r][c] =  V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
            Can you take a 3x3 matrix for V, and examine the number of calls ?
"""

answer = -1
correct_answer = 2

while True:
    print(question)
    print(choices)
    answer = int(input("Enter your choice : "))

    if answer != correct_answer:
        print("Are you sure? Try again.")
    else:
        break

explanation = """
            Correct!
            
            Note that for a given `(r, c)`
            
            the following code will not be executed more than once : 

            memo[r][c] =  V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));


            Once memo[r][c] is set, the functions will return at 

            if (memo[r][c] != -1) return memo[r][c];


            So, every function ends up calling other functions at most 1 time. 
            In other words, every function ends up executing at most O(1) times 
            (Note that you can shift the part about checking for memo[r][c] != -1 at the callsite ).

            `O(R * C)` possible number of combinations are possible for `(r, c)`
            Hence, the time complexity of the function : O(R*C)
"""

print(explanation)