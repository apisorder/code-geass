
'''
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  09:40AM 02-29-2024
 *  Problem:                        TC-Primer-4 (Zero)
 * @param {None}
 * @return {None}
'''

question = """
            What does it mean when we say that an algorithm X is 
            asymptotically more efficient than Y?
"""

choices = """
            1 X will always be a better choice for all inputs
            2 X will always be a better choice for large inputs
            3 X will always be a better choice for small inputs
            4 Y will always be a better choice for small inputs 
"""

hint = """
            In asymptotic analysis we consider growth of algorithm 
            in terms of input size. An algorithm X is said to be 
            asymptotically better than Y if X takes smaller time than y 
            for all input sizes n larger than a value n0 where n0 > 0.
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
            In asymptotic analysis we consider growth of algorithm 
            in terms of input size. An algorithm X is said to be 
            asymptotically better than Y if X takes smaller time than y 
            for all input sizes n larger than a value n0 where n0 > 0.
"""

print(explanation)