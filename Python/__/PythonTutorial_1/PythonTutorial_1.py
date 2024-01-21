
#   provide pre-written code
import sys

#   start w/ letter or underscore
#   can contain letters, numbers, or underscores
#   no spces
#   use my_age not myAge

my_age = 43
my_name = "apisorder"

print("Hello", my_name)

#   data are stored in boxes
#   different box are different data types

#   Comment

"""
Multiline 
comments

    # Newline:        \n
    # Backslash:      \\
    # Single Quote:   \'
    # Backspace:      \b
    # Tab:            \t
"""

string1 = ""
string2 = ''
sf = "\"hello\""
print(f'sf = {sf}')

str_1 = "\"This is a quote\""

#   max integer
print(sys.maxsize)
#   max float size
print(sys.float_info.max)

f1 = 1.1111111111111111
f2 = 1.1111111111111111
f3 = f1 + f2
print(f'errors can creep in {f3}')

print( "Cast ->type(int(5.4))", type(int(5.4)))
print( "Cast 1 ->type(str(5.4))", type(str(5.4)))
print( "Cast 2 ->type(chr(97)) UniCode character ->string", type(chr(97)))
print( "Cast 3 ->type(ord('a')) character ->UniCode", type(ord('a')))
print( "Cast 4 ->type(float(2))", type(float(2)))

# This is a complex number
Cn1 = 5 + 6j

num_1 = "1"
num_2 = "2"

print("1+ 2 =", (int(num_1) + int(num_2)))

num_1 = "7"
num_2 = "11"
print(num_1 + " + " + num_2 + " = " +  str(int(num_1) + int(num_2)))