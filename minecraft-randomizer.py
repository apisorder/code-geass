
import random

die_minimum = 1
die_maximum = 7
y_coordinate_minimum = -64
y_coordinate_maximum = 321

while True:
    print("                     Simple program to randomize")
    print("                     1 to choose a random y-coordinate (-64 to 320)")
    print("                     2 to choose a random number on a die (1 to 6)")
    print("                     3 to quit the program")

    user_choice = int(input("                                          Enter your choice (1-3) : "))

    if user_choice == 1:
        print("                     Y = " + str(random.randrange(y_coordinate_minimum, y_coordinate_maximum)))
    elif user_choice == 2:
        print("                     die number = " + str(random.randrange(die_minimum, die_maximum)))
    elif user_choice == 3:
        break