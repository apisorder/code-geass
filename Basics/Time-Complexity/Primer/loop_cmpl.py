
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  09:26AM 02-29-2024
 *  Problem:                        TC-Primer-1 (Zero)
 * @param {None}
 * @return {None}
'''

question = """
            What is the time, space complexity of following code :

            int a = 0;
            int b = 0;    
            for (i = 0; i < N; i++) 
            {
                a = a + rand();  
            }
            for (j = 0; j < M; j++) 
            {
                b = b + rand();
            }

            Assume that rand() is O(1) time, O(1) space function.
"""

choices = """
            1 TC = O(N x M); SC = O(1)
            2 TC = O(N + M); SC = O(N + M)
            3 TC = O(N + M); SC = O(1)
            4 TC = O(N X M); SC = O(N + M)
            5 TC = O(N X M); SC = O(N X M)
"""

hint = """
            Notice that the 2 loops are independent and not nested. 
            So, we can look at them separately and then add the result.
            Assume that you do not know the relation between N and M. 
            So, try to suggest your answer as a function of N and M ( max or addition maybe ).

            Remember that space complexity is measured in terms of the largest amount of memory 
            used during runtime.
"""

answer = -1
correct_answer = 3

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
            The first loop is O(N) and the second loop is O(M). 
            Since you don't know which is bigger, you say **this is O(N + M)**. 
            This can also be written as O(max(N, M)).

            Since there is no additional space being utilised, 
            the space complexity is constant / O(1)
"""

print(explanation)