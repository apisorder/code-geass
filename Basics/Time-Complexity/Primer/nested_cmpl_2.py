
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  09:36AM 02-29-2024
 *  Problem:                        TC-Primer-3 (Zero)
 * @param {None}
 * @return {None}
'''

question = """
            What is the time complexity of the following code :

            int a = 0;
            for (i = 0; i < N; i++) 
            {
                for (j = N; j > i; j--) 
                {
                    a = a + i + j;
                }
            }
"""

choices = """
            1 TC = O(N)
            2 TC = O(N x log N)
            3 TC = O(N X sqrt(N) )
            4 TC = O(N X N)
"""

hint = """
            Count the number of times the loop runs.

            When i = 0, it runs for N times.

            When i = 1, it runs for N - 1 times …

            When i = k, it runs for N - k times

            So, total number of runs = N + (N - 1) + (N - 2) + … 1 + 0 = ???
"""

answer = -1
correct_answer = 4

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
            Total number of runs = N + (N - 1) + (N - 2) + ... 1 + 0

            = N * (N + 1) / 2

            = 1/2 * N^2 + 1/2 * N

            O(N^2) times. 
"""

print(explanation)