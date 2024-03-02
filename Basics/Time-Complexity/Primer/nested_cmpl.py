
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  09:28AM 02-29-2024
 *  Problem:                        TC-Primer-2 (Zero)
 * @param {None}
 * @return {None}
'''

question = """
            What is the time, space complexity of following code :

            int a = 0, b = 0; 
            for (i = 0; i < N; i++) 
            { 
                for (j = 0; j < N; j++) 
                { 
                    a = a + j; 
                } 
            } 
            for (k = 0; k < N; k++) 
            { 
                b = b + k; 
            }
"""

choices = """
            1 TC = O(N x N); SC = O(1)
            2 TC = O(N); SC = O(N)
            3 TC = O(N X N X N); SC = O(1)
            4 TC = O(N X N); SC = O(N)
"""

hint = """
            Notice how the nested loop behaves. The j loop iterates for N times and 
            the j loop itself is run N times.

            So, the total number of runs would be N + N + …. N times
"""

answer = -1
correct_answer = 1

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
            The first set of nested loops is O(N^2) and the second loop is O(N). 

            This is O(max(N^2,N)) which is O(N^2). 
"""

print(explanation)