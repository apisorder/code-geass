
class Solution
{
    public static boolean isPalindrome(String input)
    {
        //  define the base case / stopping condition
        if ((input.length() == 0)||(input.length() == 1))
        {
            return true;
        }

        //  do seome work to shirnk the problem space
        if (input.charAt(0) == input.charAt(input.length()-1))
        {
            //  the end index is excluded, i.e. substring is between [beginIndex : endIndex-1]
            return isPalindrome(input.substring(1, input.length()-1));
        }
        return false;
    }
}

class SolutionTestDrive
{
    public static void main(String[] args)
    {
        Solution solution = new Solution();

        String string1 = "racecar";
        String string2 = "racer";

        System.out.println(string1 + " is a palindrome : " + Boolean.toString(solution.isPalindrome(string1)));
        System.out.println(string2 + " is a palindrome : " + Boolean.toString(solution.isPalindrome(string2)));

    }
}