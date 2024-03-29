
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  03:22PM 03-13-2024
 *  Problem:                        TC-Primer-1 (Zero)
 * @param {None}
 * @return {None}
'''

question = """
            What is the time complexity of the following code :

                    int j = 0;
                    for(int i = 0; i < n; ++i)
                    {
                        while(j < n && arr[i] < arr[j]) 
                        {
                            j++;
                        }
                    }
"""

choices = """
            1 TC = O( N )
            2 TC = O( N**2 )
            3 TC = O(N x log(N))
            4 TC = O(N x log(N)**2)
            5 TC = Can't say:  depends on the value of arr.
"""

hint = """
            In the first look, the time complexity seems to be O(n^2) due to two loops.
            However, note that the variable j is not initialized for each value of variable i.
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
            
            Note that the variable j is not initialized for each value of variable i.
            Hence, the inner j++ will be executed at most n times.
            The i loop also runs n times.
            So, the whole thing runs for O(n) times.


            **Still not convinced ?**

            Lets assume the array passed has its element in decreasing order. 
            i.e. arr = [14, 13, 12, 11]

            We will just dry run through the code :

            Iteration 1 : i = 0, j = 0. arr[0] < arr[0] is false. So, the inner while loop breaks.

            Iteration 2: i =1, j = 0. arr[1] < arr[0] is true. j becomes 1.

            Iteration 3 : i = 1, j = 1. Condition false. We break. Note that j will remain 1 and is not reset back to 0.

            Iteration 4 : i = 2, j = 1. arr[2] < arr[1]. True. j = 2.

            Iteration 5 : i = 2, j = 2. Condition false. Break.

            Iteration 6 : i = 3, j = 2. arr[3] < arr[2]. True. j = 3.

            Iteration 7 : i = 3, j = 3. Condition false. Break.


            As you can see, the inner while loop only runs once in this case.
            So, total iterations is **2 * N.**
"""

print(explanation)