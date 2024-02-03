
/*
 *  Programmer:                     Jeff C. Cheng
 *  Last modified:                  09:08PM 02-01-2024
 *  Problem:                        2. Add Two Numbers (Medium)
 *  Reference:                      https://leetcode.com/problems/add-two-numbers/description/
 *  NOTE:
 *                                  KNOW HOW LISTNODE IS 
 *                                  NO DEFAULT VALUE NEEDED (0 OR null)
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
*/

//********************************************************************************************************************
//  Step 1: define node
//********************************************************************************************************************

class ListNode
{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class Solution
{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {

//********************************************************************************************************************
//  Step 2: create dummy head and current for the new list
//********************************************************************************************************************

        // creating an dummy list
        ListNode dummyHead = new ListNode( 0 );
        // intialising an pointer
        ListNode current = dummyHead;

        int carry = 0;
        int sum = 0;

        // while loop will run, until l1 OR l2 not reaches null 
        // OR if they both reaches null. But our carry has some value in it. 
		// We will add that as well into our list

//  l1      ->  node 1                  ->  node 2                          ->  node 3                          -> ...
//  l2      ->  node 1                  ->  node 2                          ->  node 3                          -> ...
//  current ->  (carry(0) + node 1 x 2) ->  (carry(node1 x 2) + ndoe 2 x 2) ->  (carry(node2 x 2) + node 2 x 3) -> ...   
//  sum = carry
//********************************************************************************************************************
//  Step 3: while either list remains or carry is 1
//********************************************************************************************************************

        while (carry == 1 || l1 != null || l2 != null )
        {

//********************************************************************************************************************
//  Step 4: carry is first added to the sum
//********************************************************************************************************************

            sum = carry;

            // adding l1 to our sum & moving l1

//********************************************************************************************************************
//  Step 5: add node value to the sum, if list 1 exists; advance the list
//********************************************************************************************************************

            if ( l1 != null )
            {
                sum += l1.val;
                l1 = l1.next;
            }

            // adding l2 to our sum & moving l2

//********************************************************************************************************************
//  Step 6: add node value to the sum, if list 2 exists; advance the list
//********************************************************************************************************************

            if ( l2 != null )
            {
                sum += l2.val;
                l2 = l2.next;
            }

//********************************************************************************************************************
//  Step 7: calculate node value and carry
//********************************************************************************************************************

            if (sum >= 10)
            {
                sum %= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            // current will point to that new node if we get

//********************************************************************************************************************
//  Step 8: add the new node to the new list; advance the list
//********************************************************************************************************************

            current.next = new ListNode(sum);
            // update the current every time
            current = current.next;
        }

//********************************************************************************************************************
//  Step 9: return the result
//********************************************************************************************************************

        return dummyHead.next;
    }
}

class SolutionTestDrive
{
    public static void main(String[] args)
    {
        // Test Case:
        // Input: l1 = [2,4,3], l2 = [5,6,4]
        // Output: [7,0,8]
        // Explanation: 342 + 465 = 807.
        Solution solution = new Solution();       

        ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
        ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    
        ListNode result = solution.addTwoNumbers(l1, l2);
    
        int num = 0;
        int multiplier = 1;

        while (result != null)
        {
//  multiplier is used to place the sum of the two nodes at the correct significant place
            num += result.val * multiplier;
            result = result.next;
            multiplier *= 10;
        }
        System.out.println(num);
    }
}