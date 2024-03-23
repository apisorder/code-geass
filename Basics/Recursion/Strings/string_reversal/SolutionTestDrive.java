
class Solution
{
    public String reverseString(String input)
    {
        if (input.equals(""))
        {
            return "";
        }
        //  what is the smallest amount of work I can do in each iteration?
        return reverseString(input.substring(1)) + input.charAt(0);
    }    
}

public class SolutionTestDrive {
    public static void main(String[] args)
    {
        Solution solution = new Solution();
        String string = "Penguinplushmoji";

        System.out.println(string + "reversed = " + solution.reverseString(string));
    }
}
