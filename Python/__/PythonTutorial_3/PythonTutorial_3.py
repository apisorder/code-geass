
#   conditional operator
drink = input("Pick One(Coke or Pepsi) : ")
if drink == "Coke":
    print("Here is your Coke")
elif drink == "Pepsi":
    print("Here is your Pepsi")
else:
    print("Here is your water")

#   calculator
num1, operator, num2 = input("Enter Calculation : (with spaces in between)  ").split()
num1 = int(num1)
num2 = int(num2)

if operator == "+":
    print(f"{num1} + {num2} = {num1 + num2}")
elif operator == "-":
    print(f"{num1} - {num2} = {num1 + num2}")
elif operator == "*":
    print(f"{num1} * {num2} = {num1 * num2}")
elif operator == "/":
    print(f"{num1} / {num2} = {num1 / num2}")
elif operator == "%":
    print(f"{num1} % {num2} = {num1 % num2}")