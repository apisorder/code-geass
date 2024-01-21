
import math

name = input("what is your name : ")
print("Hello", name)

num_1, num_2 = input("Enter 2 numbers : ").split()
#   all input are of string type
num_1 = int(num_1)
num_2 = int(num_2)

sum_1 = num_1 + num_2
difference = num_1 - num_2
product = num_1 * num_2
quotient = num_1 / num_2
remainder = num_1 % num_2

print(f'{num_1} + {num_2} = {sum_1}')
print(f'{num_1} - {num_2} = {difference}')
print(f'{num_1} * {num_2} = {product}')
print(f'{num_1} / {num_2} = {quotient}')
print(f'{num_1} % {num_2} = {remainder}')

#   ask the user to input the number of miles
num_of_miles = int(input("enter the number of miles to convert to kilometers : "))

#   convert miles to kilometers (kilometers = miles * 1.60934)
num_of_kilometers = num_of_miles * 1.60934
#   print, for example, 5 miles equals 8.0467 kilometers
print(f'You entered {num_of_miles} miles, which is {num_of_kilometers} kilometers')

print(f"ceil(4.4) = {math.ceil(4.4)}")
print(f"floor(4.4) = {math.floor(4.4)}")
print(f"abs(-4.4) = {math.fabs(-4.4)}")
print(f"factorial(4) = {math.factorial(4)}")
#   return the remindre of division
print(f"fmod(5, 4) = {math.fmod(5, 4)}")

#   receive a float and return an int
print(f"trunc(4.2) = {math.trunc(4.2)}")

#   return x^y
print(f"pow(2, 2) = {math.pow(2, 2)}")

#   return the square root
print(f"sqrt(4) = {math.sqrt(4)}")

#   special values
print(f"math.e = {math.e}")
print(f"math.pi = {math.pi}")

#   return the natural logarithm e * e * e ~= 20
#   so log(20) tells you that e^3 ~= 20
print(f'log(20) = {math.log(20)}')

#   you can define the base and 10^3 = 1000
print(f'log(1000, 10) = {math.log(1000, 10)}')

#   you can also use base 10 like this
print(f'log10(1000) = {math.log10(1000)}')

# We have the following trig functions
# sin, cos, tan, asin, acos, atan, atan2, asinh, acosh,
# atanh, sinh, cosh, tanh
print(f'sin(0) = {math.sin(0)}')
print(f'cos(0) = {math.cos(0)}')
print(f'tan(0) = {math.tan(0)}')
print(f'asin(0) = {math.asin(0)}')
print(f'acos(0) = {math.acos(0)}')
print(f'atan(0) = {math.atan(0)}')
print(f'atan2(0, 30) = {math.atan2(0, 30)}')
print(f'asinh(0) = {math.asinh(0)}')
print(f'acosh(0) = {math.acosh(30)}')
print(f'atanh(0) = {math.atanh(0)}')
print(f'sinh(0) = {math.sinh(0)}')
print(f'cosh(0) = {math.cosh(0)}')
print(f'tanh(0) = {math.tanh(0)}')

#   convert radians to degrees and vice versa
print(f"degrees(1.5708) = {math.degrees(1.5708)}")
print(f"radians(90) = {math.radians(90)}")

