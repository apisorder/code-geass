
#   what is a programming language?
#
#   accept input and store it in many ways
#   output information to the screen, files, etc.
#   conditionally do one thing or another thing
#   do something multiple times
#   math mathematical calculations
#   change data
#   model real world objects

#   ask the user to input their name and assign it to a variable named name

name = input("What is your name ? ")

#   print out hello followed by the name they entered

print('Hello', name)

#   ask the user to input 2 values and store them in variables num1 num2

num1, num2 = input("Enter 2 numbers : ").split()

#   convert the strings into regular numbers
num1 = int(num1)
num2 = int(num2)

#   add the values entered and store in sum
sum1 = num1 + num2

#   subtract values and store in difference
difference = num1 - num2

#   multipliy the values and store in product
product = num1 * num2

#   divide the values and stor in quotient
quotient = num1 / num2

#   use modulus on the values to find the remainder
reminder = num1 % num2

#   print the results
print("{} + {} = {}".format(num1, num2, sum1))
print("{} - {} = {}".format(num1, num2, difference))
print("{} * {} = {}".format(num1, num2, product))
print("{} / {} = {}".format(num1, num2, quotient))
print("{} % {} = {}".format(num1, num2, reminder))

#   problem : receive miles and convert to kilometers
miles = input('Enter the number of miles : ')

#   kilometers = miles * 1.60934
kilometers = int(miles) * 1.60934

print("You entered {} miles = {} kilometers".format(miles, kilometers))
#   enter miles 5

#   5 miles equal 8.04 

#   enter calculation: 5 * 6
#   5 * 6 = 30

#   store the user input of 2 numbers and the operator
op1, operator, op2 = input("Enter a calculation : ").split()

#   convert the strings into integers
op1 = int(op1)
op2 = int(op2)

#   if + then we need to provide output based on addition
#   print the result 

if operator == '+':
    print("{} + {} = {}".format(op1, op2, op1 + op2))
elif operator == "-":
    print("{} - {} = {}".format(op1, op2, op1 - op2))
elif operator == '*':
    print("{} * {} = {}".format(op1, op2, op1 * op2))
elif operator == "/":
    print("{} / {} = {}".format(op1, op2, op1 / op2))
elif operator == '%': 
    print("{} % {} = {}".format(op1, op2, op1 % op2))
else:
    print("Use either + - * / or % next time")

#   we will provide different output based on age
#   1-18 -> Important
#   21, 50, > 65    -> Important
#   All others  -> Not Important
    
#   receive age and store in age
age = eval(input("Enter age : "))

#   and :   if both are true, it rturns true

#   or :    if either condition is true, it returns true

#   not :   convert a true condition into a false

#   if age is both greater than or equal to 1 and less than or equal to 18
if (age >= 1) and (age <= 18):
    print("Important Birthday")

#   if age is either 21 or 50 Important
elif (age == 21) or (age == 50):
    print("Important Birthday")

#   we check if age is less than 65 and then convert true to false and vice versa
elif not (age < 65):
    print("Important Birthday")

#   Not important
else:
    print("Sorry, not important")

#   ask for the age
age = eval(input("Enter your age for schooling : "))

#   if age is 5 go to kindergarten
if age < 5:
    print("Too young for school")
elif age == 5:
    print("Go to Kindergarten")
#   age 6 through 17 to grades 1 through 12
elif (age >= 6) and (age <= 17):
    print("Go to Grade {}".format(age-5))
#   if age is greater than 17 say go to college
else:
    print("Go to College")