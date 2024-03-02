
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  09:26AM 02-29-2024
 *  Problem:                        TC-Primer-1 (Zero)
 * @param {None}
 * @return {None}
'''

question = """
            V is sorted 
            V.size() = N
            The function is initially called as searchNumOccurrence(V, k, 0, N-1)
        
            int searchNumOccurrence(vector<int> &V, int k, int start, int end) 
            {
                if (start > end)
                {
                    return 0;
                }
                int mid = (start + end) / 2;
                if (V[mid] < k) 
                {
                    return searchNumOccurrence(V, k, mid + 1, end);
                }                                                    
                if (V[mid] > k)
                {
                    return searchNumOccurrence(V, k, start, mid - 1);
                }
                return searchNumOccurrence(V, k, start, mid - 1) 
                    + 1 + searchNumOccurrence(V, k, mid + 1, end);
            }    
"""

choices = """
            1 TC = O(sqrt (N))
            2 TC = O(log (N))
            3 TC = O( log**2 (N))
            4 TC = O(N)
            5 TC
"""

hint = """
            What if all the values in the array are the same ?
            How long does the program run then ?
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
            It might seem at the first look that the program is O(log N). 
However, the last case 

return searchNumOccurrence(V, k, start, mid - 1) + 1 + searchNumOccurrence(V, k, mid + 1, end);


is the bottleneck step. 
Assuming all the values in the array are the same, we get the following relation : 

T(N) = 2 * T(N/2) + constant

     = 4 * T(N/4) + constant     ( 2 * constant = another constant ) 

     = 8 * T(N/8) + constant 

     …

     = N * T(N/N) + constant 

     = N + constant 

     = O(N)
"""

print(explanation)