
class Solution:
    def swap_two_numbers(self, a, b):
        print('inside function call before swap')
        print(f'a = {a}')
        print(f'b = {b}')

        # temp = a
        # a = b
        # b = temp

        a, b = b, a

        print('inside function call after swap')
        print(f'a = {a}')
        print(f'b = {b}')

        return a, b

    def swap0(self, s1, s2):
        assert type(s1) == list and type(s2) == list
        tmp = s1[:]
        s1[:] = s2
        s2[:] = tmp

solution = Solution
a = 7
b = 11
print('values before the function call')
print(f'a = {a}')
print(f'b = {b}')
a, b = solution.swap_two_numbers(solution, a, b)
print('values after the function call')
print(f'a = {a}')
print(f'b = {b}')
# list1 = [3, 5]
# list2 = [5, 3]
# print(f'list1 = {list1}')
# print(f'list2 = {list2}')
# solution.swap0(solution, list1, list2)
# print(f'list1 = {list1}')
# print(f'list2 = {list2}')